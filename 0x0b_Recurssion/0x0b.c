#include <stdio.h>

 long int mypow(int a, int b, int m){
    if(b == 1)  return a % m;
    
    long int val = mypow(a, b/2, m);    // 이렇게 부를 생각조차 못했음
    
    val= val * val % m;    //나머지 계산을 계속 해줄 생각을 못했다. 마지막에 한 번만 해야하는줄
    if(b % 2 == 0)  return val;
    return a * val % m;        // 여기다가도 나머지 계산을 해줘야하는거였군 
}   

int main(){
    int A,B,C;
    scanf("%d %d %d", &A, &B, &C);

    long int ans = mypow(A, B, C);

    printf("%d", ans);

    return 0;
}