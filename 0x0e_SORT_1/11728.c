// 11728 배열 합치기
#include <stdio.h>
int n, m;
int aidx=0, bidx=0, ansidx=0;
int a[1000005];
int b[1000005];
int ans[2000005];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n+m; i++){
        if(aidx >= n){
            ans[ansidx++] = b[bidx++];
            continue;
        }
        if(bidx >= m){
            ans[ansidx++] = a[aidx++];
            continue;
        }
        if(a[aidx] > b[bidx]){
            ans[ansidx++] = b[bidx++];
        }else{
            ans[ansidx++] = a[aidx++];
        }
    }
    for(int i = 0; i < n+m; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
