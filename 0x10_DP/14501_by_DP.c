// 14501 퇴사
// 백트래킹으로 풀었었는데 답지 보니까 DP로 풀었네요
#include <stdio.h>
int n;
int t[20];
int p[20];
int d[20];
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    
    for(int i = n; i >= 1; i--){
        if(i+t[i] <= n+1)
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        else
            d[i] = d[i+1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] > ans) ans = d[i];
    }
    printf("%d", ans);
    return 0;
}