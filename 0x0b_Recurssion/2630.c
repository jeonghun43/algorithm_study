//2630 색종이 만들기
//재귀적으로 계속 봐야겠다고 생각했음
//종이 하나가 주어지면 4개의 부분으로 나누어서 재귀적으로 실행
//그러다가 나누어진 부분이 같은 색으로만 이루어져 있으면 재귀를 멈추고
//그 부분이 0인지 1인지 판단. 하얀색인지 파란색인지 판단
//판단후 그 색의 개수를 +1
//N  종이 한 변의 길이
//arr[150][150] 색종이 상태 입력받을 배열
//whitecnt  bluecnt

#include <stdio.h>
int n;
int arr[150][150];
int cnt[2] = {};

void func(int x, int y, int k){ //x는 세로를 나타냄 arr[x][y], k는 길이를 나타냄
// printf("this is %d %d %d...\n", y, x, k);
    if(k == 1){
        cnt[arr[x][y]]++;
        return;
    }
    int isallsame=1;    //전부 같은숫자인지 여부를 저장하는 변수
    //전부 같은 숫자인지 판단
    for(int i = x; i < x+k; i++){
        for(int j = y; j < y+k; j++){
            if(arr[x][y] != arr[i][j]){ //하나라도 다른게 나오면
                isallsame = 0;          //false로 만들고
                i = x+k;                //이중반복문을  
                break;                  //바로 빠져나온다
            }
        }
    }

    if(isallsame){  //전부 같은 숫자라면
        cnt[arr[x][y]]++;   //하얀색일땐 0번 인덱스의 카운트를 +1, 파란색일땐 1번 인덱스의 카운트를 +1
        return;
    }

    //전부 같은 숫자가 아니라면 4등분 해줘야함
    int halfx = x + k/2;  //x는 x좌표가 아니라 y좌표임을 유의. 세로를 나타냄 EX) arr[x][y] 이차원배열에서 x는 세로를 나타냄
    int halfy = y + k/2;
    func(x, y, k/2);        //1사분면
    func(x, halfy, k/2);    //2사분면
    func(halfx, y, k/2);    //3사분면
    func(halfx, halfy, k/2);//4사분면
}
int main(){
    scanf("%d", &n);                    //n값 입력받고
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);    //색종이 정보 입력받기
        
    func(0, 0, n);
    printf("%d\n%d", cnt[0], cnt[1]);
    return 0;
}