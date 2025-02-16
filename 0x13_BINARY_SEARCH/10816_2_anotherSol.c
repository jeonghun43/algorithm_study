// 10816 숫자카드2
// 어차피 해당 숫자가 몇개나 있는지 출력하는 문제임
// cnt배열 만들어서 들어오자마자 카운트 세주면
// 출력할때 바로 해당 인덱스 값 출력해주면 되잖아
// 되네요 ㅋㅎㅋ 오옝
#include <stdio.h>
int n, m;
int cnt[20000005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int idx;
        scanf("%d", &idx);
        idx += 10000000;  //음수값 들어올 수도 있으니 값 보정해주기
        cnt[idx]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int idx;
        scanf("%d", &idx);
        idx += 10000000;
        printf("%d ", cnt[idx]);
    }
    return 0;
}