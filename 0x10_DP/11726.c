// 11726 2 x n 타일링
#include <stdio.h>
int n;
int d[1005];
int main(){
    scanf("%d", &n);
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= n; i++){
        d[i] = d[i-2] + d[i-1]; 
        d[i] = d[i] % 10007; //10007로 나눈 나머지를 저장해줄수도 있고 아니면 이렇게 계산할 수도 있음
        // (a + b) mod n = ((a mod n) + (b + mod n)) mod n
        // 아까 틀렸던 코드의 경우.. 각각에 대해서 나머지 연산 수행후 더해주고나서 또 나머지 연산을 해줬어야했는데 그 부분을 안 했따!
    }
    printf("%d", d[n]);
    return 0;
}