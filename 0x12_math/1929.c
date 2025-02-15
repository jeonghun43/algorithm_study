// 소수구하기 
// M 이상 N이하의 소수 모두 출력
// 1 <= M <= N <= 1,000,000
// 따라서 그냥 구현하는 것으로 하면 시간복잡도가
// O(N루트N)이기 대문에 1,000,000 * 1,000 = 10억
// 에라토스테네스의 체를 이용해서 풀겠음
#include <stdio.h>
int m, n;
int d[1000005];
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 2; i <= n; i++){
        d[i] = 1;
    }
    d[1] = 0;
    for(int i = 2; i*i <= n; i++){
        if(!d[i]) continue;
        for(int j = i*i; j <= n; j = j+i){
            d[j] = 0;
        }
    }
    for(int i = m; i <= n; i++){
        if(d[i])
            printf("%d\n", i);
    }
    return 0;
}