// 14501 퇴사
// n : 15,  2초제한
// 백트래킹
#include <stdio.h>
int n;
int t[20];
int p[20];
int ans = 0;
void func(int k, int score){
    if(k >= n+1){
        //printf("%d here? %d\n",k, score);
        if(score > ans) ans = score;
        return;
    }
    int flag = 0;
    for(int i = k; i <= n; i++){
        int newday = i+t[i];
        if(newday > n+1) continue;
        flag = 1;
        //printf("umm %d %d\n", i, newday);
        func(newday, score+p[i]);
    }
    if(!flag)   func(n+10, score);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    func(1, 0);
    printf("%d", ans);
    return 0;
}