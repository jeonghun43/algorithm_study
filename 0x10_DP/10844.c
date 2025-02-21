// 10844 쉬운 계단 수
// DP
// wow,,, 끝 자리 수가 0~9임을 활용
#include <stdio.h>
int n;
long long d[105][10];
int main(){
    scanf("%d", &n);

    d[1][0] = 0;
    for(int i = 1; i <= 9; i++){
        d[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
         for(int j = 0; j <= 9; j++){
            if(j == 0)  d[i][j] = d[i-1][1];
            else if(j == 9)  d[i][j] = d[i-1][8];
            else    d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            d[i][j] %= 1000000000;
         }
    }
    // printf("\n");
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= 9; j++){
    //         printf("%d ", d[i][j]);
    //     }
    //     printf("\n");
    // }
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += d[n][i];
        ans %= 1000000000;
    }
    printf("%lld", ans);
    return 0;
}