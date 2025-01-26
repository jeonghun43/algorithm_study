// 9663 N-Queen
#include <stdio.h>
int N;
int cnt=0;
int issued1[15];    //최대 14   열에 대해서 판단
int issued2[30];    //최대 26   좌측하단에서 우측상단 대각선 판단   x+y
int issued3[30];    //최대 26   좌측상단에서 우측하단 대각선 판단   x-y+n-1
void func(int cur){
    if(cur == N){
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++){
        if(issued1[i] || issued2[cur+i] || issued3[cur-i+N-1]) continue;
        issued1[i] = 1;
        issued2[cur+i] = 1;
        issued3[cur-i+N-1] = 1;
        func(cur+1);
        issued1[i] = 0;
        issued2[cur+i] = 0;
        issued3[cur-i+N-1] = 0;
    }
}   
int main(){
    scanf("%d", &N);
    func(0);
    printf("%d", cnt);
    return 0;
}