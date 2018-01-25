#include <stdio.h>
#include<stdlib.h>
void merge(int arr[],int m,int l,int r)
{
    int nL = m-l+1;
    int nR = r-m;
    int i;int j;int k;
    int L[nL];
    int R[nR];
    for(i=0;i<nL;i++)
        L[i] = arr[l+i];
    for(j=0;j<nR;j++)
        R[j] = arr[m+j+1];
    i = 0;j = 0;k = l;
    while(i<nL && j<nR)
    {
        if(L[i] <= R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        arr[k]=R[j];
        j++;
        k++;
    }    
}
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m = l +((r-l)/2);
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,m,l,r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
