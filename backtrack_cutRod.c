#include <stdio.h>
#include <limits.h>
int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

int max(int a, int b) { return (a > b)? a : b;}

int cutRod(int size){
	if(size <= 0)
		return 0;
	int q = INT_MIN;
	for(int i=0;i<size;i++){
		q = max(q, arr[i] + cutRod(size-i-1));
	}
	return q;
}

int main()
{
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(size));
    return 0;
}
