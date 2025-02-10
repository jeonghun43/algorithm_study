// 2193 이친수
// 접근 좋았고, 90자리까지 해서 그 경우의 수를 다 더해주는거잖아
// 그래서 그 개수가 int 범위를 벗어난다는 것을 알아야하는 문제..
// 그냥 int로 했다가 틀렸는데 lonlong쓰니까 맞았음
#include <stdio.h>
int n;
long long int d[100][2];
int main(){
    scanf("%d", &n);
    d[1][0] = 0; d[1][1] = 1;
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][0]; 
        d[i][1] = d[i-1][0];
        d[i][0] += d[i-1][1];    
    }
    printf("%lld", d[n][0] + d[n][1]);
    return 0;
}