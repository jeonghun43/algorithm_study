// 소인수분해
#include <stdio.h>
int n;
int main(){
    scanf("%d", &n);
    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            printf("%d\n", i);
            n = n/i;
        }
    }
    if(n != 1)printf("%d", n);
    return 0;
}