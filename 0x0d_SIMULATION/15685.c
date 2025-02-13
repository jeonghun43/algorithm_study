// 15685 드래곤 커브

#include <stdio.h>
int n, x, y, d, g;
int arr[105][105];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;
int main(){
    scanf("%d", &n);

    while(n--){
        int dir[1050] = {};
        int idx = 0;
        scanf("%d %d %d %d", &y, &x, &d, &g);
        dir[idx++] = d;
        arr[x][y] = 1;

//이 부분이 너무 어려웠음
//머릿속으로는 떠오르지만 구현을 어떻게 해야할지 감이 안잡혀서 보면서 함
        for(int i = 0; i < g; i++){
            int len = idx;
            for(int j = len-1; j >= 0; j--){
                dir[idx++] = (dir[j] + 1) % 4;
            }
        }


        for(int i = 0; i < idx; i++){
            y += dy[dir[i]];    //x좌표 나타냄
            x += dx[dir[i]];    //y좌표 나타냄
            arr[x][y] = 1;
        }
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]){
                ans++;
            }
        }
    }
    printf("%d", ans);
    //첨엔 이렇게 떠올렸지만 다른 방식으로 접근했음
    //tmp배열에 정상적인 친구들 먼저 넣고
    //tmp배열을 거꾸로 참조하면서 +1 해준값을 tmp에 추가해주면서
    //해당하는 방향에 대해 수행해줌

    return 0;
}