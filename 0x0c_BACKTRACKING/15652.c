// 15650 N과 M(4)   비내림차순이라는게 뭐....지 크거나 같은거라는데 
//음? 아 그러네 무조건 전에 있는 배열의 값보다 크거나 같아야함
#include <stdio.h>
int N, M;
int arr[10];
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int st = 1;
    if(k != 0)  st = arr[k-1];
    for(int i = st; i <= N; i++){
        arr[k] = i;
        func(k+1);
    }
}
int main(){
    scanf("%d %d", &N, &M);
    func(0);
    return 0;
}