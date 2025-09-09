#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int    *data;      // allocated array
    size_t  len;     // number of elements currently in the queue
    size_t  cap;   // size of allocated array representing queue
    size_t  F;   // index of front element (valid when len>0)
    size_t  R; // index one past the last element (insertion point)
} Queue;

static bool queueRebaseResize(Queue *q, const size_t newCap) {
    int *newData = (int*)malloc((newCap ? newCap : 1) * sizeof(int));
    if (!newData) return false;

    for (size_t i = 0; i < q->len; ++i) {
        newData[i] = q->data[(q->F + i) % q->cap];
    }

    free(q->data);
    q->data = newData;
    q->cap  = newCap ? newCap : 1;
    q->F    = 0;
    q->R    = q->len % q->cap; // if len==0, R becomes 0
    return true;
}

bool queueInit(Queue *q, const size_t initialCap) {
    q->data = NULL;
    q->len  = 0;
    q->cap  = 0;
    q->F    = 0;
    q->R    = 0;

    if (initialCap == 0) return true;
    q->data = (int*)malloc(initialCap * sizeof(int));
    if (!q->data) return false;
    q->cap = initialCap;
    return true;
}

void queueFree(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->len  = 0;
    q->cap  = 0;
    q->F    = 0;
    q->R    = 0;
}

size_t queueLen(const Queue *q) { return q->len; }

bool queueFront(const Queue *q, int *out) {
    if (q->len == 0) return false;
    *out = q->data[q->F];
    return true;
}

bool queueBack(const Queue *q, int *out) {
    if (q->len == 0) return false;
    const size_t idx = q->R == 0 ? q->cap - 1 : q->R - 1;
    *out = q->data[idx];
    return true;
}

bool enqueue(Queue *q, const int value) {
    if (q->cap == 0) {
        q->data = (int*)malloc(sizeof(int));
        if (!q->data) return false;
        q->cap = 1;
        q->F = q->R = 0;
    }
    if (q->len == q->cap) {
        const size_t newCap = q->cap * 2;
        if (newCap < q->cap) return false; // overflow
        if (!queueRebaseResize(q, newCap)) return false;
    }
    q->data[q->R] = value;
    q->R = (q->R + 1) % q->cap;
    q->len++;
    return true;
}

bool enqueueFront(Queue *q, const int value) {
    if (q->cap == 0) {
        q->data = (int*)malloc(sizeof(int));
        if (!q->data) return false;
        q->cap = 1;
        q->F = q->R = 0;
    }
    if (q->len == q->cap) {
        const size_t newCap = q->cap * 2;
        if (newCap < q->cap) return false;
        if (!queueRebaseResize(q, newCap)) return false;
    }
    q->F = q->F == 0 ? q->cap - 1 : q->F - 1;
    q->data[q->F] = value;
    q->len++;
    return true;
}

int dequeue(Queue *q) {
    if (q->len == 0) {
        fprintf(stderr, "dequeue: queue is empty\n");
        return 0; // sentinel
    }
    const int v = q->data[q->F];
    q->F = (q->F + 1) % q->cap;
    q->len--;

    // Shrink: halve when ≤25% full; keep minimum cap 1 when non-empty
    if (q->cap >= 4 && q->len * 4 <= q->cap) {
        const size_t newCap = q->cap / 2;
        (void)queueRebaseResize(q, q->len == 0 ? 1 : newCap);
    }

    if (q->len == 0) {
        q->F = q->R = 0;
    }
    return v;
}

int main(void) {
    Queue q;
    if (!queueInit(&q, 0)) {
        fprintf(stderr, "queue init failed\n");
        return 1;
    }

    // Test 1: Enqueue an element
    bool result = enqueue(&q, 10);
    int front = 0, back = 0;
    bool ok = queueFront(&q, &front) && queueBack(&q, &back);
    if (result && ok && queueLen(&q) == 1 && front == 10 && back == 10) {
        printf("Test 1 - Enq 10: PASSED\n");
    } else {
        printf("Test 1 - Enq 10: FAILED\n");
    }

    // Test 2: Enqueue another element
    result = enqueue(&q, 20);
    ok = queueFront(&q, &front) && queueBack(&q, &back);
    if (result && ok && queueLen(&q) == 2 && front == 10 && back == 20) {
        printf("Test 2 - Enq 20: PASSED\n");
    } else {
        printf("Test 2 - Enq 20: FAILED\n");
    }

    // Test 3: Dequeue the first element
    int val = dequeue(&q);
    ok = queueFront(&q, &front);
    if (val == 10 && queueLen(&q) == 1 && ok && front == 20) {
        printf("Test 3 - Deq: PASSED\n");
    } else {
        printf("Test 3 - Deq: FAILED\n");
    }

    // Test 4: Dequeue again
    val = dequeue(&q);
    if (val == 20 && queueLen(&q) == 0) {
        printf("Test 4 - Deq: PASSED\n");
    } else {
        printf("Test 4 - Deq: FAILED\n");
    }

    // Test 5: Dequeue from empty queue
    val = dequeue(&q);
    if (val == 0 && queueLen(&q) == 0) {
        printf("Test 5 - Deq empty: PASSED\n");
    } else {
        printf("Test 5 - Deq empty: FAILED\n");
    }

    // Test 6: growth + wrap-around behavior
    bool all = true;
    for (int i = 1; i <= 5; ++i) all &= enqueue(&q, i * 100);   // 100..500
    for (int i = 0; i < 3; ++i) all &= dequeue(&q) == (i+1)*100;    // pop 100,200,300
    for (int i = 6; i <= 9; ++i) all &= enqueue(&q, i * 100); // 600..900 (wrap likely)

    const int expected[] = {400,500,600,700,800,900};
    bool orderOK = true;
    for (size_t i = 0; i < sizeof(expected)/sizeof(expected[0]); ++i) {
        const int got = dequeue(&q);
        if (got != expected[i]) { orderOK = false; break; }
    }
    if (all && orderOK && queueLen(&q) == 0) {
        printf("Test 6 - Wrap & order: PASSED\n");
    } else {
        printf("Test 6 - Wrap & order: FAILED\n");
    }

    // Test 7: Shrink check (not strictly asserted)
    for (int i = 0; i < 64; ++i) enqueue(&q, i);
    const size_t capBefore = q.cap;
    for (int i = 0; i < 60; ++i) (void)dequeue(&q);
    const size_t capAfter = q.cap;
    if (capAfter <= capBefore / 2) {
        printf("Test 7 - Shrink (cap %zu -> %zu): PASSED\n", capBefore, capAfter);
    } else {
        printf("Test 7 - Shrink (cap %zu -> %zu): OK\n", capBefore, capAfter);
    }

    // Test 8: enqueueFront order
    queueFree(&q);
    queueInit(&q, 0);

    enqueue(&q, 20);         // queue: 20
    enqueueFront(&q, 10);   // queue: 10,20
    enqueue(&q, 30);       // queue: 10,20,30
    enqueueFront(&q, 5);  // queue: 5,10,20,30

    const int expected2[] = {5,10,20,30};
    orderOK = true;
    for (size_t i = 0; i < sizeof(expected2)/sizeof(expected2[0]); ++i) {
        int got = dequeue(&q);
        if (got != expected2[i]) { orderOK = false; break; }
    }
    if (orderOK && queueLen(&q) == 0) {
        printf("Test 8 - EnqFront order: PASSED\n");
    } else {
        printf("Test 8 - EnqFront order: FAILED\n");
    }

    queueFree(&q);
    return 0;
}