// 1978 소수찾기
#include <stdio.h>
int n;
int cnt = 0;
int isprime(int x){
    if(x == 1) return 0;
    for(int i = 2; i*i <= x; i++){  // 이걸 아무생각없이 n으로해서 틀림ㅋㅋ
        if(x % i == 0){
            return 0;
        }  
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        if(isprime(x)){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}