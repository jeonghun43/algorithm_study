// 2751 수 정렬하기 2 merge_sort이용
#include <stdio.h>
int n;
int arr[1000005];
int tmp[1000005];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st, b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = arr[b++];
        else if(b == en)    tmp[i] = arr[a++];
        else if(arr[a] > arr[b])    tmp[i] = arr[b++];
        else    tmp[i] = arr[a++];
    }
    for(int i = st; i < en; i++){
        arr[i] = tmp[i];
    }
}
void merge_sort(int st, int en){
    if(en - st == 1)    return;
    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    merge_sort(0, n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}