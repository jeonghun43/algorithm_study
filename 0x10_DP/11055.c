// 11055 가장 큰 증가하는 부분 수열
#include <stdio.h>
int n;
long long int ans = 0;
int arr[1005];
long long int d[1005];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    d[1] = arr[1];
    if(d[1] > ans)  ans = d[1];
    for(int i = 2; i <= n; i++){
        d[i] = arr[i];
        int tmpmax = 0;
        int tmpmaxidx = -1;
        for(int j = i-1; j >= 1; j--){ //해당 값을 기준으로 왼쪽으로 가면서 판단
            if(arr[j] >= arr[i]) continue;
            if(d[j] > tmpmax){
                tmpmaxidx = j;
                tmpmax = d[j];
            } 
        }
        d[i] += d[tmpmaxidx];
        if(d[i] > ans) ans = d[i];
    }
    printf("%lld", ans);
    return 0;
}