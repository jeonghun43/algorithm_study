// 15650 N과 M(2)
#include <stdio.h>
int N, M;
int arr[10];
int ischeck[10];
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    for(int i = 1; i <= N; i++){
        if(ischeck[i] || arr[k-1] > i) continue;
        arr[k] = i;
        ischeck[i] = 1; 
        func(k+1);
        ischeck[i] = 0;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    func(0);
    return 0;
}