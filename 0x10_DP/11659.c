// 11659 구간 합 구하기 4
// 테이블 정의 : d[i]는 i일때 1부터 i까지의 합
#include <stdio.h>
int n, m;
int arr[100005];
int tot[100005];
int main(){
    scanf("%d %d", &n, &m);
    tot[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        tot[i] = arr[i] + tot[i-1];
    }
    for(int re = 0; re < m; re++){  //ㅋㅋ바본가 m번 반복하게 해야하는데 예제만 보고 3번만 반복하게 했네
        int i, j;
        scanf("%d %d", &i, &j);
        int ans;
        if(i == j)  ans = arr[i];
        else ans = tot[j] - tot[i-1];

        //연산 다른 방법
        //tot[j] - tot[i-1] + arr[i]

        printf("%d\n", ans);
    }
    return 0;
}