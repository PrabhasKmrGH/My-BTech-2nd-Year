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
        // rebase+shrink; OK if it fails—we just keep current capacity
        (void)queueRebaseResize(q, (q->len == 0) ? 1 : newCap);
    }

    if (q->len == 0) {
        // normalize indices so we don't accumulate huge F/R
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
        printf("Test 1 - Enq 10: %s\n", "PASSED");
    } else {
        printf("Test 1 - Enq 10: %s\n", "FAILED");
    }

    // Test 2: Enqueue another element
    result = enqueue(&q, 20);
    ok = queueFront(&q, &front) && queueBack(&q, &back);
    if (result && ok && queueLen(&q) == 2 && front == 10 && back == 20) {
        printf("Test 2 - Enq 20: %s\n", "PASSED");
    } else {
        printf("Test 2 - Enq 20: %s\n", "FAILED");
    }

    // Test 3: Dequeue the first element
    int val = dequeue(&q);
    ok = queueFront(&q, &front);
    if (val == 10 && queueLen(&q) == 1 && ok && front == 20) {
        printf("Test 3 - Deq: %s\n", "PASSED");
    } else {
        printf("Test 3 - Deq: %s\n", "FAILED");
    }

    // Test 4: Dequeue again
    val = dequeue(&q);
    if (val == 20 && queueLen(&q) == 0) {
        printf("Test 4 - Deq: %s\n", "PASSED");
    } else {
        printf("Test 4 - Deq: %s\n", "FAILED");
    }

    // Test 5: Dequeue from empty queue
    val = dequeue(&q);
    if (val == 0 && queueLen(&q) == 0) {
        printf("Test 5 - Deq empty: %s\n", "PASSED");
    } else {
        printf("Test 5 - Deq empty: %s\n", "FAILED");
    }

    // Test 6: growth + wrap-around behavior
    // Fill and rotate to force wrap
    bool all = true;
    for (int i = 1; i <= 5; ++i) all &= enqueue(&q, i * 100);   // 100..500
    for (int i = 0; i < 3; ++i) all &= dequeue(&q) == (i+1)*100;    // pop 100,200,300
    for (int i = 6; i <= 9; ++i) all &= enqueue(&q, i * 100); // 600..900 (wrap likely)

    // Now expected order: 400,500,600,700,800,900
    const int expected[] = {400,500,600,700,800,900};
    bool orderOK = true;
    for (size_t i = 0; i < sizeof(expected)/sizeof(expected[0]); ++i) {
        const int got = dequeue(&q);
        if (got != expected[i]) { orderOK = false; break; }
    }
    if (all && orderOK && queueLen(&q) == 0) {
        printf("Test 6 - Wrap & order: %s\n", "PASSED");
    } else {
        printf("Test 6 - Wrap & order: %s\n", "FAILED");
    }

    // Test 7: Shrink check (not strictly asserted)
    for (int i = 0; i < 64; ++i) enqueue(&q, i);
    const size_t capBefore = q.cap;
    for (int i = 0; i < 60; ++i) (void)dequeue(&q);
    const size_t capAfter = q.cap;
    if (capAfter <= capBefore / 2) {
        printf("Test 7 - Shrink (cap %zu -> %zu): %s\n", capBefore, capAfter, "PASSED");
    } else {
        printf("Test 7 - Shrink (cap %zu -> %zu): %s\n", capBefore, capAfter, "OK");
    }

    queueFree(&q);
    return 0;
}