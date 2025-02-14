// 1799 비숍
// 재귀
// 퀸문제에서 했듯이 
// 1행에 퀸을 놓는다면 해당 행에는 또 퀸을 놓을 수 없음
// 이와 마찬가지로 비숍에서는 대각선에 놓으면 해당 대각선에는 놓을 수 없음
#include <stdio.h>
int n;
int board[15][15];
int ans = 0;
int checkRightUp[20];
int checkRightDown[20];
void func(int k, int cnt){
    if(k == (2*n) - 1){
        //printf("in k %d %d\n", k, cnt);
        if(cnt > ans){
            ans = cnt;

        }
        return;
    }

    // for(int a = k; a < 2*n - 1; a++){
    //     int i = a;
    //     int j = 0;
    //     if(i >= n){
    //         j = i - n;
    //         i = n-1;
    //     }
    //     i++; j--;

    //     for(int b = 0; b < n; b++){
    //         i--;
    //         j++;
    //         if(i < 0 || j >= n)   break;
    //         if(board[i][j] == 0)    continue;
    //         if(checkRightDown[i-j+n-1] || checkRightUp[i+j])  continue;
    //         checkRightDown[i-j+n-1] = 1;
    //         checkRightUp[i+j] = 1;
    //         printf("%d (%d , %d)\n",k , j, i);
    //         func(i+j+1);
    //         checkRightDown[i-j+n-1] = 0;
    //         checkRightUp[i+j] = 0;
    //     }
    // }

    int flag = 0;
    for(int a = 0; a < n; a++){
        int i = k;
        int j = 0;
        if(i >= n){
            i = n-1;
            j = k - n + 1;
        }  
        i -= a;
        j += a;
        if(i < 0 || j >= n) break;
        if(board[i][j] == 0)    continue;
        if(checkRightDown[i-j+n-1] || checkRightUp[i+j])  continue;
        flag = 1;
        checkRightDown[i-j+n-1] = 1;
        checkRightUp[i+j] = 1;
        func(k+1, cnt+1);
        checkRightDown[i-j+n-1] = 0;
        checkRightUp[i+j] = 0;
    }  
    if(!flag) func(k+1, cnt); 


//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(i+j < k)    continue;
//             if(board[i][j] == 0)    continue;
//             if(checkRightDown[i-j+n-1] || checkRightUp[i+j])  continue;
//             checkRightDown[i-j+n-1] = 1;
//             checkRightUp[i+j] = 1;

// //c
//          //   printf("%d (%d , %d)\n",k , j, i);
// //c

//             func(i+j+1);
//             checkRightDown[i-j+n-1] = 0;
//             checkRightUp[i+j] = 0;
//         }
//     }
    

}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
        }
    }

    func(0, 0);
    printf("%d", ans);
    return 0;
}