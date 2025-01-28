#include <stdio.h>
int n = 10;
int arr[10000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[10000001];
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
    merge_sort(0, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
// // merge sort
// #include <stdio.h>
// int n = 10;
// int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
// int tmp[1000001];
// void merge(int st, int en){
//     int mid = (st+en) / 2;
//     int a=st, b=mid;
//     for(int i = st; i < en; i++){
//         if(a >= mid){
//             tmp[i] = arr[b++];
//             continue;
//         }
//         if(b >=  en){
//             tmp[i] = arr[a++];
//             continue;
//         }
//         if(arr[a] > arr[b]){
//             tmp[i] = arr[b++];
//         }
//         else{
//             tmp[i] = arr[a++];
//         }
//     }
//     for(int i = st; i < en; i++){
//         arr[i] = tmp[i];
//     }
// }
// void mergesort(int st, int en){
//     if(en - st <= 1)    return;
//     int mid = (st+en) / 2;
//     mergesort(st, mid);
//     mergesort(mid, en);
//     merge(st, en);
// }
// int main(){
//     mergesort(0, n);
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }