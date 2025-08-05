#include <stdio.h>

int main(void) {
  int number = 456;
  int* pointerToNumber = &number;
  int** pointerToPointerToNumber = &pointerToNumber;

  int zero = **(pointerToPointerToNumber) - number;

  printf("zero = %d\n", zero); // zero = 0
}