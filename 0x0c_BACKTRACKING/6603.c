// 6603 로또
// 백트래킹
// k 7개~12개 재귀를 12번..? 감당가능한건가
// 
#include <stdio.h>
int arr[15];
int isused[15];
int ans[15];
int k;
void func(int n){
    if(n == 6){     //base condition
        for(int i = 0; i < 6; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return; 
    }

    for(int i = 0; i < k; i++){
        if(isused[i] ||( n != 0 && ans[n-1] > arr[i]))   continue;   //사용한적 있거나 비내림차순에 위배되면 패스
        isused[i] = 1;  //사용했다고 표시
        ans[n] = arr[i];//답에 값 넣어줌
        func(n+1);
        isused[i] = 0;
    }
}
int main(){
    while(1){
        scanf("%d", &k);
        if(k == 0)  return 0;
        
        for(int i = 0; i < k; i++){
            scanf("%d", &arr[i]);
        }

        func(0);
        for(int i = 0; i < k; i++){
            isused[i] = 0;
        }
        printf("\n");
    }
}