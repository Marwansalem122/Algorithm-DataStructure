//
// Created by HP on 1/20/2024.
//

#include "SortingAlgorithm.h"
#include<iostream>
using namespace std;

void SortingAlgorithm::BubbleSort(int *arr, int size) {
    bool swapped;
    for (int i = 0; i < size-1;i++) {
        swapped=false;
        for (int j =0; j <size-i-1 ; ++j) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped= true;
            }
        }
        if(!swapped)
            break;
    }
}

void SortingAlgorithm::SelectionSort(int *arr, int size) {
    int min_index;
    for (int i = 0; i <size; ++i) {
        min_index=i;
        for (int j = i+1; j < size; ++j) {
            if(arr[min_index]>arr[j])
                arr[min_index]=j;
        }
        if(min_index !=i)
            swap(arr[min_index],arr[i]);
    }
}

void SortingAlgorithm::InsertionSort(int *arr, int size) {
    int key,j;
    for (int i = 1; i < size; ++i) {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

void SortingAlgorithm::merge(int *arr, const int left, const int mid, const int right) {
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

void SortingAlgorithm::mergeSort(int *arr, const int begin, const int end) { //O(N*log(N))
    if(begin>=end)
        return;
    int mid =begin+(end-begin)/2;
    mergeSort(arr,begin,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,begin,mid,end);

}

int SortingAlgorithm::partition(int *arr, int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    for (int j = low; j <=high ; ++j) {
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void SortingAlgorithm::quickSort(int *arr, int low, int high) {
   if(high>low){
       int pi= partition(arr,low,high);
       quickSort(arr,low,pi-1);
       quickSort(arr,pi+1,high);
   }
}




