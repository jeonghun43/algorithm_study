//1780 종이개수

//재귀로 풀어야겠다는 생각이 들었음 약간 z느낌
#include <stdio.h>
int arr[2500][2500];
int cnt[5];
int sum=0, n;
void func(int k, int x, int y){
    if(k == 1){
        cnt[arr[y][x]+1]++;
        return;
    }
    int tmp, issame=1;

    for(int i = y; i < y+k; i++){
        for(int j = x; j < x+k; j++){
            if(i==y && j==x) tmp = arr[i][j];
            if(tmp != arr[i][j]){
                issame = 0;
                i=y+k;
                break;
            }
        }
    }
    if(issame){
        cnt[tmp+1]++;
        return;
    }else{
        //9개 func
        func(k/3, x, y);
        func(k/3, x+k/3, y);
        func(k/3, x+(k/3)*2, y);

        func(k/3, x, y+k/3);
        func(k/3, x+k/3, y+k/3);
        func(k/3, x+(k/3)*2, y+k/3);

        func(k/3, x, y+(k/3)*2);
        func(k/3, x+k/3, y+(k/3)*2);
        func(k/3, x+(k/3)*2, y+(k/3)*2);
    }
    
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        scanf("%d", &arr[i][j]);
        }
    }
    func(n, 0 ,0);
    for(int i = 0; i < 3; i++){
        printf("%d\n", cnt[i]);
    }
    return 0;
}