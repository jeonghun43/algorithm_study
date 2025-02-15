// 6064 카잉달력
// 10 12 3 9 일때 33을 출력해야함
// 사실 이 문제는 
// 10으로 나눈 나머지가 3이면서
// 12로 나눈 나머지가 9인 값을 찾는 문제임

#include <stdio.h>
int t;
int m, n, x, y;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return a / gcd(a, b) * b;
}
int main(){ 
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &m, &n, &x, &y);
        int st = x;
        int en = lcm(m, n);
        if(x == m) x %= m;
        if(y == n) y %= n;
        int flag = 0;
        for(int i = st; i <= en; i = i+m){
            if(i % n == y){
                flag = 1;
                printf("%d\n", i);
                break;
            }
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}