// 15649 N과 M(1)                   ... 백트래킹
#include <stdio.h>
int arr[10];
int ischeck[10];
int N,M;
void func(int k){   // 현재 k개까지 선택했음. 이걸 생각 못해줬었다
    if(k == M) {
        for(int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= N; i++){
        if(ischeck[i] == 1) continue;   //와 사용했는지 여부를 판단하기 위해서 bool 배열 만들어줘버려.. 나는 숫자들을 리스트에 넣어가지고 사용했다면 그 숫자를 빼고 이렇게 할 거를 생각했었는데 이게 훨씬 간단하네
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