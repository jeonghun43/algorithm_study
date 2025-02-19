// 1932 정수 삼각형
// n 최대 500 이라서 백트래킹은 아닌듯
// 그렇다면 dp
// d 테이블 정의 : d[i][j] i번째일때 이전 층에서의 합중에서 최댓값을 더한 값
#include <stdio.h>
int n;
int ans = 0;
int arr[501][501];
int d[501][501];
int max(int a, int b){
    if(a > b) return a;
    return b;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    d[1][0] = arr[1][0];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(j == 0)
                d[i][j] = arr[i][j] + d[i-1][0];
            if(j == i-1)
                d[i][j] = arr[i][j] + d[i-1][i-2];
            else
                d[i][j] = arr[i][j] + max(d[i-1][j-1], d[i-1][j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(d[n][i] > ans)   ans = d[n][i];
    }
    printf("%d", ans);

    return 0;
}