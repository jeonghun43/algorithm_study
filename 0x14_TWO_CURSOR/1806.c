// 1806 부분합

// 부분합 최대 1억이므로 int 사용
// 연속된 수들의 부분합이 s이상 되는 것들중에서 가장 작은 길이 출력
// 없으면 0 출력
// N최대 10만, 시간복잡도 N^2은 안되고, NlogN정도면 가능
// 그냥 부분합이 아니라 "연속된 수들의 부분합" 이게 포인트!
// 연속된 수들의 부분합은 이중반복문으로 확인 가능함. 그럼 시간복잡도 n^2이라서 안되므로
// 투포인터(투커서) 이용해서 풀이

// 내 풀이에서는 en을 1로 둔 상태로 진행함.. 그렇게 하니까 틀렸음
// 바킹독 풀이에서는 en을 0으로 둔 상태로 진행함.. 맞았음

#include <stdio.h>
int n, s;
int arr[100005];
int tot;
int sum[100005];
int ans = 0x7fffffff;
int Min(int a, int b){
    if(a < b) return a;
    return b;
}
int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /////
    int en = 0;
    tot = arr[0];
    int flag = 0;
    for(int st = 0; st < n; st++){
        while(en < n && tot < s){
            en++;
            tot += arr[en];
        }
        if(en == n) break;
        flag = 1;
        ans = Min(ans, en-st+1);
        tot -= arr[st];
    }
    if(!flag) ans = 0;
    printf("%d", ans);
    ///////
    return 0;

    //틀렸떤 나의 풀이.. en을 0이아닌 1로 두고 시작했더니 en증가시켜주고 이러면서 틀렸음..
    // int en = 1;
    // int flag = 0;
    // for(int st = 0; st < n; st++){
    //     sum[st] = arr[st];
    //     if(st != 0) sum[st] = sum[st-1] - arr[st-1];
    //     while(en < n && sum[st] < s){ //범위안에 있고 
    //         sum[st] += arr[en];
    //         en++;
    //     }
    //     flag = 1;
    //     if(sum[st] >= s) //얘네는 한 번 고친거고 원래는 아래와 같았음음
    //         ans = Min(ans, en-st);
        // if(en == n) break;
        // flag = 1;
        // ans = Min(ans, en-st);
    // }
    // if(flag) printf("%d", ans);
    // else printf("0");
}