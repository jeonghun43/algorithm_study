// 15656 N과 M (7)
#include <stdio.h>
int ans[10];
int arr[10];
int N,M;
void sort(int * arr){
    int tmp;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
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
        ans[k] = arr[i];
        func(k+1);
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