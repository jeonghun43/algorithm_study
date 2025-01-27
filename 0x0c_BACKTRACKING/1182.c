// 1182 부분수열의 합
#include <stdio.h>
int n, s;
int arr[25];
int cnt=0;
void func(int cur, int tot){
    if(cur == n){
        if(tot == s) cnt++;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot + arr[cur]);
}
int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    func(0,0);
    if(s==0)    cnt--;
    printf("%d", cnt);
    return 0;
}