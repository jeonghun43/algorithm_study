// 15683 감시
// with 바킹독 강의
// 백트래킹을 사용해도 되지만 진법을 이용해도 됨
// 모든 경우를 살펴봐야하고
// cctv가 서로에게 영향을 끼치지 않으면서 독립적으로 동작하기 때문에
// 진법 활용하여 풀이
// 방향은 오른쪽 아래쪽 왼쪽 위쪽 총 4가지 가능
// cctv는 최대 8개
struct data{
    int x;
    int y;
};
int n, m;
struct data cctv[10];//cctv위치 저장할 배열
int cctvcnt = 0;    //cctv개수
int min;            //사각지대 최소개수
int board1[10][10]; //원본 배열
int board2[10][10]; //복사본
int dx[4] = {0, 1, 0, -1};  //세로   
int dy[4] = {1, 0, -1, 0};  //가로   오른쪽 아래쪽 왼쪽 위쪽 순
int OOB(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)  return 1;//범위 벗어나면 true
    return 0;                                        //안 벗어나면 false
}
void upd(int x, int y, int dir){
    dir %= 4;  // 라는 코드가 있어야하는 이유는?? ah upd함수 실행할때 dir+2 dir+3 이런 코드들이 있음 4로 나눈 나머지값으로 연산해주기위해 필요함
    while(1){
        x = x + dx[dir];
        y = y + dy[dir];
        if(OOB(x, y) || board2[x][y] == 6)   //Out of Bounds or 벽
            break;
        if(board2[x][y] != 0)   continue;   //다른 cctv를 만나면 continue
        board2[x][y] = -1;                  //감시 가능한 공간을 -1로 표시
    }
    
}
#include <stdio.h>
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf("%d", &board1[i][j]);
            if(board1[i][j] == 0) min++; //배열의 0개수만큼 min값 올려줘
            if(board1[i][j] != 0 && board1[i][j] != 6)    //cctv일때
                cctv[cctvcnt++] = (struct data){i, j};  //위치 넣고 cctv개수 +1
        }
    int allcase = 1;
    for(int i = 1; i <= cctvcnt; i++){ //cctv개수만큼 4를 곱함 / 4 ^ cctvcnt
        allcase *= 4;       
    }
    for(int tmp = 0; tmp < allcase; tmp++){  //모든 경우의 개수
        for(int i = 0; i < n; i++)          //배열 복사
            for(int j = 0; j < m; j++){
                board2[i][j] = board1[i][j];
            }
        int brute = tmp;
        
        for(int i = 0; i < cctvcnt; i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].x;
            int y = cctv[i].y;
            if(board1[x][y] == 1){  //1번 cctv
                upd(x, y, dir);
            }else if(board1[x][y] == 2){
                upd(x, y, dir);
                upd(x, y, dir+2);
            }else if(board1[x][y] == 3){
                upd(x, y, dir);
                upd(x, y, dir+1);
            }else if(board1[x][y] == 4){
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            }else if(board1[x][y] == 5){
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(board2[i][j] == 0) cnt++;
            }
        if(min > cnt)   min = cnt;
    }
    printf("%d", min);
    return 0;
}