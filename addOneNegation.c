#include <stdio.h>
#include <stdlib.h>

int addOne(int n){
    //printf("%d\n", ~n);
    //printf("%d\n", -(n+1));
    return -(~n);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", addOne(n));
    return 0;
}
