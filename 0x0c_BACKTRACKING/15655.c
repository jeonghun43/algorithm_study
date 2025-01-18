// 15650 N과 M(6)
#include <stdio.h>
int N, M;
int ans[10];
int arr[10];
int isused[10];
void sort(int* arr){
    int tmp;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(arr[i] > arr[j]){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        if(isused[i] || ans[k-1] > arr[i]) continue;
        ans[k] = arr[i];
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr);
    func(0);
    return 0;
}
