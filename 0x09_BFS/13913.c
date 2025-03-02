// 13913 숨박꼭질 4
// n 10만, k 10만
// 동생 찾는 가장 빠른 시간 + 어떻게 이동해야하는지 출력
// bfs인데.. 과정 출력을 어떻게 다뤄줘야할까

int n, k;
int q[100005];
int head = 0, tail = 0;
int dx[3] = {1, -1, 2};
int board[100005];
int visited[100005];
int route[100005];
int answer[100005];
int idx = 0;
void push(int x){
    q[tail++] = x;
}
int pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0) return 1;
    return 0;
}
#include <stdio.h>
int main(){
    scanf("%d %d", &n, &k);

    board[n] = 1;
    push(n);
    visited[n] = 1;
    route[5] = -1;
    int flag = 1;
    while(flag && !isempty()){
        int cur = pop();
        for(int dir = 0; dir < 3; dir++){
            int nx;
            if(dir==2){
                nx = cur * dx[dir];
            }else{
                nx = cur + dx[dir];
            }

            if(nx < 0 || nx > 100000) continue;
            if(visited[nx] || board[nx]) continue;
            push(nx);
            visited[nx] = 1;
            board[nx] = board[cur]+1;
            route[nx] = cur;
            if(nx == k){
                flag = 0;
                break;
            }
        }
    }
    int ans = board[k];
    idx = ans;
    answer[idx--] = k;
    int c = route[k];
    while(c != -1 && idx >= 0){
        answer[idx--] =  c;
        c = route[c];
    }
    //answer[1] = n;
    // for(int i = 0; i <= k+10; i++){
    //     printf("%d ", board[i]);
    // }printf("\n");
    printf("%d\n", ans-1);
    for(int i = 1; i <= ans; i++){
        printf("%d ", answer[i]);
    }

    //     printf("\n");
    // for(int i = 0; i <= k+10; i++){
    //     printf("%d ", route[i]);
    // }
    
    return 0;
}