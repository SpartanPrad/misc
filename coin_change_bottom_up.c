#include <stdio.h>

int arr[] = {1, 2, 3};

int count(int m, int n){
	int c[m][n+1];
	for(int i=0;i<n+1;i++)
		c[i][0] = 1;
	int x=0, y=0;
	for(int i=0;i<m;i++){
		for(int j=1;j<n+1;j++){
			x = (j-arr[i] >= 0)?c[i][j-arr[i]]:0;
			y = (i>=1)?c[i-1][j]:0;
			c[i][j] = x+y;
		}
	}
	return c[m-1][n];	
}

int main()
{
    int i, j;
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(m, 4));
    getchar();
    return 0;
}
