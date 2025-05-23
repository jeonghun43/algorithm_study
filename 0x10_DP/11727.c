// 11727 2 x n 타일링2
#include <stdio.h>
long long d[1005];
int n;
int main(){
    scanf("%d", &n);
    d[1] = 1;
    d[2] = 3;
    for(int i = 3; i <= n; i++){
        d[i] += d[i-1] % 10007;
        d[i] += (d[i-2] * 2) % 10007;
        d[i] %= 10007;
    }
    printf("%d", d[n]);
}

//접근방법 
//2 x n 공간중에서 가장 왼쪽 윗칸에 집중합니다
//그 칸에서 가능한 경우 중에서 2 x 1타일을 놓는다고 한다면
//남은 공간은 d[i-1] 일 것입니다
//또한 그 칸에서 가능한 경우 중에서 1 x 2 혹은 2 x 2타일을 놓는다고 한다면
//남은 공간은 d[i-2] 일 것이기 때문에
//점화식은 d[i-1] + 2 * d[i-2] 라고 세울 수 있고
//초기값은 d[1] 과 d[2] 에 대해 정의 해주면 됩니다 끝!