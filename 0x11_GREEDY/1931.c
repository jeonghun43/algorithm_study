//1931 회의실 배정
//n최대값이 100,000 이라서 시간복잡도 n^2이면 시간초과남 정렬할때 버블썼어서 처음엔 시간초과났었음 
//합병정렬은 nlonN 안에 정렬 가능하고, 구조체의 정렬까지도 가능함
// mergesort 다시 구현 연습해보자
#include <stdio.h>
#include <stdlib.h>
struct data{
    int st;
    int en;
};
int n;
struct data d[100005];
struct data tmp[100005];
void merge(int st, int en){
    int mid = (st + en) / 2;
    int a = st; int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = d[b++];
        else if(b == en)    tmp[i] = d[a++];
        else if(d[a].en <= d[b].en) tmp[i] = d[a++];
        else tmp[i] = d[b++];
    }

    for(int i = st; i < en; i++){
        d[i] = tmp[i];
    }
}
void mergesort(int st, int en){
    if(en - st == 1) return;
    int mid = (st + en) / 2; 
    mergesort(st, mid);
    mergesort(mid, en);
    merge(st, en);
}

void merge2(int st, int en){
    int mid = (st + en) / 2;
    int a = st; int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = d[b++];
        else if(b == en)    tmp[i] = d[a++];
        else if(d[a].st <= d[b].st) tmp[i] = d[a++];
        else tmp[i] = d[b++];
    }

    for(int i = st; i < en; i++){
        d[i] = tmp[i];
    }
}
void mergesort2(int st, int en){
    if(en - st == 1) return;
    int mid = (st + en) / 2; 
    mergesort2(st, mid);
    mergesort2(mid, en);
    merge2(st, en);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &d[i].st, &d[i].en);
    }
    //정렬수행
    mergesort2(0, n);
    mergesort(0, n);

    //c
    // printf("\n\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d %d\n", d[i].st, d[i].en);
    // }
    // printf("\n\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d %d\n", d[i].st, d[i].en);
    // }
    //c

    int cnt = 0;
    int en = 0;
    for(int i = 0; i < n; i++){
        if(en > d[i].st)
            continue;
        else{
            cnt++;
            en = d[i].en;
        }
    }
    printf("%d", cnt);
    return 0;
}