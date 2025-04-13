//
// Created by Lenovo on 25-4-13.
//

#include<stdio.h>
#include"sort.h"



void swap(int *a,int*b) {
    int temp = *a;
    *a = * b;
    *b = temp;
}

void quickSort(int array[],int left,int right)
{
    if (left >= right) return;

    int Lindex = left;
    int Rindex = right-1;
    int compare = array[right];

    while (Lindex <= Rindex) {
        if (array[Lindex] <= compare) {
            Lindex++;
            continue;
        }
        if (array[Rindex] >= compare) {
            Rindex--;
            continue;
        }
        swap(&array[Lindex], &array[Rindex]);
    }

    swap(&array[Lindex], &array[right]);

    quickSort(array, left, Lindex-1);
    quickSort(array, Lindex+1, right);
}


void mergeSort(int array[], int left, int right) {
    if (right <= left) return;

    int midIndex = left + (right-left)/2;
    mergeSort(array, left, midIndex);
    mergeSort(array, midIndex+1, right);

    int temp[right-left+1];
    int lindex = left;
    int rindex = midIndex+1;
    int t = 0;

    // 合并
    while (lindex <= midIndex && rindex <= right) {
        if (array[lindex] <= array[rindex]) {
            temp[t++] = array[lindex++];
        } else {
            temp[t++] = array[rindex++];
        }
    }


    while (lindex <= midIndex) temp[t++] = array[lindex++];
    while (rindex <= right) temp[t++] = array[rindex++];


    for (int i = 0; i < t; i++) {
        array[left+i] = temp[i];
    }
}

void heapAdjust(int array[], int start, int end) {
    int dad = start;
    int son = start*2+1;
    while ( son <= end ) {
        if (array[son]< array[son+1]&&son+1<=end) {
            son++;
        }
        if (array[son]<array[dad]) {
            return;
        }
        else {
            swap(&array[dad], &array[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}
void heapSort(int array[],int len) {
    for (int i = len/2-1;i>=0;i--) {
        heapAdjust(array,i,len-1);
    }
    for (int i = len-1 ; i>=0;i--) {
        swap(&array[0],&array[i]);
        heapAdjust(array,0,i-1);
    }
}


int quickTest() {
    int a[]={2,1,4,5,32,3};
    //quickSort(a,0,5);
    //mergeSort(a,0,5);
    heapSort(a,6);
    for (int i =0 ; i <6 ;i++) {
        printf("%d ",a[i]);
    }
    return 0;
}

