// 2146 다리 만들기
// BFS
// 우선 bfs수행하면서 각 섬의 가장자리 부분을 서로다른 숫자들로 바꿔줌
// 그 부분들 잠시 저장
// ex 1번섬의 가장자리부분은 1, 2번섬의 가장자리부분은 2 이렇게
// 그리고 그 가장자리 부분들에 대해서 bfs를 수행해줌.
// 다른 섬에 도착하자마자 bfs끝내주고 해당 길이값을 min과 비교후 업데이트
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n;
int min = 0x7fffffff;
int board[105][105];
int dis[105][105];
int visited[105][105];
struct data q[100005];
int head = 0, tail = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct data edgepoint[100005]; //얘를 10,005로 했을때 53퍼outofbounds나면서 틀렸는데
// 100,005으로 바꿔주니까 또 되네..? 뭔가 가장자리 친구들 구해주는 코드에 문제 있는듯?
int eidx = 0;
void push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0) return 1;
    return 0;
}
void reset(){
    head = 0;
    tail = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
            dis[i][j] = 0;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
        }
    }
    // 우선 board BFS수행하면서
    // 섬의 가장자리 부분들 값 업데이트
    int edge = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] || board[i][j] == 0) continue;
            push(i, j);
            visited[i][j] = 1;
            while(!isempty()){
                struct data cur = pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                    if(visited[nx][ny]) continue;
                    if(board[nx][ny] == edge) continue;
                    if(board[nx][ny] == 0){
                        board[cur.x][cur.y] = edge;
                        edgepoint[eidx++] = (struct data){cur.x, cur.y};
                        continue;;
                    }
                    push(nx, ny);
                    visited[nx][ny] = 1;
                }
            }
            edge++;
        }
        
    }
    for(int i = 0; i < eidx; i++){
        reset();
        int x = edgepoint[i].x;
        int y = edgepoint[i].y;
        push(x, y);
        visited[x][y] = 1;
        while(!isempty()){
            struct data cur = pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue;
                if(visited[nx][ny] || board[nx][ny] == 1) continue; //방문했거나 섬 안쪽이면 패스
                if(board[nx][ny] == board[x][y]) continue; //같은 섬 가장자리면 패스
                if(board[nx][ny] != 0){  //0이 아니라면 남은 건 다른 섬의 가장자리 뿐
                    int tmp = dis[cur.x][cur.y];
                    if(tmp < min) min = tmp;
                    while(!isempty()) pop(); //이런거 그냥 저 위 while문의 인자에다가 flag같은 거 넣어주고  flag값 false로 바꿔주면됨
                    break;
                }
                //0일때 거리 세주기
                push(nx, ny);
                visited[nx][ny] = 1;
                dis[nx][ny] = dis[cur.x][cur.y]+1;
            }
        }
    // printf("\n");
    // printf("%d %d\n", x, y);
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", dis[i][j]);
    //     }
    //     printf("\n");
    // }
}
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%d", board[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n%d", eidx);  printf("\n");

    printf("%d", min);
    return 0;
}