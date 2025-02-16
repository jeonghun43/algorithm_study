// 9461 파도반 수열
#include <stdio.h>
int t;
long long d[105];
int main(){
    d[1] = 1; d[2] = 1; d[3] = 1;

    for(int i = 4; i <= 100; i++){
        d[i] = d[i-2] + d[i-3];
    }
    scanf("%d", &t);
    // for(int i = 1; i <= 100; i++){
    //     printf("%lld\n", d[i]);
    // }
    while(t--){
        int tmp;
        scanf("%d", &tmp);
        printf("%lld\n", d[tmp]);
    }
    return 0;
}