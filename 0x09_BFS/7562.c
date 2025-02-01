// 7562 나이트의 이동
#include <stdio.h>
struct data
{
    int x;  //x좌표 가로방향
    int y;  //y좌표 세로방향
};
int t, s;
int head = 0, tail = 0;
struct data q[1000005];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
void push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data pop(){
    if(tail - head == 0) return (struct data){-1,-1};
    return q[head++];
}
int isempty(){
    return tail-head == 0 ? 1 : 0;
}
int main(){
    scanf("%d", &t);        //테스트케이스 개수 입력
    while(t-- > 0){
        int arr[301][301] = {};
        int visited[301][301] = {};
        
        int curx, cury;
        int desx, desy;
        scanf("%d", &s);    // 체스판 크기 입력
        scanf("%d %d", &curx, &cury);
        scanf("%d %d", &desx, &desy);

        visited[cury][curx] = 1;
        push(curx, cury);

        while(!isempty()){
            struct data cur = pop();

            if(cur.x == desx && cur.y == desy){
                break;
            } 
             
            for(int i = 0; i < 8; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(visited[ny][nx])   continue;
                if(nx < 0 || nx >= s || ny < 0 || ny >= s)   continue;
                visited[ny][nx] = 1;
                arr[ny][nx] = arr[cur.y][cur.x] + 1;
                push(nx, ny);
            }
        }
        printf("%d\n", arr[desy][desx]);
        head = 0;
        tail = 0;
    }
    return 0;
}

// bfs
// 시간복잡도는 안녕하겠지 뭐
// queue,  struct data => x, y 좌표
// head tail q[]    dx[] dy[]
// T 테스트케이스 개수, s 체스판크기 arr[301][301]체스판 
// current 현재 칸,  goal 이동하려는칸,  cnt 이동횟수,  mincnt 최소횟수