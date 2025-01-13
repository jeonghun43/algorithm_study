#include <stdio.h>

 int pow(int a, int b, int m){
    int ans=1;
    while(b--){ 
        ans = ans * a % m;  
        /// 나머지 계산을 계속 해줄 생각을 못했다. 마지막에 한 번만 해야하는줄
    }
    return ans;
}   

int main(){
    int A,B,C;
    scanf("%d %d %d", &A, &B, &C);

    int ans = pow(A, B, C);

    printf("%d", ans);

    return 0;
}