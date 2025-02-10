// 11055 바킹독 풀이처럼 해결해봄
#include <stdio.h>
int n;
int ans = 0;
int arr[1005];
int d[1005];
int max(int x, int y){
    if(x > y)   return x;
    return y;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        d[i] = arr[i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j])
                d[i] = max(d[j] + arr[i], d[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] > ans)  ans = d[i];
    }
    printf("%d", ans);
    return 0;
}