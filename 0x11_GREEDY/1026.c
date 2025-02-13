// 1026 보물
#include <stdio.h>
int n;
int a[51];
int b[51];
int ans = 0;
void sortup(int tmp[]){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(tmp[i] > tmp[j]){
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }
}
void sortdown(int tmp[]){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(tmp[i] < tmp[j]){
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < n; i++){
        scanf("%d", &b[i]);
    }
    sortup(a);
    sortdown(b);
    for(int i = 0; i < n; i++){
        ans += a[i] * b[i];
    }
    printf("%d", ans);
    // printf("\n");
    // for(int i = 0 ; i < n; i++){
    //     printf("%d ", a[i]);
    // }printf("\n\n");
    // for(int i = 0 ; i < n; i++){
    //     printf("%d ", b[i]);
    // }printf("\n\n");
    return 0;
}