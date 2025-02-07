// 2468 안전영역
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n;
int board[101][101];
int rain[105];
int raintmp[105];
int raincnt=0;
int ans = 0;
struct data q[1000005];
int head = 0, tail = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0)   return 1;
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
            //raintmp[board[i][j]]++;
        }
    }

    // for(int i = 1 ; i <= 100; i++){
    //     if(raintmp[i] == 0) continue;
    //     rain[raincnt++] = i;
    // }

    for(int r = 0; r <= 100; r++){
        int board2[101][101] = {};
        int visted[101][101] = {};
        int chunck = 0;
        for(int i = 0; i < n; i++){ //비 높이에 따라 잠긴 곳을 1이라고 표시
            for(int j = 0; j < n; j++){
                if(board[i][j] <= r)
                    board2[i][j] = 1;
            }
        }

        // 다 돌면서 bfs 수행
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visted[i][j] || board2[i][j] == 1) continue;
                visted[i][j] = 1;
                push(i, j);

                while(!isempty()){
                    struct data cur = pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue; // 범위 벗어나면 패스
                        if(visted[nx][ny] || board2[nx][ny] == 1)   continue; // 방문한적있거나 비에 잠긴곳이라면 페스
                        board2[nx][ny] = chunck;
                        visted[nx][ny] = 1;
                        push(nx, ny);
                    }
                }
                chunck++;   //bfs하나 수행 끝났으면 덩어리 개수 +1
            }
        }
       
        if(chunck > ans)    ans = chunck;
        head = 0;
        tail = 0;
    }

    printf("%d", ans);
    return 0;
}