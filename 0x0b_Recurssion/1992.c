//1992 쿼드트리
// 재귀
// 숫자 하나로만 이루어져 있으면 패스
// 그게아니라면 1,2,3,4분면을 나눠서 진행하는 형식
// n
// board[100][100]
#include <stdio.h>
int n;
char board[100][100];
void func(int x, int y, int k){
    if(k == 1){
        printf("%c",board[x][y]);
        return;
    }
    char tmp = board[x][y];
    int issame = 1;
    for(int i = x; i < x + k; i++){
        for(int j = y; j < y + k; j++){
            if(tmp != board[i][j]){
                issame = 0;
                i = x + k;
                break;
            }
        }
    }
    //여기서부터
    // printf("check yeah\n");
    //  for(int i = x; i < x + k; i++){
    //     for(int j = y; j < y + k; j++){
    //         printf("%c ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    //여기까지 체크 

    if(issame){ //전부 같은 숫자라면
        printf("%c", board[x][y]);  //출력하고
        return; //종료
    }
    printf("(");
    func(x, y, k / 2);  //1사분면
    func(x, y+k/2, k / 2);  //2사분면
    func(x+k/2, y, k / 2);  //3사분면
    func(x+k/2, y+k/2, k / 2);  //4사분면
    printf(")");
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", &board[i]);


//check
// printf("umm\n");
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             printf("%c", board[i][j]);
//         }
//         printf("\n");
//     }
//check
    func(0,0,n);
    return 0;
}
