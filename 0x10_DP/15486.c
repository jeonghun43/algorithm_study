// 15486 퇴사 2
// n 최대 150만 이므로 백트래킹 안되고 dp로 해결
//금액 최대는 1,000 많아봐야 150만개
// 금액 누적의 최댓값은 약 15억이므로 int 사용가능 
#include <stdio.h>
int n;
int ans = 0;
int t[1500005];     // 기간
int p[1500005];     // 금액
int d[1500005];     // d[i]는 i일때 얻을 수 있는 최대 이익
int max(int a, int b){
    if(a > b) return a;
    return b;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    for(int i = n; i >= 1; i--){
        if(i + t[i] > n+1) d[i] = d[i+1]; 
        //왜 이때 d[i] = d[i+1]을 해줘야하는걸까..? 
        //아. 그래야 지난번에 있던 값을 가져와서 
        //비교해줄 수 있겠구나 ㅎ 옼에ㅣ

        else d[i] = max(p[i] + d[i+t[i]], d[i+1]);
   
    }
    for(int i = 1; i <= n; i++){
        if(d[i] > ans)  ans = d[i];
    }

    printf("%d", ans);
    return 0;
}