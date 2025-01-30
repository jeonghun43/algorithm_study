// 15666 N과M (12)
// 백트래킹으로 풀어야겠다
// 같은 수 여러번 골라도 되니까 isused[] 같이 확인해주는 배열은 따로 만들지 않음
// 비내림차순이어야 하기 때문에 조건 판단해주는 코드 있어야함
#include <stdio.h>
int n, m;
int arr[10];    // 입력받은 값들 저장할 배열
int ans[10];    // 정답값들 저장할 배열 
void sort(){
    int tmp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    int before = 0;
    for(int i = 0; i < n; i++){
        if((k != 0 && ans[k-1] > arr[i]) || before == arr[i]) continue;
        ans[k] = arr[i];
        before = ans[k];
        func(k+1);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort();
    func(0);
    return 0;
}