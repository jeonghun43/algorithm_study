// 15664 n과 m (10)
#include <stdio.h>
int n, m;
int arr[10005]; //입력받을 값을 저장하는 배열
int ans[10005]; //출력을 위해 값을 잠시 저장하는 정답 배열
int isused[10005];  //배열의 방문여부를 기록할 배열
void sort(){    // 배열 정렬해주는 함수
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
void func(int k){   // 재귀적으로 실행할 함수
    if(k == m){     // 값이 꽉 차면 출력
        for(int i = 0; i < m; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;     //base condition
    }
    int before = 0; //중복 값 출력을 막기 위해 임시로 값을 저장할 변수
    for(int i = 0; i < n; i++){
        if(isused[i])   continue;   //방문한 적 있다면 패스
        if(k != 0 && ans[k-1] > arr[i]) continue;   // 비내림차수인지 판단하는 조건. k가 0이 아닐때만 이라는 조건을 넣은 이유는 k가 0일때 ans[k-1]에서 오류 나기 때문임
        if(before == arr[i])    continue;   //중복 값 출력을 막음
        ans[k] = arr[i];    //정답 배열에 넣어주고
        isused[i] = 1;      //방문했다고 표시해주고
        before = ans[k];    //중복 값 출력을 막기위해 방금 넣은 값을 before에도 넣어주고
        func(k+1);          //재귀함수 호출..재귀적으로 수행
        isused[i] = 0;      //함수 종료되고 나왔으면 방금 봐준 그 값에 대해서 방문여부를 수정해줌. 방문 안했다고 바꿔주기
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort();
    func(0);
    return 0;
}


//정리
// N과 M 문제처럼 재귀적으로 봐줘야하는 경우..
// 중복을 허용하지 않는다를 구현할때, 2가지 방법 가능
// 첫번째 방법)
// isused[] 처럼 방문여부를 기록하는 배열을 이용해주는 방법
// 두번째 방법)
// 어쨋든 배열 값들을 크기 순으로 정렬해줄거고
// 마지막으로 확인한 값 그 다음부터 실행해주면
// 굳이 방문여부 확인 안 해도 방문 안 한 새로운 값부터 봐주게 됨
// 그리고 이렇게 해줘야 비내림차순에 대해서 따로 조건 안해줘도 알아서 됨