// 11047 동전 0
#include <stdio.h>
int n, k;
int arr[10];
int cnt = 0;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = n-1; i >=0; i--){
        if(arr[i] > k)  continue;//나는 이렇게 조건 걸고
        while(k >= arr[i]){ //반복문 했는데 바킹독은 또 킹의 방식대로 수행함...
            k -= arr[i];
            cnt++;
        }

        // 바킹독 형님의 풀이
    for(int i = n-1; i >= 0; i--){
        int ans = k;
        ans = k / arr[i]; //몫으로 접근하면 k값보다 큰 arr[]값에 대해서 몫이 0으로 갈테니까.
        k %= arr[i];      //훨씬 빠르고 간결하게 잘 동작하겠네요
    }
        //wow
        if(k == 0)  break;
    }
    printf("%d", cnt);
    return 0;
}