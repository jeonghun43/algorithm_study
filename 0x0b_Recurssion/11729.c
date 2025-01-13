//11729 하노이탑
//왓더뻑입니다 근데 조금은 받아들여짐
#include <stdio.h>
void hanoi(int a, int b, int n){
    if(n == 1){
      printf("%d %d\n", a, b);
      return;
    }

    hanoi(a, 6-a-b, n-1);
    printf("%d %d\n", a, b);
    hanoi(6-a-b, b, n-1);
}

int main(){
    int N, cnt=2;
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        cnt *= 2;
    } 

    printf("%d\n", cnt-1);
    hanoi(1, 3, N);

    return 0;
}