#include <iostream>

#include "SortingAlgorithm.h"
#include<string>

//
//50155555
using namespace std;
void printArray(int arr[], int size);
void printArray2(int *pInt, int n);

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
void printArray2(int *pInt, int n) {
    for (int i=0;i<n;i++) {
        cout<<pInt[i]<<" ";
    }
    cout<<endl;
}



int main(){
 int arr[5]={6,0,-2,-10,1};
   SortingAlgorithm sort=SortingAlgorithm();
//    SortingAlgorithm::BubbleSort(arr,5);
//    printArray(arr,5);
//
//    SortingAlgorithm::SelectionSort(arr,5);
//    printArray(arr,5);
//    SortingAlgorithm::InsertionSort(arr,5);
//    printArray(arr,5);
//  SortingAlgorithm::mergeSort(arr,0,4);
   // mergeSort(arr,0,4);
   SortingAlgorithm::quickSort(arr,0,4);
    printArray(arr,5);
    return 0;
}