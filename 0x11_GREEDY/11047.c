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
        if(arr[i] > k)  continue;
        while(k >= arr[i]){
            k -= arr[i];
            cnt++;
        }
        if(k == 0)  break;
    }
    printf("%d", cnt);
    return 0;
}