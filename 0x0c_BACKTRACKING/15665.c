// 15665 N과 M (11)
// 백트래킹
// 같은 숫자를 첫번째 자리에서도 쓰고 두번째자리에서도 사용해도됨
// 근데  1 7 9 9 있을때 19 19이렇게는 안됨
// 같은 수를 여러번 골라도는 되는데
// 중복되는 수열이면 안됨
#include <stdio.h>
int n, m;
int arr[10];
int ans[10];
void sort(){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
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
        //printf("in %d, this is %d\n", k, arr[i]);
        if(before == arr[i])    continue;
        ans[k] = arr[i];        //정답배열에 인덱스를 k로 줘야지.. i로 줘서 이상한 결과 나왔음ㅋㅋ 줴엔장~
        before = arr[i];
        func(k+1);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort();
    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    

    func(0);
    return 0;
}