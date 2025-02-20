// 2230 수 고르기

// 투포인터 문제들은 이분탐색으로도 풀리고,
// 이분탐색 문제들은 투포인터로도 풀린다
// 두 수의 차이가 M이상인 것들중에 최소값을 출력하는 문제
// 두 수의 차이가 20억까지 될 수 있으므로 int 사용해도 됨
// int 범위 약 -21억~ 21억
// 두가지 풀이방법 
// 방법1 : 두 수의 차이에 대한 수열 만들고, 이분탐색 수행 lower_bound 계산
// 방법2 : 투포인터(두개의커서) 이용하여 이중반복문의 시간복잡도를 획기적으로 줄이기.. 배열 정렬 필수!

#include <stdio.h>
int n,m;
int st=0, en=0;
int ans = 0x7fffffff;   //int 범위내에서의 최댓값
int a[100005];
int tmp[100005];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int aa = st;
    int bb = mid;
    for(int i = st; i < en; i++){
        if(aa == mid) tmp[i] = a[bb++];
        else if(bb == en) tmp[i] = a[aa++];
        else if(a[aa] <= a[bb]) tmp[i] = a[aa++];
        else tmp[i] = a[bb++];
    }
    for(int i = st; i < en; i++){
        a[i] = tmp[i];
    }
}
void mergesort(int st, int en){
    int mid = (st+en) / 2;
    if(en - st == 1) return;
    mergesort(st, mid);
    mergesort(mid, en);
    merge(st, en);
}
int Min(int x, int y){
    if(x < y) return x;
    return y;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(0, n);
    for(int st = 0; st < n; st++){
        while(a[en] - a[st] < m && en < n-1){ //차이가 M 이상 될때까지 반복. 범위 내에서
            en++;
        }
        if(a[en] - a[st] >= m){
            ans = Min(ans, a[en] - a[st]);
        }


        //위 while문과 if문을 이렇게 쓸수도있음
        //바킹독의 정답코드
        for(int st = 0; st < n; st++){
            while(en < n && a[en] - a[st] < m){
                en++;
            }
            if(en == n) break;
            ans = Min(ans, a[en] - a[st]);
        }

    }
    printf("%d", ans);
    return 0;
}