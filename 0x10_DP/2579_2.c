// 2579 계단 오르기     다른풀이
//d[i]는 i일때 안 밟는 경우들의 합의 최솟값임 i값을 무조건 포함해서 안 밟음
#include <stdio.h>
int n;
int arr[305];
int d[305];
int tot = 0;
int min(int x, int y){
    if(x > y)   return y;
    return x;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        tot += arr[i];
    }
    if(n <= 2){
        printf("%d", tot);
        return 0;
    }
    d[1] = arr[1];
    d[2] = arr[2];
    d[3] = arr[3];
    for(int i = 4; i <= n; i++){    //여기서 굳이 n까지 안해줘도됨 왜냐면d[i]는 i까지 계단을 올라갔을때 안 밟은 계단의 합의 최솟값이기때문 + 무조건 i를 안 밟는걸로 함
                                    //그니까 반복문 조건을 i < n 이렇게만 해줘도 된다~
        d[i] = arr[i] + min(d[i-2], d[i-3]);
    }
    printf("%d", tot - min(d[n-1], d[n-2]));
    return 0;
}