#include <stdio.h>

void swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int number1 = 50;
  int number2 = 25;

  printf("Before Swapping:\n   number1 = %d\n   number2 = %d\n", number1, number2);

  swap(&number1, &number2);

  printf("\nAfter Swapping:\n  number1 = %d\n  number2 = %d\n", number1, number2);
}