#include <stdio.h>

int arr[] = {1, 2, 3};

int count(int m, int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(m<=0 && n>0)
		return 0;
	return count(m-1, n)+count(m, n-arr[m-1]);
}

int main()
{
    int i, j;
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(m, 4));
    getchar();
    return 0;
}
