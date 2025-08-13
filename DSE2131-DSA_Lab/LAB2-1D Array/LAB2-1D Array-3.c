#include <stdio.h>

int main(void) {
  int length;
  printf("Input the length of the array: ");
  scanf("%d", &length);

  if (length <= 0) {
    printf("Nothing to search on.\n");
    return 0;
  }

  int arr[length];

  for (int i = 0; i < length; i++) {
    printf("Please enter a number for index %d: ", i);
    scanf("%d", &arr[i]);
  }

  while (1) {
    int toSearchValue;
    printf("\nPlease enter the value to search for: ");
    scanf("%d", &toSearchValue);

    // Linear search
    int foundIndex = -1;
    for (int i = 0; i < length; i++) {
      if (arr[i] == toSearchValue) {
        foundIndex = i;
        break;
      }
    }
    if (foundIndex == -1) {
      printf("Value not found.\n");
    } else printf("Value %d's first occurrence found at index %d\n", toSearchValue, foundIndex);

    printf("Continue?(y/N): ");
    char answer;
    scanf(" %c", &answer);
    if (answer != 'y' && answer != 'Y') {
      break;
    }
  }
  return 0;
}