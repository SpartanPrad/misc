#include<stdio.h>
#include<stdlib.h>

char X[] = "AGGTAB";
char Y[] = "GXTXAYB";

int lcs(int m, int n)
{
    int l[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) l[i][j]=0;
            else if(X[i]==Y[j]){
                l[i][j]=l[i-1][j-1] + 1;
            }
            else{
                l[i][j]=max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    return l[m][n];
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int main()
{
  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d\n", lcs(m, n) );

  return 0;
}
