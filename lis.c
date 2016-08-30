#include<stdio.h>
#include<stdlib.h>

int lis(int arr[], int n)
{
    int *lis = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<(1+lis[j]))
                lis[i]=lis[j]+1;
        }
    }
    int max=1;
    for(int i=0;i<n;i++)
        max = max>lis[i]?max:lis[i];
    return max;
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}
