// 5437 dividing the Loot
// 개수는 똑같이 가면서, 최대값을 가지도록 해야함
#include <stdio.h>
int t, p, n;
int arr[1005];
void sort(){
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t-- > 0){
        int ans = 0;
        scanf("%d %d", &p, &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        sort();
        int all = n / (p+1);
        for(int i = 0; i < all; i++){
            ans += arr[n-1-i];
        }
        printf("%d\n", ans);
    }
    return 0;
}