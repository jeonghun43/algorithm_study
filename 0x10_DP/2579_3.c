// 2579 계단오르기  다른풀이
//d[i]는 i까지 계단을 올랐을때 오른 계단의 합의 최댓값
#include <stdio.h>
int n;
int arr[305];
int d[305];
int max(int x, int y){
    if(x > y)   return x;
    return y;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){    //아무생각없이 0부터 받았었네 주의. 테이블 정의할때 이렇게 했었잖아. d[i]는 i까지 계단을 올랐을때 오른 계단의 합의 최댓값! 
        scanf("%d", &arr[i]);
    }
    d[1] = arr[1];
    d[2] = arr[1] + arr[2];
    d[3] = arr[3] + max(arr[1], arr[2]);
    for(int i = 4; i <= n; i++){
        d[i] = arr[i] + max(arr[i-1] + d[i-3], d[i-2]);
    }
    printf("%d", d[n]);
    return 0;
}