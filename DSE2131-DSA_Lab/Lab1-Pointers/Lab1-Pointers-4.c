#include <stdio.h>

void doubleArrayValues(int* array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = array[i] * 2;
  }
}

int main(void) {
  // Input the size of array; and then get the values.
  int size;
  printf("Enter size of array: ");
  scanf("%d", &size);

  printf("\n"); // empty line
  int array[size];
  for (int i = 0; i < size; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &array[i]);
  }

  // Print the array's elements BEFORE calling doubleArrayValues() function on it.
  printf("\nArray before doubling:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  doubleArrayValues(array, size);

  // Print the array's elements AFTER calling doubleArrayValues() function on it.
  printf("\n\nArray after doubling:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}