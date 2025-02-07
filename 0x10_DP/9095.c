// 9095 1, 2, 3 더하기
#include <stdio.h>
int t, n;
int d[15];
int main(){
    scanf("%d", &t);
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
        for(int i = 4; i <= 11; i++){    //한 번만 수행해주면 나중에 답만 꺼내올 수 있음
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
    while(t--){
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
    return 0;
}