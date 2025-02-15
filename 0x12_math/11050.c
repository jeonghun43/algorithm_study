// 11050 이항계수1
// N! / k! * (N-K)!
#include <stdio.h>
int n, k;
int ans = 1;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = n; i > 1; i--){
        ans *= i;
    }
    for(int i = k; i > 1; i--){
        ans /= i;
    }
    for(int i = n-k; i > 1; i--){
        ans /= i;
    }
    //이렇게 tmp값을 두고 해도 되겠지만
    //더 간단하게 할 수 있었네요
    // int tmp = 1;
    // for(int i = k; i > 1; i--){
    //     tmp *= i;
    // }
    // for(int i = n-k; i > 1; i--){
    //     tmp *= i;
    // }
    // ans = ans / tmp;
    printf("%d", ans);
    return 0;
}