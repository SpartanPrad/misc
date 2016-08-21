#include <stdio.h>
#include <limits.h>
int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

int max(int a, int b) { return (a > b)? a : b;}

int cutRod(int size, int r[]){
	int q = INT_MIN;
	if(r[size]>=0)
		return r[size];
	if(size == 0)
		q = 0;
	for(int i=0;i<size;i++){
		q = max(q, arr[i] + cutRod(size-i-1, r));
	}
	r[size] = q;
	return q;
}

int main()
{
    int size = sizeof(arr)/sizeof(arr[0]);
    int r[size];
    memset(r, -1, sizeof(arr));
    printf("Maximum Obtainable Value is %d\n", cutRod(size, r));
    return 0;
}
