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

  // Sort the array before searching (Bubble sort)
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        const int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  while (1) {
    int toSearchValue;
    printf("\nPlease enter the value to search for: ");
    scanf("%d", &toSearchValue);

    // Binary search
    int foundIndex = -1;
    int low = 0, high = length - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == toSearchValue) {
        foundIndex = mid;
        break;
      } else if (arr[mid] < toSearchValue) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (foundIndex == -1) {
      printf("Value not found.\n");
    } else printf("Value %d's first occurrence found at index %dafter sorting.\n", toSearchValue, foundIndex);

    printf("Continue?(y/N): ");
    char answer;
    scanf(" %c", &answer);
    if (answer != 'y' && answer != 'Y') {
      break;
    }
  }
  return 0;
}