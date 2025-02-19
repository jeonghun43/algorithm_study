// 2667 단지 번호 붙이기
// bfs  n최대 25 시간복잡도 25*25
// 입력받고 이중반복문 돌면서 1을 찾아 
// 찾으면 단지개수 +1하고 bfs수행
// 수행하면서 집 개수 세서 집개수배열에 저장
// 방문한 1이면 그냥 넘어가
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n;
int block = 0;
int hidx = 0;
int home[1000]; // 집 개수는 최대 25*25
char board[30][30];
int visited[30][30];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct data q[1000];
int head = 0, tail = 0;
void sort(){
    for(int i = 0; i < hidx-1; i++){
        for(int j = i+1; j < hidx; j++){
            if(home[i] > home[j]){
                int tmp = home[i];
                home[i] = home[j];
                home[j] = tmp;
            }
        }
    }
}
void push(int x, int y){
    q[head++] = (struct data){x, y};
}
struct data pop(){
    return q[tail++];
}
int isempty(){
    if(tail - head == 0) return 1;
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", board[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //printf("here is %d %d\n", i, j);
            if(visited[i][j]) continue;
            if(board[i][j] == '0') continue;
            //printf("@@ %d %d\n", i, j);
            block++; //단지 수 +1
            push(i, j); //큐에 넣어주고
            visited[i][j] = 1; //방문했다고 표시
            //bfs수행
            int homecnt = 0;
            while(!isempty()){
                struct data cur = pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n)  continue; //범위 벗어나면 패스
                    if(visited[nx][ny] || board[nx][ny] == '0') continue; //방문한적있거나 집 없으면 패스
                    push(nx, ny);
                    visited[nx][ny] = 1;
                }
                homecnt++;
            }
            home[hidx++] = homecnt;
        }
    }
    sort();
    printf("%d\n", block);
    for(int i = 0; i < hidx; i++){
        printf("%d\n", home[i]);
    }
    return 0;
}