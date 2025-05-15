// 점프왕 젤리
struct data{
    int x;
    int y;
};
struct data q[50];
int head = 0, tail = 0;
int n, success = 0;
int board[3][3], visit[3][3];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
void push(int x, int y){
    q[tail++] = (struct data){x,y};
}
struct data pop(){
    return q[head++];
}
int isEmpty(){
    if(head == tail) return 1;
    else return 0;
}
#include <stdio.h>
int main(){
    scanf("%d", &n);
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
        }
    }
    push(0,0);
    visit[0][0] = 1;
    while(!isEmpty() && !success){
        struct data cur = pop();
        for(int dir= 0; dir < 2; dir++){
            int nx = cur.x + (dx[dir] * board[cur.x][cur.y]);
            int ny = cur.y + (dy[dir] * board[cur.x][cur.y]);
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny]) continue;
            if(nx == n-1 && ny == n-1){
                success = 1;
                break;
            }
            push(nx, ny);
            visit[nx][ny] = 1;
        }
    }
    if(success) printf("HaruHaru\n");
    else printf("Hing\n");
    return 0;
}