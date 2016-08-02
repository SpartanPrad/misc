#include <stdio.h>
#include <stdlib.h>

int addOne(int n){
    int m=1;
    while(n & m){
        n ^= m;
        m<<=1;
    }
    n ^= m;
    return n;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", addOne(n));
    return 0;
}
