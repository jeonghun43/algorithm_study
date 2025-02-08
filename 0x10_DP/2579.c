// 2579 계단 오르기
#include <stdio.h>
int d[305][2];
int n;
int score[305];
int max(int x, int y){
    if(x > y) return x;
    return y;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &score[i]);
    
    d[0][0] = 0;    d[0][1] = 0;
    d[1][0] = score[1]; d[1][1] = score[1];
    d[2][0] = score[2]; d[2][1] = score[1] + score[2];

    // for(int i = 3; i <= n; i++){ //이거랑 아래 방법 둘 다 맞네.. 아래꺼 제출했을때 틀렸던건 print할때 max 빼먹어서 요런(휴대폰에서 제출하느라 빼먹었음)
    //     d[i][0] = score[i] + max(d[i-2][0], d[i-2][1]);
    //     d[i][1] = score[i] + d[i-1][0];
    // }

    for(int i = 3; i <= n; i++){
        d[i][0] = score[i] + max(d[i-2][0], d[i-2][1]);
        d[i][1] = score[i] + score[i-1] + max(d[i-3][0], d[i-3][1]);
    }

    printf("%d", max(d[n][0], d[n][1]));
    return 0;
}