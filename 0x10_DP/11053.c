// 11053 가장 긴 증가하는 부분 수열
// DP
// d[i] 는 i를 포함해서 만들 수 있는 가장 긴 수열의 길이
// d[n-1] = 1;
// 그 다음거부터는 비교해서 이전에 있는 값들중 최대값에 대한 정보 넘겨주면서 저장
#include <stdio.h>
int n;
int arr[1005];
int d[1005]; 
int ans = 0;
int max(int a, int b){
    if(a > b) return a;
    return b;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    d[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        int tmp = 0;
        for(int j = i+1; j < n; j++){
            if(arr[i] >= arr[j]) continue;
            if(d[j] > tmp) tmp = d[j];
        }
        d[i] = tmp+1;
        if(d[i] > ans) ans = d[i];
    }
    if(ans == 0) ans = 1;
    printf("%d", ans);

    return 0;
}