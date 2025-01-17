// 14889 스타트와 링크
// umm 잠시보류
#include <stdio.h>
int arr[21][21];
int visit[21][21];
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j)  continue;
            if(visit[i][j] || visit[j][i])  continue;

            visit[i][j] = arr[i][j] + arr[j][i];
            visit[j][i] += visit[i][j];
        }
    }

    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            
        }
    }
//     printf("\n");
//     for(int i = 1; i <= N; i++){
//         for(int j = 1; j <= N; j++){
//             printf("%d ", visit[i][j]);
//         }
//         printf("\n");
//     }
    
    return 0;
}