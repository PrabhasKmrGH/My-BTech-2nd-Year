#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int length;
  printf("Input the length of the array: ");
  scanf("%d", &length);

  int *arr = malloc(length * sizeof(int));
  if (arr == NULL) {
      printf("Memory allocation failed.\n");
      return 1;
  }

  for (int i = 0; i < length; i++) {
    printf("Please enter a number for index %d: ", i);
    scanf("%d", &arr[i]);
  }

  while (1) {
    int newIndex;
    printf("Enter the index where the new element should be added (0 to %d)  (negative to quit): ", length);
    scanf("%d", &newIndex);

    if (newIndex < 0) {
      break;
    }

    if (newIndex > length) {
      printf("Invalid index.\n");
      continue;
    }

    int newValue;
    printf("Enter a new value: ");
    scanf("%d", &newValue);

    int *temp = realloc(arr, (length + 1) * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        break;
    }
    arr = temp;

    // Shift elements right to make space
    for (int i = length; i > newIndex; i--) {
      arr[i] = arr[i - 1];
    }

    arr[newIndex] = newValue;
    length++;

    printf("Updated array: ");
    for (int i = 0; i < length; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  printf("Final array: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}