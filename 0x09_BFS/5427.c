// 5427 불
// bfs
// t 100, w h 1000 이므로 O(N) = 100 * 1,000 * 1,000 = 1억

#include <stdio.h>
struct data{
    int x;
    int y;
};
char board[1005][1005] = {};
int fire[1005][1005] = {};
int seong[1005][1005] = {};
int visitedFire[1005][1005] = {};
int visitedSeong[1005][1005] = {};
int seongPositionX;
int seongPositionY;
struct data q[10000005];
int head = 0, tail = 0;
int t, w, h;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
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
    scanf("%d", &t);
    while(t--){
        int possible = 0;       // 탈출 가능한지에 대해 저장할 변수
        int minans = 0;
        head = 0; tail = 0;
        scanf("%d %d", &w, &h);
        for(int i = 0; i < h; i++)  //문자를 입력받을시 주의하기. //%c로 할때는 '\n' 줄바꿈 문자까지 같이 들어가기때문에 입력에서 꼬이게 됨
            scanf("%s", &board[i]); //따라서 그냥 %s로 한 줄 통으로 받아와버리세요

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '*'){ //불인경우
                    visitedFire[i][j] = 1;   //방문했다고 표시하고
                    push(i, j);         //큐에 넣어줌
                    fire[i][j] = 1;
                }
                else if(board[i][j] == '@'){ //성근이인경우
                    seongPositionX = i;      //그 값 임시 저장
                    seongPositionY = j;
                }
            }
        }

        //불에 대한 bfs 먼저 수행
        while(!isempty()){
            struct data cur = pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)  continue;   //범위 벗어나면 패스
                if(visitedFire[nx][ny] || board[nx][ny] == '#') continue;   //방문했거나 벽이면 패스
                visitedFire[nx][ny] = 1; //방문했다치고
                push(nx, ny);        //큐에 넣어줌
                fire[nx][ny] = fire[cur.x][cur.y] + 1; //fire가 움직인 시간을 저장함
            }
        }

// //cc
// printf("check fire time board\n");
// for(int i = 0; i < h; i++){
//     for(int j = 0; j < w; j++){
//         printf("%d ", fire[i][j]);
//     }
//     printf("\n");
// }
// printf("\n");
// //cc

        //큐 초기화해주고
        head = 0; tail = 0;

        visitedSeong[seongPositionX][seongPositionY] = 1;
        seong[seongPositionX][seongPositionY] = 1;
        push(seongPositionX, seongPositionY);
        //성근이에 대한 bfs 수행
        while(!isempty()){
            struct data cur = pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){   //범위 벗어나면 성공 
                    possible = 1;
                    minans = seong[cur.x][cur.y] + 1;
                    while(!isempty()){
                        pop(); //큐 비워내기
                    }   
                    break;
                }
                if(visitedSeong[nx][ny] || board[nx][ny] == '#') continue;//방문했거나 벽이면 패스
                if(fire[nx][ny] != 0 && seong[cur.x][cur.y]+1 >= fire[nx][ny])   continue; //불에 닿는곳이면 패스
                //불이 먼저 도착해있는지 보는 조건문의 경우 주의해야함
                //불의 시작을 1이라고 했을때 불값이 0인경우라면 불이 아예 닿지도 못하는 경우임
                //불이 0일때를 제외하고!! 따져봐야하는것임.
                //이거를 빼먹어서 12퍼에서 틀렸었음

                visitedSeong[nx][ny] = 1;
                push(nx, ny);
                seong[nx][ny] = seong[cur.x][cur.y] + 1;
            }
        }

//         //cc
// printf("check fire seong board\n");
// for(int i = 0; i < h; i++){
//     for(int j = 0; j < w; j++){
//         printf("%d ", seong[i][j]);
//     }
//     printf("\n");
// }
// printf("\n");
// //cc

        //결과값 출력
        if(possible){
            printf("%d\n", minans-1);
        }else{
            printf("IMPOSSIBLE\n");
        }
        
        //q초기화
        head = 0;
        tail = 0;
        //visted배열들과 fire seong배열 초기화
        for(int i = 0; i < 1005; i++){
            for(int j = 0; j < 1005; j++){
                visitedFire[i][j] = 0;
                visitedSeong[i][j] = 0;
                fire[i][j] = 0;
                seong[i][j] = 0;
                board[i][j] = '!';
            }
        }
    }
    return 0;
}