#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int leftIndex, int midIndex , int rightIndex){
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];
    for(int i = 0;i<leftArraySize;i++){
        leftArray[i] = array[leftIndex+i];
    }
    for(int i = 0;i<rightArraySize;i++){
        rightArray[i] = array[midIndex+i+1];
    }

    int index = leftIndex;
    int i =0,j=0;
    while(i<leftArraySize && j<rightArraySize){
      if(leftArray[i] <= rightArray[j]){
        array[index] = leftArray[i];
        index++;
        i++;
      }
      else{
        array[index] = rightArray[j];
        index++;
        j++;
      }
    }
    while(i<leftArraySize){
        array[index] = leftArray[i];
        i++;
        index++;
    }
    while(j<rightArraySize){
        array[index] = rightArray[j];
        j++;
        index++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex>=rightIndex)return;
    int midIndex = leftIndex + (rightIndex + leftIndex)/2;
    mergeSort(array,leftIndex,midIndex);
    mergeSort(array, midIndex+1,rightIndex);

    merge(array,leftIndex,midIndex,rightIndex);
}

int pivot(int array[],int pivotIndex,int endIndex){
    int swapIndex = pivotIndex;
    for(int i = pivotIndex+1;i<=endIndex;i++){
        if(array[i]<array[pivotIndex]){
            swapIndex++;
            swap(array[i],array[swapIndex]);
        }
    }
    swap(array[pivotIndex],array[swapIndex]);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex>=rightIndex)return;
    int pivotIndex = pivot(array,leftIndex,rightIndex);
    quickSort(array,leftIndex,pivotIndex-1);
    quickSort(array,pivotIndex+1,rightIndex);


}




















int main(){
    return 0;
}
