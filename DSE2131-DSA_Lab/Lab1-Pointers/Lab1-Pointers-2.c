#include <stdio.h>

struct Pair {
  int number1, number2;
};

struct Pair swap(int a, int b) {
  const int temp = a;
  a = b;
  b = temp;

  struct Pair output;
  output.number1 = a;
  output.number2 = b;
  return output;
}

int main(void) {
  int number1 = 50;
  int number2 = 25;

  printf("Before Swapping:\n   number1 = %d\n   number2 = %d\n", number1, number2);

  struct Pair swapped = swap(number1, number2);
  number1 = swapped.number1;
  number2 = swapped.number2;

  printf("\nAfter Swapping:\n  number1 = %d\n  number2 = %d\n", number1, number2);
}