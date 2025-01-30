// N과 M(8)
#include <stdio.h>
int n, m;
int arr[10];
int ans[10];
void sort(){
    int tmp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < n; i++){
        if(k != 0 && ans[k-1] > arr[i])  continue;
        ans[k] = arr[i];
        func(k+1);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort();
    func(0);
    return 0;
}