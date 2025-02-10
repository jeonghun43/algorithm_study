// 12852 1로 만들기 2
#include <stdio.h>
// 1로 만들는 경우의 최소값과
// 그 방법중 한 가지를 출력해야함
int x;
int d[1000005];
int pre[1000005];
int min(int x, int y){
    if(x > y) return y;
    return x;
}
int minidx(int x, int y){
    if(d[x] > d[y]) return y;
    return x;
}
int main(){
    scanf("%d", &x);
    d[1] = 0;
    for(int i = 2; i <= x; i++){
        d[i] = d[i-1] + 1;
        pre[i] = i-1;
        if(i % 3 == 0){
            d[i] = min(d[i/3]+1, d[i]);
            pre[i] = minidx(i/3, i-1);
        }
        if(i % 2 == 0){
            d[i] = min(d[i/2]+1, d[i]);
            pre[i] = minidx(i/2, pre[i]);
        }
    }
    int ans = d[x];
    printf("%d\n", ans);
    int a = pre[x];
    int idx = x;
    ans++;
    while(ans--){
        printf("%d ", idx); //인덱스를 출력하는 것이 곧 정답까지 가는 연산 과정을 보여주는 것
        idx = pre[idx];
    }
    return 0;
}