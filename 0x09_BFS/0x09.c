// 1697 숨박꼭질
#include <stdio.h>

int dat[100005];  
int head = 0, tail = 0;
int board[100005];
int nx;
int dx[3] = {-1, 1, 2};

void push(int x){
    dat[tail++] = x;
}

int pop(){
    return dat[head++];
}

int empty(){
    return tail - head == 0 ? 1 : 0;
}

int main(){

    int N,K;
    scanf("%d %d", &N, &K);

    if(N == K){
        printf("0"); 
        return 0;
    }  

    board[N] = 1;
    push(N);

    while(!empty()){
        int cur = pop();

        for(int dir = 0; dir < 3; dir++){
            if(dir == 2){
                nx = 2 * cur; 
            }
            else nx = cur + dx[dir];

            if(nx < 0 || nx > 100000)   continue;   // 사실 이 문제의 경우에는 주어지는 위치만 0 ~ 100,000 사이인거지 왔다갔다할때는 넘어갈 수도 있는 문제였음 그래서 그냥 무지성으로 조건 저렇게 줘버리면 다른 문제에서는 틀릴 수도 있다 이 문제에서는 운 좋게 ok된거임. 짜피 10만 넘어가는 경우는 +1 하거나 X2해서 넘어갈텐데 넘어가더라도 -1해서 다시 돌아와야하니까 그럴빠엔 그냥 -1 먼저 하고 x2해주면 되잖음 그래서 범위 0~10만으로 해도 맞게 나온거
            if(nx == K) {
                printf("%d\n",board[cur]);
                return 0;
            }
            if(board[nx])    continue;

            board[nx] = board[cur] + 1;
            push(nx);
        }
    }

    return 0;
}

// //4179 불!
// #include <stdio.h>

// struct data{
//     int x;
//     int y;
// };

// struct data datajihun[1000005]; 
// struct data datafire[1000005];
// int headJj=0, tailJj=0, headFf=0, tailFf=0;
// char board[1005][1005];
// int visitjihun[1005][1005];
// int visitfire[1005][1005];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int nx, ny;
// int success = 0, maxtime=1, ans = 0;
// void pushJj(int x, int y){
//     datajihun[tailJj++] = (struct data){x, y};
// }
// struct data popJj(){
//     return datajihun[headJj++];
// }
// int emptyJj(){
//     return tailJj - headJj == 0 ? 1 : 0;
// }


// void pushFf(int x, int y){
//     datafire[tailFf++] = (struct data){x, y};
// }
// struct data popFf(){
//     return datafire[headFf++];
// }
// int emptyFf(){
//     return tailFf - headFf == 0 ? 1 : 0;
// }


// int main(){
//     int R,C;
//     scanf("%d %d", &R, &C);

//     for(int i = 0; i < R; i++){
//         scanf("%s", &board[i]);
//     }

//     for(int i = 0; i < R; i++){
//         for(int j = 0; j < C; j++){
//             if(board[i][j] == 'J'){
//                 visitjihun[i][j] = 1;
//                 pushJj(i, j);
//             }else if(board[i][j] == 'F'){
//                 visitfire[i][j] = 1;
//                 pushFf(i, j);
//             }
//         }
//     }
 
//     //불에 대한 bfs
//     while(!emptyFf()){
//         struct data cur = popFf();

//         for(int dir = 0; dir < 4; dir++){
//             nx = cur.x + dx[dir];
//             ny = cur.y + dy[dir];
   
//             if(nx < 0 || nx >= R || ny < 0 || ny >= C)       continue;
//             if(board[nx][ny] == '#' || visitfire[nx][ny])    continue;    

//             visitfire[nx][ny] = visitfire[cur.x][cur.y] + 1;
//             pushFf(nx, ny);
//         }
//     }

//     //지훈이에 대한 bfs
//     while(!emptyJj()){
//         struct data cur = popJj();

//         for(int dir = 0; dir < 4; dir++){
//             nx = cur.x + dx[dir];
//             ny = cur.y + dy[dir];

//             if(nx < 0 || nx >= R || ny < 0 || ny >= C){
//                 printf("%d", visitjihun[cur.x][cur.y]); //틀린 풀이에서는 그냥 성공 여부만 조정해주고 끝까지 bfs를 돌렸었는데 굳이 그럴필요가 없음 짜피 BFS 돌아가다가 성공하는 그 순간이 오면 그게 최솟값임. 애초에 배열에 들어가는 거리 값들이 작은 값부터 해서 큰 값 순으로 점점 커지는 것이기 때문!! 그래서 바킹독이 이걸 설명해줬던 거구나
//                 return 0;
//             }
//             if(board[nx][ny] == '#' || visitjihun[nx][ny])  continue;
//             if(visitfire[nx][ny] != 0 && visitjihun[cur.x][cur.y] + 1 >= visitfire[nx][ny])   continue;     //아 visitfire에 값이 안 들어가있던 경우도 빼줘야하는구나.. 그 조건을 빼먹었다

//             visitjihun[nx][ny] = visitjihun[cur.x][cur.y] + 1;
//             pushJj(nx, ny);
//         }
//     }
//     printf("IMPOSSIBLE");   //여기까지 왔다는 건 성공하지 못했다는 것. 정답 출력하고 return 0;해서 끝내면 됨. 이걸 생각해내지 못했음.
//     return 0;
// }

// // 7569 토마토 (3차원)
// #include <stdio.h>
// struct data{
//     int w;
//     int x;
//     int y;
// };
// struct data dat[1000005];
// int head = 0, tail = 0;
// int nw, nx, ny, day = 0;
// int board[105][105][105];
// int dw[6] = {0, 0, 0, 0, 1, -1};
// int dx[6] = {1, 0, -1, 0, 0, 0};
// int dy[6] = {0, 1, 0, -1, 0, 0};


// void push(int w, int x, int y){
//     dat[tail++] = (struct data){w, x, y};
// }

// struct data pop(){
//     return dat[head++];
// }

// int empty(){
//     return (tail - head) == 0 ? 1 : 0;
// }

// int main(){
//     int M, N, H;
//     scanf("%d %d %d", &M, &N, &H);

//     for(int i = 0; i < H; i++){
//         for(int j = 0; j < N; j++){
//             for(int k = 0; k < M; k++){
//                 scanf("%d", &board[i][j][k]);
//             }
//         }
//     }

//      for(int i = 0; i < H; i++){
//         for(int j = 0; j < N; j++){
//             for(int k = 0; k < M; k++){
//                if(board[i][j][k] == 1)  push(i, j, k);
//             }
//         }
//     }

//     while(!empty()){
//         struct data cur = pop();
        
//         for(int dir = 0; dir < 6; dir++){
//             nw = cur.w + dw[dir];
//             nx = cur.x + dx[dir];
//             ny = cur.y + dy[dir];

//             if(nw < 0 || nw >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//             if(board[nw][nx][ny] != 0)    continue;

//             board[nw][nx][ny] = board[cur.w][cur.x][cur.y] + 1;
//             push(nw, nx, ny);
//         }
//     }

//     for(int i = 0; i < H; i++){
//         for(int j = 0; j < N; j++){
//             for(int k = 0; k < M; k++){
//                if(board[i][j][k] == 0){
//                 day = 0;
//                 j = N;
//                 i = H;
//                 break;
//                }else{
//                 board[i][j][k] > day ? day = board[i][j][k] : 1;
//                }
//             }
//         }
//     }

//     printf("%d", day - 1);

//     return 0;
// }


// // 7576 토마토 (2차원)
// #include <stdio.h>
// struct data
// {
//     int x;
//     int y;
// };

// struct data dat[1000005];
// int head = 0, tail = 0;
// int nx, ny, day = 0;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// void push(int x, int y){
//     dat[tail++] = (struct data){x, y};
// }
// struct data pop(){
//     return dat[head++];
// }
// int empty(){
//     return (tail - head) == 0 ? 1 : 0; 
// }

// int board[1005][1005];
// int main(){
//     int M, N;

//     // 가로 세로 크기 입력 받기 
//     scanf("%d %d", &M, &N);

//     //토마토 현 상황 입력 받기 
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < M; j++){
//             scanf("%d",&board[i][j]);
//         }
//     }

//     //판단 시작
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < M; j++){
//             if(board[i][j] == 1)    push(i, j); //익은 토마토들 전부를 큐에 삽입
//         }
//     }
//     //BFS
//     while(!empty()){
//         struct data cur = pop();

//         for(int dir = 0; dir < 4; dir++){
//             nx = cur.x + dx[dir];
//             ny = cur.y + dy[dir]; 

//             if(nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;   //토마토 상자의 범위 벗어나는지 판단
//             if(board[nx][ny] != 0)   continue;  //이미 익었거나 토마토가 없는 경우라면 패스. 이미 익었거나, 아직 안 익었거나, 토마토가 없거나 이렇게 3가지 경우만 존재함

//             board[nx][ny] = board[cur.x][cur.y] + 1;
//             push(nx, ny);
//         }
//     }

//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < M; j++){
//             if(board[i][j] == 0){
//                 day = 0;
//                 i = N;
//                 break;
//             }
//             else    board[i][j] > day ? day = board[i][j] : 1;
//         }
//     }

//     printf("%d", day-1); //최소 일자 출력

//     return 0;
// }

// //2178 미로탐색
// #include <stdio.h>
// struct dat
// {
//     int x;
//     int y;
// };

// struct dat dat[1000005];
// int head = 0, tail = 0;

// void push(int x, int y){
//     dat[tail++] = (struct dat){x,y};

// }
// struct dat pop(){
//     return dat[head++];
// }

// int empty(){
//     return tail - head == 0 ? 1 : 0;
// }
// int main(){
//     int N, M;
//     int nx, ny;
//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};
//     int distance[105][105];
//     char b[105][105];
//     scanf("%d %d", &N, &M);

//     for(int i = 0; i < N; i++){
//         scanf("%s", &b[i]);
//     }

//     distance[0][0] = 1;
//     push(0,0);
//     while(!empty()){
//         struct dat cur = pop();
//         for(int dir = 0; dir < 4; dir++){
//             nx = cur.x + dx[dir];
//             ny = cur.y + dy[dir];

//             if(nx < 0 || nx >= N || ny < 0 || ny >=M)  continue;
//             if(b[nx][ny] == '0' || distance[nx][ny] != 0)    continue;

//             distance[nx][ny] = distance[cur.x][cur.y] + 1;
//             push(nx, ny);
//         }
//     }
//     printf("%d", distance[N-1][M-1]);
//     return 0;
// }