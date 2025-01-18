// 15650 N과 M(5)
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
        return;
    }

    for(int i = 0; i < N; i++){
        if(isused[i+1])   continue;
        ans[k] = arr[i];
        isused[i+1] = 1;
        func(k+1);
        isused[i+1] = 0;
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

    // 디버깅용
    // printf("\n");
    // for(int i = 0; i < N; i++){
    //     printf("%d ", arr[i]);
    // }