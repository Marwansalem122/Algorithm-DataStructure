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
