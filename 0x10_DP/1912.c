// 1912 연속합
// 1초
// n은 최대10만
// DP
// sum[i]는 0번째부터 i번째까지의 합
// d[i]는 i번째 값을 무조건 포함하는 연속되는 구간의 최대값
#include <stdio.h>
int n;
int arr[100005];
int sum[100005];
int d[100005];
int min, ans;
int max(int x, int y){
    if(x > y)   return x;
    return y;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    d[0] = sum[0];
    min = d[0];
    for(int i = 1; i < n; i++){
        d[i] = max(sum[i], sum[i] - min);
        if(sum[i] < min) min = sum[i];
    }

    ans = d[0];
    for(int i = 1; i < n; i++){
        if(d[i] > ans) ans = d[i];
    }
    printf("%d", ans);

    return 0;
}