// Greatest Common Divisor 최대공약수 구하기
// 유클리드 호제법 이용
#include <stdio.h>
int a, b;
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}
int main(){
    scanf("%d %d", &a, &b);
    printf("gcd is %d\n", gcd(a, b));
    return 0;   
}