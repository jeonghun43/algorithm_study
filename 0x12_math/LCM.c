// Least Common Multiple 최소공배수 구하기
// GCD를 이용해서 구함
// a * b = GCD(a, b) * LCM(a, b) 를 이용
// LCM(a,b) = a * b / GCD(a,b)
// 근데 코드로 구현할때는 a b곱해준다음에 GCD를 나누는것이 아니라
// 먼저 나눠줄거야
// 왜냐하면 a랑b 곱했을때 int overflow가 발생할수도 있기 때문!
#include <stdio.h>
int a, b;
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}
int lcm(int x, int y){
    return x / gcd(x, y) * y;
}
int main(){
    scanf("%d %d", &a, &b);
    printf("LCM is %d\n", lcm(a, b));
    return 0;
}