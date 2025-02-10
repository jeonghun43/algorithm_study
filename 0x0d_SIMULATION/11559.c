// 아직 해결 못함..
// 11559 Puyo Puyo
// bfs 애니팡마냥 4개모이면 터짐 연쇄+1
// 1. 4개 연속인것 찾기
// 2. 걔네 터지면서 위에있던 뿌요들이 아래로 떨어짐..
#include <stdio.h>
struct data{
    int x;
    int y;
};
int ising = 1;
int ans = 0;
int boom[6][2];
char board[15][10];
int visited[15][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct data q[1000000];
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
    for(int i = 0; i < 12; i++){    //입력받고
        scanf("%s", &board[i]);
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 2; j++){
            boom[i][j] = -1;
        }
    }
    while(ising){
        int check = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j] == '.' || visited[i][j])  continue; // .이거나 사용한 적 있다면 패스
            visited[i][j] = 1;
            push(i, j);
            boom[j][0] = i;
            boom[j][1] = i;
            char tmp = board[i][j];
            int tmpcnt = 1;
            while(!isempty()){
                struct data cur = pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;   //범위 벗어나면 패스
                    if(visited[nx][ny] || board[nx][ny] != tmp) continue;   //방문한 적 있거나, 다른 글자면은 패스
                    visited[nx][ny] = 1;
                    push(nx, ny);
                    tmpcnt++;

                    if(nx > boom[j][1]) boom[j][1] = nx;
                    if(ny != j) {
                        if(boom[ny][0] == -1){
                            boom[ny][0] = nx;
                            boom[ny][1] = nx;
                        }else{
                            if(boom[ny][0] > nx)
                                boom[ny][0] = nx;
                            if(nx > boom[ny][1])
                                boom[ny][1] = nx;
                        }
                    }
                }
            }
            if(tmpcnt >= 4){
                check = 1;
            }else{
                boom[j][0] = 0;
                boom[j][1] = 0;
            }
        }
    }
    if(!check){ //되는게 한 개도 없으면 끄읕
        ising = 0;
    }else{      //되는게 있으면 밑으로 떨어져랏
        char tmpboard[15][10];
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                tmpboard[i][j] = board[i][j];
            }
        }
        printf("umm rr check %d %d\n\n", boom[1][0], boom[1][1]);
        for(int col = 0; col < 6; col++){
            for(int row = 0; row < 12; row++){
                if(boom[col][1]-row < 0) break;

                if(boom[col][0]-1-row < 0)  
                    tmpboard[11-row][col] = '.';
                else 
                    tmpboard[boom[col][1]-row][col] = board[boom[col][0]-1-row][col];
            }
        }

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                board[i][j] = tmpboard[i][j];
            }
        }
        printf("this is down!\n");
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");


    }
    ans++;
}
    printf("%d", ans);
    return 0;
}