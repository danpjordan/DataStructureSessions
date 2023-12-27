// This Code is Contributed By Diwakar Jha

#include <iostream>
using namespace std;

// 9 3 2 6 1 4

// 3 2 1 4 9 6

int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low - 1;

  // j = 0
  // i = -1
  // 9 3 2 6 1 4

  // j = 1
  // i = -1
  // 9 3 2 6 1 4

  // j = 2
  // i = 0
  // 3 9 2 6 1 4

  // j = 3
  // i = 1
  // 3 2 9 6 1 4
  
  // j = 4
  // i = 1
  // 3 2 9 6 1 4

  // j = 5
  // i = 2
  // 3 2 1 6 9 4

  // final swap
  // 3 2 1 4 9 6

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);

  return i + 1;
}

void quickSort(int arr[], int low, int high) {

  if (low < high) {
    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5, 6, 9, 2};
  int n = sizeof(arr) / sizeof(int);

  cout << "Array:" << endl;
  for (auto kv : arr) {
    cout << kv << " ";
  }

  quickSort(arr, 0, n - 1);

  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}