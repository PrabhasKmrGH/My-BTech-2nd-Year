#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int length;
  printf("Input the length of the array: ");
  scanf("%d", &length);

  if (length <= 0) {
    printf("Nothing to delete.\n");
    return 0;
  }

  int *arr = malloc(length * sizeof(int));
  if (!arr) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < length; i++) {
    printf("Please enter a number for index %d: ", i);
    scanf("%d", &arr[i]);
  }

  while (length > 0) {
    int delIndex;
    printf("Enter the index of the element to delete (0 to %d) (negative to quit): ", length - 1);
    scanf("%d", &delIndex);

    if (delIndex < 0) {
      break;
    }
    if (delIndex >= length) {
      printf("Invalid index.\n");
      continue;
    }

    // Shift elements left to overwrite deleted element with next element
    for (int i = delIndex; i < length - 1; i++) {
      arr[i] = arr[i + 1];
    }

    length--;

    int *temp = realloc(arr, length * sizeof(int));
    if (temp != NULL) {
      arr = temp;
    }

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