// 5014 스타트링크
// bfs
// F S G U D
// 기존문제들과는 다르게 +1 -1칸 움직이는 것이 아닌
// +U칸 -D칸 움직임
// s == g일때 0출력해줘야하는데 다른 조건 추가 안해주면
// use the stairs 가 출력돼버리네요
int F, S, G, U, D;
int arr[1000005];
int visted[1000005];
int q[5000005];
int head = 0, tail = 0;
int dx[2] = {1, -1};
void push(int x){
    q[tail++] = x;
}
int pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0)    return 1;
    return 0;
}
#include <stdio.h>
int main(){
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    visted[S] = 1;
    arr[S] = 0;
    push(S);
    int goal = 0;
    if(S == G){
        printf("0");
        return 0;
    }  
    while(!isempty()){
        int x = pop();

        for(int i = 0; i < 2; i++){
            int nx;
            if(i == 0) nx = x + dx[i] * U;
            if(i == 1) nx = x + dx[i] * D;

            if(nx <= 0 || nx > F) continue;
            if(visted[nx])  continue;
            if(nx == G) goal = 1;
            arr[nx] = arr[x]+1;
            visted[nx] = 1;
            push(nx);
        }

    }
    if(goal)    printf("%d", arr[G]);
    else printf("use the stairs");
    return 0;
}