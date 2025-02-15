// 16987 계란으로 계란치기
#include <stdio.h>
int n;
int s[305];
int w[305];
int iscrush[10];
int ans = 0;
void func(int k){
    if(k == n){
        int egg = 0;
        for(int i = 0; i < n; i++){
            if(s[i] <= 0) egg++;
        }
        if(egg > ans)   ans = egg;
        return;
    }
    if(s[k] <= 0){
        func(k+1); // 들고있는게 깨져있는계란이면 다음꺼 계란 들자
        return;
    }   
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(i == k){ //반복문 돌때 손에든 계란 차례라면
            continue;
        }
        if(s[i] <= 0){
            continue; //대상이 깨져있는 계란이면 패스
        }

        int tmpk = s[k];
        int tmpi = s[i];  
        s[k] -= w[i];
        s[i] -= w[k];
        flag = 1;
        func(k+1);
        s[k] = tmpk;
        s[i] = tmpi;
    }
    if(!flag) func(k+1);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &s[i], &w[i]);
    }
    func(0);
    printf("%d", ans);
    return 0;
}