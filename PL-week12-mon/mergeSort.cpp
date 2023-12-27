// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

#include <algorithm>
#include <iostream> 

using namespace std;

void merge(int array[], int left, int mid, int right) {
  int subArrayOne = mid - left + 1;
  int subArrayTwo = right - mid;

  int *leftArray = new int[subArrayOne];
  int *rightArray = new int[subArrayTwo];

  for (int i = 0; i < subArrayOne; i++) {
    leftArray[i] = array[left + i];
  }

  for (int i = 0; i < subArrayTwo; i++) {
    rightArray[i] = array[mid + 1 + i];
  }

  int indexOfSubArrayOne = 0;
  int indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }

    indexOfMergedArray++;
  }

  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }

  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }

  delete[] leftArray;
  delete[] rightArray;
}


void mergeSort(int array[], int begin, int end) {

  if (begin >= end) {
    return;
  }

  int mid = begin + (end - begin) / 2;

  mergeSort(array, begin, mid);
  mergeSort(array, mid + 1, end);

  merge(array, begin, mid, end);
}


int main() {

  int arr[] = {4, 8, 39, 10, 39, 4, 0, 2};

  int arr_size = sizeof(arr) / sizeof(int);

  cout << "Array:" << endl;
  for (auto kv : arr) {
    cout << kv << " ";
  }

  mergeSort(arr, 0, arr_size - 1);
  cout << endl;

  cout << "Sorted Array:" << endl;
  for (auto kv : arr) {
    cout << kv << " ";
  }
  cout << endl;

  return 0;
}