#include <iostream>

#include "SortingAlgorithm.h"


//

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
void merge(int arr[],int const left,int const mid,int const right){
    int const subArrayOne=mid-left+1,subArrayTwo=right-mid;
    auto* leftArray=new int[subArrayOne],* rightArray=new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; ++i) {
       leftArray[i]=arr[left+i];
    }
    for (int i = 0; i < subArrayTwo; ++i) {
        rightArray[i]=arr[mid+1+i];
    }
    auto indexOfSubArrayOne=0,indexOfSubArrayTwo=0;
    int indexOfMergedArray=left;
    while(subArrayOne>indexOfSubArrayOne &&subArrayTwo>indexOfSubArrayTwo){
        if(rightArray[indexOfSubArrayTwo]>=leftArray[indexOfSubArrayOne]){
            arr[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }else{
            arr[indexOfMergedArray]=rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(subArrayOne>indexOfSubArrayOne){
        arr[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while(subArrayTwo>indexOfSubArrayTwo){
        arr[indexOfMergedArray]=rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int arr[],int const begin,int const end){

    if(begin>=end)
        return;
        int mid =begin+(end-begin)/2;
        mergeSort(arr,begin,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,begin,mid,end);

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
  SortingAlgorithm::mergeSort(arr,0,4);
   // mergeSort(arr,0,4);
    printArray(arr,5);
    return 0;
}