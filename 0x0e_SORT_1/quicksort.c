#include <stdio.h>
int n;
int arr[100];
void swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void quick_sort(int st, int en){
    if(en - st <= 1) return;
    int pivot = arr[st];
    int l = st+1, r = en-1;
    while(1){
        while(l <= r && pivot >= arr[l]) l++;
        while(l <= r && pivot <= arr[r]) r--;
        if(l >= r) break;
        swap(l, r);
    }
    swap(st, r);
    quick_sort(st, r);
    quick_sort(r+1, en);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(0, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
// // quick sort
// #include <stdio.h>
// int n = 8;
// int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};
// void swap(int a, int b){
//     int tmp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = tmp;
// }
// void quick_sort(int st, int en){
//     if(en-st <= 1) return;      //en-st == 0인 경우도 고려해줘야함
//     int pivot = arr[st];
//     int l = st+1, r = en-1;
//     while(l < r){
//         while(l <= r && pivot >= arr[l]){   //l<=r 범위를 벗어나서 계속 연산될 수 있기 때문에 제한을 둠
//             l++;
//         }   
//         while(l <= r && pivot <= arr[r]){
//             r--;
//         }   
//         if(l > r){
//             swap(r, st);
//             break;
//         }
//         swap(l, r);
//     }
//     quick_sort(st, r);      //현재 피봇의 위치는 r이기 때문에 r직전까지 quick_sort실행해주고 
//     quick_sort(r+1, en);        //현재 피봇의 위치는 r이기 때문에 r다음부터 quick_sort실행
// }
// int main(){
//     quick_sort(0, n);
//     for(int i = 0; i < n;i ++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }