#include <stdio.h>
#include <stdbool.h>

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx != i) {
      int temp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = temp;
    }
  }
}

bool isSorted(const int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }
  return true;
}

int main(void) {
  // Test 1
  int arr1[] = {5, 2, 9, 1, 5, 6};
  const int n1 = 6;
  selectionSort(arr1, n1);
  printf("Test 1: %s\n", isSorted(arr1, n1) ? "PASSED" : "FAILED");

  // Test 2
  int arr2[] = {3};
  const int n2 = 1;
  selectionSort(arr2, n2);
  printf("Test 2: %s\n", isSorted(arr2, n2) ? "PASSED" : "FAILED");

  // Test 3
  int arr3[] = {10, -1, 2, 5, 0, -10, -45, -5, 0, 100, 1000};
  const int n3 = 11;
  selectionSort(arr3, n3);
  printf("Test 3: %s\n", isSorted(arr3, n3) ? "PASSED" : "FAILED");

  // Test 4
  int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  const int n4 = 30;
  selectionSort(arr4, n4);
  printf("Test 4: %s\n", isSorted(arr4, n4) ? "PASSED" : "FAILED");

  // Test 5
  int arr5[] = {9, 71};
  const int n5 = 2;
  selectionSort(arr5, n5);
  printf("Test 5: %s\n", isSorted(arr5, n5) ? "PASSED" : "FAILED");

  return 0;
}