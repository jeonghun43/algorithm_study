// 15686 치킨배달
// 백트래킹
// home[105] chicken[20]
// ans
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n, m, ans=2000000;
int board[100][100];
struct data home[1000];
struct data chicken[100];   
int homecnt = 0;
int chickencnt = 0;
int isused[100];
struct data chans[100];
int caldist(int a, int b, int c, int d){
    int x = a - c;
    int y = b - d;
    if(x < 0)   x *= -1;
    if(y < 0)   y *= -1; 
    return x + y;
}
void func(int k, int tmp){
    if(k == m){
        //치킨 거리 구하기
        int alldist = 0;
        for(int i = 0; i < homecnt; i++){
            int mindist = 200;
            for(int j = 0; j < m; j++){
                int curdist = caldist(home[i].x, home[i].y, chans[j].x, chans[j].y);
                if(mindist > curdist)   mindist = curdist;
            }
            alldist += mindist;
        }
        if(ans > alldist)   ans = alldist;
        return;
    }

    for(int i = tmp; i < chickencnt; i++){
        if(isused[i])   continue;
        chans[k] = chicken[i];
        isused[i] = 1;
        func(k+1, i);
        isused[i] = 0;
    }
    
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){             //50 * 50 = 2500
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] == 1)    home[homecnt++] = (struct data){i, j};
            if(board[i][j] == 2)    chicken[chickencnt++] = (struct data){i, j};
        }
    }

    func(0, 0);
    printf("%d", ans);
    return 0;
}