// 2206 벽 부수고 이동하기
// bfs 인데 벽을 한 번까지는 부술 수 있음..
// n m 최대 1,000이므로 n x m 최대 백만
// 시간복잡도 ㅇㅋ
// 이중반복문으로 돌아보면서 벽인 경우에 걔를 없애보고 수행. 
// 다른 벽 없앨때는 이전 벽 다시 세워주고 이거를 반복.
// 벽 안 없애고도 해보고 최단 경로 갱신.
// 불가능하면 -1


// 나의 또 다른 접근법
// 시작점이랑 목적지에서 bfs를 수행해줘
// 그 값들을 board1 board2에 각각 저장해주고
// 가능한 벽에 대해서 board1의 값이랑 비교
// 어떤걸 비교해주냐면 한 번이라도 이동한 값이 그 벽 근처에 있어야함
// 없으면?? 거긴 아예 가지도 못하는 벽이기 때문에 패스
// 있다면?? 거긴 갈 수 있는 벽이기 때문에 인덱스 값 업데이트 해줌
// 어떤 값으로 업데이트 해주냐면 board2 (목적지에서 출발한 bfs)
// 에서 그 벽 근처에 있는 값중 가장 작은 값에다가 +1 한 값으로 업데이트 해줘
// 그러면 가능한 벽들중에서 진짜 가능한 벽에 대해서
// 가장 최소값 찾으면 그게 벽 뚫고 갔을때 그 벽에서부터 목적지까지의 최단거리임
// 따라서 board1에서 벽때문에 멈췄을때 그 값이랑 그 벽에서 목적지까지의 최단거리 더해주면
// 답! 이 아니네요..

// 다른 접근법
// 시작점과 목적지에서 각각 bfs수행. 
// 같이 만나는 지점이 있다면 벽 안 부수고도 갈 수 있음
// 시작점과 출발했을때 벽에 막힌다면 그냥 넘어가는 것이 아니라
// 그 벽 좌표를 wall1에 기억해두고 넘어가
// 목적지에서 출발했을때도 마찬가지.
// 벽에 막히면 wall1[그 벽][좌표]값을 봐봐
// wall1에서 기억해두었던 좌표라면 
// 시작점에서 출발했을때도 그 벽때문에 막혀서 다른 길로 갔었던거임
// 그럼 wall2 값을 1로 두고. 만약 wall1 값이0 이라면 시작점에서 출발했을때
// 그 벽까지 못갔다는 소리므로 패스
// 이렇게 한다면 시작점과 목적지에서 출발했을때 어떤 벽 때문에 가로막혀서
// 최단거리로 못간 경우에 대해 확인해줄 수 있음
// wall2에 1로 표시되어있는 좌표의 경우 두 지점에서 공통으로 막혀버린 벽
// 시작점에서 그 벽까지의 거리 + 목적지에서 그 벽까지의 거리 + 1을 해주면 거리 나옴
// 이 거리들중 가장 작은 거리가 답!

#include <stdio.h>
#include <string.h>
struct data{
    int x;
    int y;
};
int ans = 1000005;
int n, m;
char board[1005][1005];
int board1[1005][1005];
int board2[1005][1005];
int visited[1005][1005];
int visited2[1005][1005];
int wallvist[1005][1005];
int wallvist2[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct data q[1000005];
int head = 0, tail = 0;
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
int min(int a, int b){
    if(a < b) return a;
    return b;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", board[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] - '0' == 1){
                board1[i][j] = -1;
                board2[i][j] = -1;
            }
            else{
                board1[i][j] = board[i][j] - '0';
                board2[i][j] = board[i][j] - '0';
            }
        }
    }
    if(n == 1 && m == 1){
        printf("1");
        return 0;
    }

    //시작점부터 BFS수행
    board1[0][0] = 1;
    push(0,0);
    visited[0][0] = 1;
    while(!isempty()){
        struct data cur = pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(visited[nx][ny]) continue;
            if(board1[nx][ny] == -1 ){
                wallvist[nx][ny] = 1;
                continue;
            }
            if(nx == n-1 && ny == m-1)  ans = board1[cur.x][cur.y] + 1;
            board1[nx][ny] = board1[cur.x][cur.y] + 1;
            push(nx, ny);
            visited[nx][ny] = 1;
        }
    }
    head = 0; tail = 0;
    //목적지부터 BFS수행
    board2[n-1][m-1] = 1;
    push(n-1,m-1);
    visited2[n-1][m-1] = 1;
    while(!isempty()){
        struct data cur = pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
            if(visited2[nx][ny]) continue;
            if(board2[nx][ny] == -1){
                wallvist2[nx][ny] = 1;
                continue;
            }
            board2[nx][ny] = board2[cur.x][cur.y] + 1;
            push(nx, ny);
            visited2[nx][ny] = 1;
        }
    }

    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         printf("%d ", board2[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         printf("%d ", wallvist2[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(wallvist[i][j] && wallvist2[i][j]) continue;
            wallvist[i][j] = 0;
        }
    }
    int dist1 = 1000005;
    int dist2 = 1000005;
    int mindist = 2000015;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist1 = 1000005;
            dist2 = 1000005;
            if(wallvist[i][j]){
                for(int dir = 0; dir < 4; dir++){
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue;
                    if(board1[nx][ny] <= 0) continue;
                    if(board1[nx][ny] < dist1) dist1 = board1[nx][ny];
                }
                for(int dir = 0; dir < 4; dir++){
                    int n2x = i+dx[dir];
                    int n2y = j+dy[dir];
                    if(n2x < 0 || n2x >= n || n2y < 0 || n2y >= m)  continue;
                    if(board2[n2x][n2y] <= 0) continue;
                    if(board2[n2x][n2y] < dist2) dist2 = board2[n2x][n2y]; 
                }
                if(dist1+dist2+1 < mindist) mindist = dist1+dist2+1;
            }
        }
    }

    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         printf("%d ", wallvist[i][j]);
    //     }
    //     printf("\n");
    // }
    if(ans != 1000005)  mindist = min(ans, mindist);

    if(mindist == 2000015)  printf("-1");
    else printf("%d", mindist);
    return 0;
}