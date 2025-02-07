// 2468 별찍기
#include <stdio.h>
int n;
char ans[10000][10000];
int idx=0;
void func(int k, int row, int column){
    if(k == 3){
        ans[row][column] = '*';
        ans[row+1][column-1] = '*';
        ans[row+1][column+1] = '*';
        for(int i = 0; i < 5; i++){
            ans[row+2][column-2+i] = '*';
        }
        return;
    }
    func(k/2, row, column);
    func(k/2, row + k/2, column - k/2);
    func(k/2, row + k/2, column + k/2);

}
int main(){
    scanf("%d", &n);  
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < 2*n; j++){
            ans[i][j] = ' ';
        }
    }
    func(n, 0, n-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n; j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}