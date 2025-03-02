// 1912 연속합
// 1초
// n은 최대10만
// DP
// sum[i]는 0번째부터 i번째까지의 합
// d[i]는 i번째 값을 무조건 포함하는 연속되는 구간의 최대값


// 바킹독의 풀이
// 나는 sum이랑 d를 뒀는데 
// 바킹독은 d 하나만 둠
// d[i] = max(0, d[i-1]) + a[i];
// 흠..음수가 너무 커서 누적합의 값이 음수가 되버리면 그냥 버리는게 나음
// 음수가 작아서 눚거합의 값이 여전히 양수라면 그대로 가져와서 누적합 구해줘
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