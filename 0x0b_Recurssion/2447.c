// 2447 별 찍기 - 10
// 재귀적으로..
// 2448 별찍는거 코드 참고했음
// 인자값에 row column 있는거랑
// 배열에 저장해두는거 이 두가지만 알면 쉽다!

#include <stdio.h>
int n;
char arr[2500][2500];
void func(int n, int r, int c){
    if(n == 3){
        for(int i = r; i < r+3; i++){
            for(int j = c; j < c+3; j++){
                if(i == r+1 && j == c+1){
                    arr[i][j] = ' ';
                    continue;
                }
                arr[i][j] = '*';
            }
        }
        return;
    }
    int a = n/3;
    func(n/3, r, c);
    func(n/3, r , c + (n/3));
    func(n/3, r, c + (n/3)*2);

    func(n/3, r + (n/3), c);
    //공백출력
    for(int i = r + (n/3); i < r + (n/3) + n/3; i++){
        for(int j = c + (n/3); j < c + (n/3) + n/3; j++){
            arr[i][j] = ' ';
        }
    }
    func(n/3, r + (n/3), c + (n/3)*2);

    func(n/3, r + (n/3)*2, c);
    func(n/3, r + (n/3)*2, c + (n/3));
    func(n/3, r + (n/3)*2, c + (n/3)*2);
}
int main(){
    scanf("%d", &n);
    func(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}