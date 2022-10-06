#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void display(int*arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int*x,int*y)
{
    int k = *x;
    *x = *y;
    *y = k;
}

void insertion_sort()
{
    int arr[] = {5,4,8,2,1};
    int l = sizeof(arr)/sizeof(int);
    for (int i = 1; i < 5; i++)
    {
        int j = i-1;
        int val = arr[i];
        while(arr[j]>val && j>-1)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
    
    for (int p = 0; p < l; p++)
    {
        printf("%d ",arr[p]);
    }
    printf("\n");    
}

void selection_sort()
{
    int arr[] = {12,11,13,5,6};
    int l = sizeof(arr)/sizeof(int);
    for (int i = l-1; i >= 0; i--)
    {
        int val = arr[i],p1=val;
        int p = i;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>p1)
            {
                p=j;
                p1=arr[j];
            }
        }
        swap(&arr[i],&arr[p]);
    }
    display(arr,5);
}

int main()
{
    insertion_sort();
    selection_sort();
    return 0;
}
