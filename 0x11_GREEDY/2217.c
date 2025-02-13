// 2217 로프
#include <stdio.h>
int n;
int d[100005];
int tmp[100005];
int ans = 0;
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = d[b++];
        else if(b == en)    tmp[i] = d[a++];
        else if(d[a] <= d[b]) tmp[i] = d[a++];
        else    tmp[i] = d[b++];
    }
    for(int i = st; i < en; i++){
        d[i] = tmp[i];
    }
}
void mergesort(int st, int en){
    if(en - st == 1)    return;
    int mid = (st+en) / 2;
    mergesort(st, mid);
    mergesort(mid, en);
    merge(st, en);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    mergesort(0, n);
    for(int i = 0; i < n; i++){
        if(d[i] * (n-i) > ans){
            ans = d[i] * (n-i);
        }
    }
    printf("%d", ans);
    return 0;
}