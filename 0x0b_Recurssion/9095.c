// 9095 1,2,3 더하기
#include <stdio.h>
int ans[11];

int solve(int n){
    if(n == 0) return 1;                // 0일때는 1 반환
    if(n == 2 || n == 1) return n;      // 1 2일때는 해당 값을 반환. 왜냐면
                                        // 1 2 까지는 아직 규칙이 없기때문
    
    //함수 재호출을 방지하기 위한 필사의 몸부림
    if(ans[n-1] == 0)   ans[n-1] = solve(n-1);  // ans배열에 값이 비어있을때만 함수 호출해주고
    if(ans[n-2] == 0)   ans[n-2] = solve(n-2);  // 호출해준 값은 배열에 잘 넣어주는거지
    if(ans[n-3] == 0)   ans[n-3] = solve(n-3);  // 비어있지 않으면 그 값을 그냥 써버려 불필요한 함수는 호출하지 않는다
    return ans[n-1] + ans[n-2] + ans[n-3];
}

int main(){
    int T,
     tmp;
    scanf("%d", &T);

    while(T-- > 0){
        scanf("%d", &tmp);
        printf("%d\n", solve(tmp));
    }
    return 0;
}

// // 9095 1,2,3 더하기
// #include <stdio.h>
// int solve(int n){
//     if(n == 0) return 1;                // 0일때는 1 반환
//     if(n == 2 || n == 1) return n;      // 1 2일때는 해당 값을 반환. 왜냐면
//                                         // 1 2 까지는 아직 규칙이 없기때문

//     return solve(n-1) + solve(n-2) + solve(n-3); // 값들을 다 구해보면 f(n) = f(n-1) + f(n-2) + f(n-3) 이라는 점화식이 나오게됨..
//     //시간복잡도는 안녕한가.
//     //함수 하나에 대해서 하나씩 풀어서 시간복잡도 계산할 수는 있는데 
//     //빅오표기볍으로는 어케 씀
//     //찾아보니 뭐 머리터지는 것들만 나옴
// }

// int main(){
//     int T,
//      tmp;
//     scanf("%d", &T);

//     while(T-- > 0){
//         scanf("%d", &tmp);
//         printf("%d\n", solve(tmp));
//     }
//     return 0;
// }