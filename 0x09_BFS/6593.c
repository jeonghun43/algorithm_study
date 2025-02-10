// 6593
// bfs
// L R C 각각 30개가 최대임
// O(N) = 테스트케이스 개수 * 30 * 30 * 30 = t * 27만
#include <stdio.h>
struct data{
    int z;
    int x;
    int y;
};
char charboard[50][50][50];
int board[50][50][50];
int visited[50][50][50];
struct data q[300000];
int head = 0, tail = 0;
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
void push(int z, int x, int y){
    q[tail++] = (struct data){z, x, y};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0) return 1;
    return 0;
}
int main(){
    while(1){
        int L, R, C;
        struct data e = {};
        scanf("%d %d %d", &L, &R, &C);
        if(L == 0 && R == 0 && C == 0)  break;

        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                scanf("%s", &charboard[i][j]);  //입력받는건 이게 최선일까..
            }
            getchar();
        }

        for(int k = 0; k < L; k++){
            for(int i = 0; i < R; i++){ //값들 입력받으면서 S와 E의 위치 받아두기
                for(int j = 0; j < C; j++){
                    char c = charboard[k][i][j];
                    if(c == 'S'){       //현위치 값
                        visited[k][i][j] = 1;
                        board[k][i][j] = 1;
                        push(k,i,j);
                    }else if(c == '#'){ //벽이면 board에 -1 담아두기
                        board[k][i][j] = -1;
                    }else if(c == '.'){ //빈공간이면 0 담아두기
                        board[k][i][j] = 0;
                    }else if(c == 'E'){ //탈출구면 따로 위치값 담아두기
                        e = (struct data){k, i, j};
                    }
                }
            }
        }
// printf("checking the Escape's position %d %d %d\n", e.z, e.x, e.y);
// //ㅊ
// printf("--checking charboard----\n");
// for(int k = 0; k < L; k++){
//     for(int i = 0; i < R; i++){ 
//         for(int j = 0; j < C; j++){
//             printf("%c ", charboard[k][i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n\n");
// }
////c

        //S위치에서 bfs수행 escape까지 가는 최소값 출력
        int check = 0;
        while(!isempty() && !check){
            struct data cur = pop();
            for(int dir = 0; dir < 6; dir++){
                int nz = cur.z + dz[dir];
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue; //범위 벗어나면 패스
                if(board[nz][nx][ny] > 0 || board[nz][nx][ny] == -1) continue; //방문했거나 벽이면 패스
                if(nz == e.z && nx == e.x && ny == e.y){ //Escape 도달하면
                    //아니 시발 이걸 ||로 해서 ㅈ같은 결과 나온거였네;;
                    printf("Escaped in %d minute(s).\n", board[cur.z][cur.x][cur.y]);
                    check = 1;
                    break;
                }
                board[nz][nx][ny] = board[cur.z][cur.x][cur.y] + 1;
                push(nz, nx, ny); 
            }
        }
        if(check == 0)  printf("Trapped!\n");

//ㅊ
// printf("--checking board----\n");
// for(int k = 0; k < L; k++){
//     for(int i = 0; i < R; i++){ 
//         for(int j = 0; j < C; j++){
//             printf("%d ", board[k][i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n\n");
// }
// printf("---\n");
//ㅊ


        //다음꺼 실행전 초기화  //vistied무조건 초기화 해줘야함! 아니면 전에 bfs돌았던거 그대로 가져와서 다시 쓰게됨
        head = 0; tail = 0;
        for(int k = 0; k < 50; k++){
            for(int i = 0; i < 50; i++){
                for(int j = 0; j < 50; j++){
                    board[k][i][j] = 0;
                }
            }
        }
    }
    return 0;
}