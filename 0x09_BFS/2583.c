// 2583 영역 구하기
// 완전히 bfs문제군
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n, m, k;
int board[105][105];
int isused[105][105];
int chunck_cnt = 0;
int cnt[10005];
struct data q[10005];
int head = 0, tail = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void sort(){
    for(int i = 0; i < chunck_cnt-1; i++){
        for(int j = i+1; j < chunck_cnt; j++){
            if(cnt[i] > cnt[j]){
                int tmp = cnt[i];
                cnt[i] = cnt[j];
                cnt[j] = tmp;
            }
        }
    }
}
void push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0)   
        return 1;
    return 0;
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = 1;
        }
    }
    while(k--){
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i = b; i < d; i++){
            for(int j = a; j < c; j++){
                board[i][j] = 0;    //박스는 0, 가능한 영역은 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(isused[i][j] || board[i][j] == 0)    continue;
            isused[i][j] = 1;
            push(i,j);
            int howmanyarea = 1;
            while(!isempty()){
                struct data cur = pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(isused[nx][ny] || board[nx][ny] == 0)  continue;

                    board[nx][ny] = board[cur.x][cur.y] + 1;
                    howmanyarea++;
                    isused[nx][ny] = 1;
                    push(nx, ny);
                }
            }
            cnt[chunck_cnt++] = howmanyarea;
        }
    }
    sort();
    printf("%d\n", chunck_cnt);
    for(int i = 0; i < chunck_cnt; i++){
        printf("%d ", cnt[i]);
    }
    return 0;
}