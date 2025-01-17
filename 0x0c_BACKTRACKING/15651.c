// 15650 N과 M(3)
#include <stdio.h>
int N,M;
int arr[10];
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= N; i++){
        arr[k] = i;
        func(k+1);
    }
}
int main(){
    scanf("%d %d", &N, &M);
    func(0);
}