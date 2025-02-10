// 1003 피보나치 함수
#include <stdio.h>
int t;
int d[45][2];
int main(){
    scanf("%d", &t);
    d[0][0] = 1; d[0][1] = 0;
    d[1][0] = 0; d[1][1] = 1;
    while(t--){
        int tmp;
        scanf("%d", &tmp);
        for(int i = 2; i <= tmp; i++){
            d[i][0] = d[i-1][0] + d[i-2][0];
            d[i][1] = d[i-1][1] + d[i-2][1];
        }
        //그냥 1차원 배열로 해도 됐을듯..? 아닌가 더 고민 필요
        printf("%d %d\n", d[tmp][0], d[tmp][1]);
    }
    return 0;
}