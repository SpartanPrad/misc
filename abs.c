#include <stdio.h>
#include <stdlib.h>

void dec2bin(int c)
{
   int i = 0;
   for(i = 31; i >= 0; i--){
     if((c & (1 << i)) != 0){
       printf("1");
     }else{
       printf("0");
     }
   }
   printf("\n");
}

int addOne(int n){
    int mask = n>>31;
    return (n+mask)^mask;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", addOne(n));
    return 0;
}
