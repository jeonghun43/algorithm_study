// 12100 2048(easy)
#include <stdio.h>
int n;
int max = 0;
int board[30][30];
void doright(int arr[][30]){
    int tmp[30][30] = {};
    for(int i = 0; i < n; i++){
        int before = -2;
        int tmpidx = n-1;
        for(int j = n-1; j >= 0; j--){
            if(arr[i][j] == 0)  continue;
            if(tmpidx == n-1){
                tmp[i][tmpidx--] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            if(tmp[i][tmpidx+1] != arr[i][j] || before != arr[i][j]){
                tmp[i][tmpidx--] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            tmp[i][tmpidx+1] += arr[i][j];
        }
    }
     for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
}
void dodown(int arr[][30]){
    int tmp[30][30] = {};
    for(int j = 0; j < n; j++){
        int before = -2;
        int tmpidx = n-1;
        for(int i = n-1; i >= 0; i--){
            if(arr[i][j] == 0)  continue;
            if(tmpidx == n-1){
                tmp[tmpidx--][j] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            if(tmp[tmpidx+1][j] != arr[i][j] || before != arr[i][j]){
                tmp[tmpidx--][j] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            tmp[tmpidx+1][j] += arr[i][j];
        }
    }
     for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
}
void doleft(int arr[][30]){
    int tmp[30][30] = {};
    for(int i = 0; i < n; i++){
        int before = -2;
        int tmpidx = 0;
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0)  continue;
            if(tmpidx == 0){
                tmp[i][tmpidx++] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            if(tmp[i][tmpidx-1] != arr[i][j] || before != arr[i][j]){
                tmp[i][tmpidx++] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            tmp[i][tmpidx-1] += arr[i][j];
        }
    }
     for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
}
void doup(int arr[][30]){
    int tmp[30][30] = {};
    for(int j = 0; j < n; j++){
        int before = -2;
        int tmpidx = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][j] == 0)  continue;
            if(tmpidx == 0){
                tmp[tmpidx++][j] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            if(tmp[tmpidx-1][j] != arr[i][j] || before != arr[i][j]){
                tmp[tmpidx++][j] = arr[i][j];
                before = arr[i][j];
                continue;
            }
            tmp[tmpidx-1][j] += arr[i][j];
        }
    }
     for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            arr[i][j] = tmp[i][j];
        }
}
void func(int arr[][30], int k){
    if(k == 5){
        for(int i = 0; i < n; i++)
            for(int j = 0; j  < n; j++)
                if(arr[i][j] > max) max = arr[i][j];

//cc
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j  < n; j++){
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");
//cc
        return;
    }
    int board2[30][30] = {};
        for(int i = 0; i < n; i++)
            for(int j = 0; j  < n; j++)
                board2[i][j] = arr[i][j];
    doright(board2);
    func(board2, k+1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j  < n; j++)
                board2[i][j] = arr[i][j];
    dodown(board2);
    func(board2, k+1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j  < n; j++)
                board2[i][j] = arr[i][j];
    doleft(board2);
    func(board2, k+1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j  < n; j++)
                board2[i][j] = arr[i][j];
    doup(board2);
    func(board2, k+1);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
        }
    func(board, 0);
    printf("%d", max);
    // printf("\n");
    // doright(board);
    // for(int i = 0; i < n; i++){  
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    //  doleft(board);
    // for(int i = 0; i < n; i++){  
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}