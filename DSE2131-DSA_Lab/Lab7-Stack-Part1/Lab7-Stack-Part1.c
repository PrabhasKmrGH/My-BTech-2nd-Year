#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;    // allocated array of cap elements
    size_t len;  // number of elements currently in the stack
    size_t cap; // allocated capacity (in elements)
} Stack;

bool stackInit(Stack *stack, size_t initialCap) {
    stack->data = NULL;
    stack->len  = 0;
    stack->cap  = 0;
    if (initialCap == 0) return true; // defer allocation until first push
    stack->data = (int*)malloc(initialCap * sizeof(int));
    if (!stack->data) return false;
    stack->cap = initialCap;
    return true;
}

void stackFree(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->len  = 0;
    s->cap  = 0;
}

bool stackPush(Stack *s, const int value) {
    if (s->len == s->cap) {
        // Grows: 0->1, then x2
        size_t newCap = (s->cap == 0) ? 1 : s->cap * 2;
        if (newCap < s->cap) return false;
        int *p = (int*)realloc(s->data, newCap * sizeof(int));
        if (!p) return false;
        s->data = p;
        s->cap  = newCap;
    }
    s->data[s->len++] = value;
    return true;
}

int stackPop(Stack *s) {
    if (s->len == 0) {
        fprintf(stderr, "stackPop: stack is empty\n");
        return 0; // Sentinel value for empty stack
    }
    const int val = s->data[s->len - 1];
    s->len--;
    // Shrink: if there is a lot of slack, halve capacity
    if (s->cap >= 4 && s->len * 4 <= s->cap) {
        size_t newCap = s->cap / 2;
        int *p = (int*)realloc(s->data, (newCap ? newCap : 1) * sizeof(int));
        if (p) { s->data = p; s->cap = (newCap ? newCap : 1); }
    }
    return val;
}

int main(void) {
    Stack s;
    if (!stackInit(&s, 0)) {
        fprintf(stderr, "stack init failed\n");
        return 1;
    }

    int val;

    // Test 1: Push an element
    bool result = stackPush(&s, 10);
    printf("Test 1 - Push 10: %s\n", (result && s.len == 1 && s.data[0] == 10) ? "PASSED" : "FAILED");

    // Test 2: Push another element
    result = stackPush(&s, 20);
    printf("Test 2 - Push 20: %s\n", (result && s.len == 2 && s.data[1] == 20) ? "PASSED" : "FAILED");

    // Test 3: Pop the last element
    val = stackPop(&s);
    printf("Test 3 - Pop: %s\n", (val == 20 && s.len == 1) ? "PASSED" : "FAILED");

    // Test 4: Pop again
    val = stackPop(&s);
    printf("Test 4 - Pop: %s\n", (val == 10 && s.len == 0) ? "PASSED" : "FAILED");

    // Test 5: Pop from empty stack
    val = stackPop(&s);
    printf("Test 5 - Pop empty: %s\n", (val == 0 && s.len == 0) ? "PASSED" : "FAILED");

    stackFree(&s);
    return 0;
}