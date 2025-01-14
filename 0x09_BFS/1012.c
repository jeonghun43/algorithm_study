// 1012 유기농배추
#include <stdio.h>

struct data
{
    int x;
    int y;
};
// 분명 배추개수는 최대 2500개
// 그럼 큐에 들어갈 수 있는게 많아봐야 2500개 아닌가? 
// 크기를 2500으로 잡았더니 out of bounds 런타임 에러 떴음
struct data dat[25005]; // 왜 2500보다 크게 잡아줘야하는것인가..
int head = 0, tail = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void push(int x, int y){
    dat[tail++] = (struct data){x, y};
}
struct data pop(){
    return dat[head++];
}
int empty(){
    return tail - head  == 0 ? 1 : 0; 
}

int main(){
    int T, M, N, K, tmpx, tmpy;
    
    scanf("%d", &T);

    while(T-- > 0){
        int arr[500][500] = {};   //이런식으로 초기화 안해주면 이전값들 그대로 받아지게됨 조심
        int visit[500][500] = {};
        int cnt = 0;
        
        //가로 세로 크기와 배추개수 입력받기
        scanf("%d %d %d", &M, &N, &K);

        //배추 개수만큼 반복하면서 배추가 있는 위치에 값을 1로 초기화
        for(int i = 0; i < K; i++){
            scanf("%d %d", &tmpy, &tmpx);
            arr[tmpx][tmpy] = 1;
        }

        //판단시작
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j] == 0) continue;    //베추 없으면 패스
                if(arr[i][j] == 1 && visit[i][j] == 0){//배추 있고 방문한적 없다면?
                    visit[i][j] = 1;            //방문했다고 표시하고
                    push(i, j);                 //큐에 넣어주기
                    cnt++;                      //한 덩어리의 시작이니 개수 하나 업
                }
                
                while(!empty()){                //큐에 값이 들어있다면
                    struct data cur = pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= M)  continue;   //새로운 좌표가 범위 벗어나면 패스
                        if(arr[nx][ny] == 0 || visit[nx][ny])   continue;   //새로운 좌표에 배추가 없거나 방문한적이 있다면 패스
                        
                        visit[nx][ny] = 1;              //새로운 좌표에 방문했다고 표시
                        push(nx, ny);                   //그 좌표값을 큐에 넣어주기
                    }
                }                                       //이 반복문이 실행된 후 종료되었다면 한 덩어리를 다 그려준거임
            }
        }
        printf("%d\n", cnt);

    } 

    return 0;
}