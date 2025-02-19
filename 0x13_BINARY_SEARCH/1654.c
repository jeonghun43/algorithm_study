// 1654 랜선 자르기

// 변수를 증가만하거나 감소만하는 함수로 나타낼 수 있을때
// 이분탐색을 통해서 답을 찾아낼 수 있음
// 최적화문제 -> 결정문제로 바꿔서 불때 이분탐색활용가능
// 랜선 길이의 최대값을 묻는 문제에서
// 랜선 길이가 이렇게 일때 N개 이상 만들어 낼 수 있는가
// 이렇게로 바꿔서 풀 수 있는때 이때 이분탐색활용하면 된다

// k, n
// 랜선 길이 최대 2^31-1
#include <stdio.h>
int k, n;
int arr[10001];
//이분탐색 함수
void func(int n){
    long long int st = 1;
    long long int en = 2147483647;
    while(st < en){ 
        long long int mid = (st+en+1) / 2;  // st+en 할때 int 범위 벗어날 수도 있으니 long...
        long long int cut = 0; // Long으로 해야하는군..
        for(int i = 0; i < k; i++){
            cut += arr[i] / mid;
        }
        if(cut >= n) st = mid;
        else    en = mid-1;      
    }
    printf("%lld", st);
    
}
int main(){
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++){
        scanf("%d", &arr[i]);
    }
    func(n);
    return 0;
}