// 10816 숫자카드2
// n m 최대 50만
// 따라서 그냥 선형적으로 탐색하면
// 50만 * 50만 이라서 1초 넘어가버림
// NlongN 안에 끝나는 로직으로 가야함
// 정렬도 합병정렬같이 O(NlonN)인 정렬 사용해야함
// 이분탐색활용
#include <stdio.h>
int n, m;
int dn[500001];
int dm[500001];
int tmp[500001];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = dn[b++];
        else if(b == en)    tmp[i] = dn[a++];
        else if(dn[a] <= dn[b]) tmp[i] = dn[a++];
        else    tmp[i] = dn[b++];
    }
    for(int i = st; i < en; i++){
        dn[i] = tmp[i];
    }
}
void mergeSort(int st, int en){
    if(en -  st == 1) return;
    int mid = (st+en)/2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}
int funcleft(int x){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st+en) / 2;
        if(x > dn[mid]) st = mid+1;
        else if(x <= dn[mid]) en = mid;
    }
    return st;
}
int funcright(int x){
    int st = 0;
    int en = n;
    while(st < en){
        int mid = (st+en) / 2;
        if(x >= dn[mid]) st = mid+1;
        else if(x < dn[mid]) en = mid;
    }
    return st;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &dn[i]);
    }
    mergeSort(0, n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &dm[i]);
    }

    for(int i = 0; i < m; i++){
        int leftidx = funcleft(dm[i]);
        int rightidx = funcright(dm[i]);
        printf("%d ", rightidx - leftidx);
    }
    return 0;
}