// 15663 n과 m (9)

// 모든 경우의 수를 돌아봐야하므로 백트래킹 알고리즘 사용 = 재귀적으로 풀겠다
// n : 자연수 총 개수, m : 몇개짜리 보여줄건지, 
// arr[] : 입력받은 배열 저장,  ans[] : 출력할 배열임
// 수가 중복되서 들어올 수도 있음
// 출력할때는 중복 수열은 제외 + 오름차순

#include <stdio.h>
int n, m;
int arr[20];
int ans[20];
int isused[20];
int cnt[10005];
//오름차순으로 출력해야하니 일단 입력받은 배열 정렬해주겠음
//정훈정렬 실행
void sort(){
    int tmp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j ++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//풀이의 핵심인 재귀함수 구현
void func(int cur){
    if(cur == m){   // 꽉 채워져있으면 출력 하면서 재귀 종료
        for(int i = 0; i < m; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");

        // 9 9 처럼 9 두개일때 일의 자리에 9가 들어오고 꽉 채워져있으면
        // 9 중복 출력을 방지하기 위해 다른 9에도 isused = 1 해주고 싶음
        // if(cnt[ans[cur-1]] > 1){        //인덱스 실수했었다 cur-1 인데 cur라고 썼었네;; 어쩐지 계속 값 확인해보는데 0나오더라
        //     tmp = cnt[ans[cur-1]]-1;
        // }
        return;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++){         // dk tlqkf 얘 범위를 왜 m으로 해놨어 이 바보야 전체 배열에 대해서 돌려줘야할꺼야녀
        if(isused[i] || tmp == arr[i]){   
            continue;
            }
        // if(tmp && arr[i-1] == arr[i]){
        //     tmp--;
        //     continue;
        // }
        isused[i] = 1;
        tmp = arr[i];
        ans[cur] = arr[i];
        func(cur+1);
        isused[i] = 0;
    }
}
int main(){
    scanf("%d %d", &n, &m);         //n m 입력받고
    for(int i = 0; i < n; i++){     //n개 숫자 입력받고
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    sort();                         //정렬 때리고
    func(0);
    return 0;
}