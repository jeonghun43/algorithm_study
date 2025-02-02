// 18808 스티커 붙이기
// 백트래킹이 아니라 그냥 반복문으로 봐줘야할듯
// 모든 경우에 대해서 보는 것이 아니라
// 한 번 보고 안 되면 버려버리니까
// N세로 M가로 K스티커개수 R스티커세로 C스티커가로
// cnt스티커붙은칸개수
int n, m, k, r, c;
int notebook[50][50];   //노트북 배열
int sticker[105][20][20];   //스티커 배열
int stkx[105];
int stky[105];
int eachcnt[105];    //스티커 각각의 크기를 저장
int answer = 0;
#include <stdio.h>
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int p = 0; p < k; p++){ //스티커개수만큼 반복해서 입력받기
        scanf("%d %d", &stkx[p], &stky[p]); //스티커의 크기 입력
        int tmpcnt = 0;
        for(int i = 0; i < stkx[p]; i++)  //세로
            for(int j = 0; j < stky[p]; j++){ //가로
                scanf("%d", &sticker[p][i][j]); //스티커 정보 입력
                if(sticker[p][i][j] == 1)   tmpcnt++;
            }
        eachcnt[p] = tmpcnt;    //스티커의 크기를 따로 저장해두기
    }

    //판단시작
    // 100 * 4 * (100 + 40 * 40 * (10 * 10 + 10 * 10)) = 약 1억 2천만
    for(int h = 0; h < k; h++){ //스티커개수만큼반복
        for(int to = 0; to < 4; to++){  //4방향
            if(to != 0){                //배열 90도 회전
         
                int tmpstkarray[10][10] = {};
                for(int i = 0; i < stkx[h]; i++){
                    for(int j = 0; j < stky[h]; j++){
                        tmpstkarray[j][stkx[h]-1-i] = sticker[h][i][j];
                    }
                }

                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 10; j++){
                        sticker[h][i][j] = tmpstkarray[i][j];
                    }
                }
                int tmp = stkx[h];
                stkx[h] = stky[h];
                stky[h] = tmp;
                // printf("\n\nLet's check 90's rotate sticker\n");
                // for(int i = 0; i < stkx[h]; i++){
                //     for(int j = 0; j < stky[h]; j++){
                //         printf("%d ", sticker[h][i][j]);
                //     }
                //     printf("\n");
                // }
            }
            if(stkx[h] > n || stky[h] > m){   //노트북 범위 벗어나면 break
                    // printf("out of bounds!\n");
                    // for(int x = 0; x < n; x++){
                    //         for(int y = 0; y < m; y++){
                    //             printf("%d ", notebook[x][y]);
                    //         }
                    //         printf("\n");
                    //     }
                    if(stkx[h] > m || stky[h] > n)
                        break;  // 아무리 돌려도 범위를 벗어나므로 얘는 버리고 다른 스티커 판단하러 가야함
                    continue;   // 돌렸을때 범위 안에 온다면 돌리러간다
                }
            for(int i = 0; i < n; i++)      //노트북세로크기만큼
                for(int j = 0; j < m; j++){  //노트북가로크기만큼
                    if(stkx[h] + i > n){
                        i = n;
                        break;
                    } 
                    if(stky[h] + j > m) break;
                    int fit = 1;
                    for(int x = 0; x < 10; x++){
                        for(int y = 0; y < 10; y++){
                            if(j+y > m)   break;
                            if(i+x > n){
                                x = 10;
                                break; 
                            }
                            if(sticker[h][x][y] == 0) continue;      //빈 자리는 넘어감
                            if(notebook[i+x][j+y] == 1){//노트북에 이미 스티커 붙어있으면 넘어감                        
                                //printf("%d already exist!%d %d\n",h , j+y, i+x);
                                fit = 0;
                                x = 10;
                                break;    
                            }
                        }
                    }
                    if(fit){    //스티커가 노트북에 들어갈 수 있을때
                        for(int x = 0; x < 10; x++){
                            for(int y = 0; y < 10; y++){
                                if(sticker[h][x][y] == 0) continue; //스티커 안들어있으면 continue
                                notebook[i+x][j+y] = 1; //노트북에 스티커 붙였음을 표시
                            }
                        }
                        // printf("\n\n\n %d checking.. in %d\n", h, to);
                        // for(int x = 0; x < n; x++){
                        //     for(int y = 0; y < m; y++){
                        //         printf("%d ", notebook[x][y]);
                        //     }
                        //     printf("\n");
                        // }
                        answer += eachcnt[h];   //답에 스티커 개수 +해주기
                        i = 50;
                        to = 4;
                        break;          //i 와 j 반복문 종료
                    }
                }
        }
    }

    printf("%d", answer);
    return 0;
}