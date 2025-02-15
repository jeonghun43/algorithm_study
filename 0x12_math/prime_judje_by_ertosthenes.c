// 소수 판별법 에라토스테네스의 체
// N길이의 1차원 배열을 만든다
// 1은 소수가 아니므로 false
// 다음 값을 참조해봤을때
// true라면 그 수의 배수들을 false로 바꾼다
// 끝까지 반복
#include <stdio.h>
int n;
int d[100];
int main(){
    scanf("%d", &n);
    d[1] = 0;

    for(int i = 2; i <= n; i++){
        d[i] = 1;
    }

    for(int i = 2; i <= n; i++){
        //printf("here is in %d\n", i);
        if(!d[i])    continue;
        for(int j = i*i; j <= n; j = j+i){
            //printf("here is in %d and %d\n", i, j);
            d[j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d ", d[i]);
    }
    return 0;
}