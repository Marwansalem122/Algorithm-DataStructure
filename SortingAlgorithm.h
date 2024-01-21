//
// Created by HP on 1/20/2024.
//

#ifndef C___CODE_SORTINGALGORITHM_H
#define C___CODE_SORTINGALGORITHM_H


class SortingAlgorithm {
public:
    static void BubbleSort(int arr[],int size);
    static void SelectionSort(int arr[],int size);
    static void InsertionSort(int arr[],int size);
    static void merge(int arr[],int const left,int const mid,int const right);
    static void mergeSort(int arr[],int const begin,int const end);


};


#endif //C___CODE_SORTINGALGORITHM_H
