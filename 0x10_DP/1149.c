//1149 RGB거리
#include <stdio.h>
int n;
int arr[1001][3];
int d[1001][3];
int min(int x, int y){
    if(x > y)   return y;
    return x;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    d[1][0] = arr[1][0];
    d[1][1] = arr[1][1];
    d[1][2] = arr[1][2];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 3; j++){
            d[i][j] = arr[i][j] + min(d[i-1][(j+1) % 3], d[i-1][(j+2) % 3]);
        }
    }

    printf("%d", min(min(d[n][0], d[n][1]),d[n][2]));
    return 0;
}