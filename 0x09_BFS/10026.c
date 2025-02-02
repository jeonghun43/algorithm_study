//10026 적록색약
// BFS
// R G B 덩어리들이 총 몇개가 나오는가
// 적록색약 아닌사람이 봤을때 bfs수행
// 적록색약인 사람이 봤을때 bfs수행
//시간복잡도는 bfs를 두번 수행하므로 2 * 10000 = 20,000 이정도임
// N    board[105][105]     isused[105][105]
//Queue q[100000] head tail  struct data{x, y}   cnt rgcnt
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n;
int cnt=0, rgcnt=0;
char board[105][105];
int isused[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};      //오른쪽 아래쪽 왼쪽 위쪽 순서로
struct data q[100000];
int head = 0, tail = 0;
void push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0)    return 1;
    return 0;
}
int main(){
    scanf("%d", &n);            //n 입력
    for(int i = 0; i < n; i++)  //rgb 입력
        scanf("%s", &board[i]);

    //적록색약 아닌 사람의 판단
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isused[i][j]) continue;
            isused[i][j] = 1;
            push(i,j);

            while(!isempty()){  //bfs수행
                struct data cur = pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;   //범위 벗어나면 패스
                    if(isused[nx][ny] || board[nx][ny] != board[cur.x][cur.y])  continue; //방문한적 있거나 다른 친구면 패스
                    isused[nx][ny] = 1; //방문했다고 표시
                    push(nx, ny);
                }
            }
            cnt++;
        }
    }
    head = 0;
    tail = 0; //큐 초기화
    int isused[105][105] = {};
    //적록색약인 사람의 판단
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isused[i][j]) continue;
            isused[i][j] = 1;
            push(i,j);

            while(!isempty()){  //bfs수행
                struct data cur = pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;   //범위 벗어나면 패스
                    if(isused[nx][ny])  continue; //방문한적 있다면 패스
                    if(board[cur.x][cur.y] == 'R')  //R일때 G가 나오면 같은 걸로 판단해야함
                        if(board[nx][ny] == 'G'){
                            isused[nx][ny] = 1;
                            push(nx, ny);
                        }
                    if(board[cur.x][cur.y] == 'G')  //G일때 R이 나오면 같은 걸로 판단해야함
                        if(board[nx][ny] == 'R'){
                            isused[nx][ny] = 1;
                            push(nx, ny);
                        }
                    if(board[nx][ny] != board[cur.x][cur.y])  continue; //서로 다른거면 패스
    
                    isused[nx][ny] = 1; //방문했다고 표시
                    push(nx, ny);
                }
            }
            rgcnt++;
        }
    }

    printf("%d %d", cnt, rgcnt);

    return 0;
}