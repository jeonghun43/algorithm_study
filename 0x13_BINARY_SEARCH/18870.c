// 18870 좌표압축
// 해당 값보다 작은 값들이 몇개 있는지 출력하는 문제
// N : 1,000,000 백만이하이고
// x : -10억~10억 사이임
// 우선 합병정렬해주고, 중복 제거 해준다음
// 이분탐색 진행해서 해당 값의 인덱스를 반환
// 그 인덱스 값 = 해당 값보다 작은 값들의 개수
#include <stdio.h>
int n;
int newsize;
int arr[1000001];
int board[1000001];
int tmp[1000001];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = arr[b++];
        else if(b == en) tmp[i] = arr[a++];
        else if(arr[a] <= arr[b]) tmp[i] = arr[a++];
        else    tmp[i] = arr[b++];
    }
    for(int i = st; i < en; i++){
        arr[i] = tmp[i];
    }
}
void mergesort(int st, int en){
    int mid = (st+en) / 2;
    if(en - st == 1)    return;
    mergesort(st, mid);
    mergesort(mid, en);
    merge(st, en);
}
void removesame(){
    tmp[0] = arr[0];
    int idx = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] == tmp[idx-1])  continue;
        tmp[idx++] = arr[i];
    }
    newsize = idx;
    for(int i = 0; i < idx; i++){
        arr[i] = tmp[i];
    }
}
void func(int x){
    int st = 0;
    int en = newsize-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(arr[mid] == x){
            printf("%d\n", mid);
            return;
        }else if(arr[mid] > x) en = mid-1;
        else st = mid + 1;  
    }
    printf("0\n");
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        board[i] = arr[i];
    }
    mergesort(0,n);
    // for(int i = 0; i < n; i++){
    //     printf("%d ", arr[i]);
    // }printf("\n");
    removesame();
    // for(int i = 0; i < newsize; i++){
    //     printf("%d ", arr[i]);
    // }printf("\n");

    for(int i = 0; i < n; i++){
        func(board[i]);
    }
    return 0;
}