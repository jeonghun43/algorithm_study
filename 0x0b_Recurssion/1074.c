//1074 Z
#include <stdio.h>
int z(int N, int r, int c){
    if(N == 0) return 0;

    int half = (1 << N-1);

    if( half > r && half > c ) return z(N-1, r, c);                         //1번사각형일때
    else if(half > r && c >= half) return  half * half + z(N-1, r, c-half);      //2번사각형일때
    else if(r >= half && half > c)  return 2 * half * half + z(N-1, r-half, c);  //3번사각형일때
    else if(r >= half && c >= half) return 3 * half * half + z(N-1, r-half, c-half);  //4번사각형일때
}

int main(){
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    int ans = z(N, r, c);
    printf("%d", ans);
    return 0;
}