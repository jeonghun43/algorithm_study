// 약수 구하기
#include <stdio.h>
int n;
int idx = 0;
int arr[20];
int main(){
    scanf("%d", &n);
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0) arr[idx++] = i;
    }
    int size = idx;
    for(int i = size-1; i >= 0; i--){
        if(arr[i] * arr[i] == n)    continue;
        arr[idx++] = n / arr[i];
    }


    printf("\n");
    for(int i = 0; i < idx; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}