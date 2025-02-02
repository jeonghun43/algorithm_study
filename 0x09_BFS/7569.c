// 7569 토마토 3차원
// bfs
// arr[105][105][105],  visited[105][105][105]
// max,  n, m, h,   q[1000005], head, tail
// struct data{x, y,z}
#include <stdio.h>
struct data{
    int x;  //높이
    int y;  //세로
    int z;  //가로
};
int n, m, h;
int max = 0;
int arr[105][105][105];
int visited[105][105][105];
struct data q[1000005];
int head = 0, tail = 0;
int dx[6] = {0, 0, 0, 0, 1, -1};  //높이
int dy[6] = {0, 1, 0, -1, 0, 0};  //세로
int dz[6] = {1, 0, -1, 0, 0, 0};  //가로   오른쪽 아래쪽 왼쪽 위쪽 앞 뒤 순서임
void push(int x, int y, int z){
    q[tail++] = (struct data){x, y,z};
}
struct data pop(){
    return q[head++];
}
int isempty(){
    if(tail - head == 0)    
        return 1;   //비어있다면 true반환
    return 0;       //그렇지 않으면 false
}
int main(){
    scanf("%d %d %d", &m, &n, &h);  //m가로  n세로  h높이 입력
    for(int i = 0; i < h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++){
                scanf("%d", &arr[i][j][k]); 
                //1은 익은 토마토   0은 익지 않은 토마토  -1은 비어있는 칸
                if(arr[i][j][k] == 1){  //익은 토마토의 경우
                    visited[i][j][k] = 1;//방문했다고 표시하고 
                    push(i, j, k);      //큐에 넣어준다
                }
            }

    while(!isempty()){      //큐가 차있으면 == 비어있지않다면
        struct data cur = pop();

        for(int dir = 0; dir < 6; dir++){ //6방향에 대해서 살펴볼것임
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];

            if(nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) //새로운 좌표가 범위 벗어났는지 판단
                continue;
            if(visited[nx][ny][nz] || arr[nx][ny][nz] == -1) //방문했거나 비어있는 칸이라면 패스
                continue;
            
            visited[nx][ny][nz] = 1;    //방문했다고 표시하고
            push(nx, ny, nz);
            arr[nx][ny][nz] = arr[cur.x][cur.y][cur.z] + 1;
            if(arr[nx][ny][nz]-1 > max)   //기존 max값보다 더 큰 값이 나왔다면 그 값을 max로..
                max = arr[nx][ny][nz]-1;
        }
    }
    

    for(int i = 0; i < h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++){
                if(arr[i][j][k] == 0){  //안 바뀐 토마토가 있다면
                    max = -1;           //-1을 출력해야하므로
                    j = n;
                    i = h;
                    break;              //모든 반복문에서 벗어난다
                }
            }
        
    printf("%d", max);

    return 0;
}