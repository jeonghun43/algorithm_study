1929 그림
#include <stdio.h>
struct dat
{
    int x;
    int y;
};

struct dat dat[1000005];
int head = 0, tail = 0;

void push(int x, int y){
    dat[tail++] = (struct dat){x,y};

}
struct dat pop(){
    return dat[head++];
}

int empty(){
    return tail - head == 0 ? 1 : 0;
}

int main(){
    int board[502][502];
    int vis[502][502];
    int n,m;
    int cnt=0, area=0, maxArea=0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0}; 
    int nx, ny;


    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&board[i][j]);
        }
    }

     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                cnt++;
                area++;
                vis[i][j] = 1;
                push(j,i);      //이차원배열[세로][가로] 이니까 push해줄때 x y 잘 맞춰서 넣어줘야함
                
                while(!empty()){
                struct dat cur = pop();
                    for(int dir = 0; dir < 4; dir++){
                    nx = cur.x + dx[dir];
                    ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n)    continue;   //범위를 벗어나면 패스        실수했던건  nx > m  ny > n 이렇게 썼던 것. 범위실수했고
                    if(board[ny][nx] == 0 || vis[ny][nx])   continue;       //색칠 안 되어있거나 방문한 적 있다면 패스  글고 여기서 이차원 배열을 그냥 x,y 느낌으로 써버렸어. 그게 아니고 이차원 배열은 [세로][가로] 라는 것  다시 리마인드!
                    area++;
                    vis[ny][nx] = 1;
                    push(nx, ny);
                    }
                }

                if(area > maxArea) maxArea = area;
                area = 0;
            }
        }
    }

    printf("%d\n%d", cnt, maxArea);

    return 0;
}