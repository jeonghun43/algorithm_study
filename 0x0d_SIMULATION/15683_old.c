// 15683 감시
// 백트래킹. 재귀 활용하였으나 실패
// 시간이 오래걸리기도 하고, 예제4에대한 답 이상하게 나옴
#include <stdio.h>
int n, m;
int mincnt=0, cctvcnt=0;
int arr[10][10] = {};
int isused[10][10] = {};
int idxtmp = 1;
struct cctv
{
    int i;
    int j;
};

struct rdlu{
    int right;
    int down;
    int left;
    int up;
};
struct rdlu rdluarr[10][10];
struct cctv cctvarr[10];
void right(int i, int j, int arr[][10]){
    j++;
    for(int a = 0; a < m; a++){
        if(j == m || arr[i][j] == 6)    break;
        if(1 <= arr[i][j] && arr[i][j] <= 5) continue;
        arr[i][j++] = -1;
    }
}
void down(int i, int j, int arr[][10]){
    i++;
    for(int a = 0; a < m; a++){
        if(i == n || arr[i][j] == 6)    break;
        if(1 <= arr[i][j] && arr[i][j] <= 5) continue;
        arr[i++][j] = -1;
    }
}
void left(int i, int j, int arr[][10]){
    j--;
    for(int a = 0; a < m; a++){
        if(j == -1 || arr[i][j] == 6)    break;
        if(1 <= arr[i][j] && arr[i][j] <= 5) continue;
        arr[i][j--] = -1;
    }
}
void up(int i, int j, int arr[][10]){
    i--;
    for(int a = 0; a < m; a++){
        if(i == -1 || arr[i][j] == 6)    break;
        if(1 <= arr[i][j] && arr[i][j] <= 5) continue;
        arr[i--][j] = -1;
    }
}
struct rdlu cctv1(int i, int j){
    struct rdlu tmp = {0,0,0,0};
    int max = 0;
    int cnt[4] = {}; // 0 0 0 0  => 우 하 좌 상

    //우측방향 판단
    for(int a = j; a < m; a++){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[0]++;
    }
    if(cnt[0] > max)    max = cnt[0];

    //아래방향 판단
    for(int a = i; a < n; a++){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[1]++;
    }
    if(cnt[1] > max)    max = cnt[1];

    //좌측방향 판단
    for(int a = j; a >= 0; a--){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[2]++;
    }
    if(cnt[2] > max)    max = cnt[2];

    //위쪽방향 판단
       for(int a = i; a >= 0; a--){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[3]++;
    }
    if(cnt[3] > max)    max = cnt[3];

    if(max == cnt[0])   tmp.right = 1;
    if(max == cnt[1])   tmp.down = 1;
    if(max == cnt[2])   tmp.left = 1;
    if(max == cnt[3])   tmp.up = 1;

    //printf("\nthis is cnt[]\n%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);

    return tmp;
}
struct rdlu cctv2(int i, int j){
    struct rdlu tmp = {0,0,0,0};
    int max = 0;
    int cnt[4] = {}; // 0 0 0 0  => 우 하 좌 상

    //우측방향 판단
    for(int a = j; a < m; a++){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[0]++;
    }

    //아래방향 판단
    for(int a = i; a < n; a++){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[1]++;
    }

    //좌측방향 판단
    for(int a = j; a >= 0; a--){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[2]++;
    }

    //위쪽방향 판단
       for(int a = i; a >= 0; a--){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[3]++;
    }

    if(cnt[0] + cnt[2] >= cnt[1] + cnt[3])
        tmp.left = 1;
    if(cnt[1] + cnt[3] >= cnt[0] + cnt[4])
        tmp.down = 1;

    return tmp;
}
struct rdlu cctv3(int i, int j){
    struct rdlu tmp = {0,0,0,0};
    int cnt[4] = {}; // 0 0 0 0  => 우 하 좌 상

    //우측방향 판단
    for(int a = j; a < m; a++){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[0]++;
    }

    //아래방향 판단 하
    for(int a = i; a < n; a++){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[1]++;
    }

    //좌측방향 판단
    for(int a = j; a >= 0; a--){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[2]++;
    }

    //위쪽방향 판단 상
       for(int a = i; a >= 0; a--){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[3]++;
    }

    int anc[4] = {};
    anc[0] = cnt[3] + cnt[0];   //상 우
    anc[1] = cnt[0] + cnt[1];     //우 하
    anc[2] = cnt[1] + cnt[2];     //하 좌
    anc[3] = cnt[2] + cnt[3];     //좌 상 

    int max = anc[0];

    for(int a = 1; a < 4; a++){
        if(anc[a] > max)    max = anc[a];
    }

    if(max == anc[0])
        tmp.up = 1;
    if(max == anc[1])
        tmp.right = 1;
    if(max == anc[2])
        tmp.down = 1;
    if(max == anc[3])
        tmp.left = 1;

    return tmp;
}
struct rdlu cctv4(int i, int j){
    struct rdlu tmp = {0,0,0,0};
    int cnt[4] = {}; // 0 0 0 0  => 우 하 좌 상

    //우측방향 판단
    for(int a = j; a < m; a++){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[0]++;
    }

    //아래방향 판단 하
    for(int a = i; a < n; a++){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[1]++;
    }

    //좌측방향 판단
    for(int a = j; a >= 0; a--){
        if(arr[i][a] == 6) break;
        else if(arr[i][a] == 0) cnt[2]++;
    }

    //위쪽방향 판단 상
       for(int a = i; a >= 0; a--){
        if(arr[a][j] == 6) break;
        else if(arr[a][j] == 0) cnt[3]++;
    }

    int anc[4] = {};
    anc[0] = cnt[0] + cnt[1] + cnt[2];     //우 하 좌
    anc[1] = cnt[1] + cnt[2] + cnt[3];     //하 좌 상
    anc[2] = cnt[2] + cnt[3] + cnt[0];     //좌 상 우 
    anc[3] = cnt[3] + cnt[0] + cnt[1];     //상 우 하  

    int max = anc[0];

    for(int a = 1; a < 4; a++){
        if(anc[a] > max)    max = anc[a];
    }
    //printf("\nthis is cnt[]\n%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
    //printf("\nthis is ans[]\n%d %d %d %d\n", anc[0], anc[1], anc[2], anc[3]);
    if(max == anc[0])
        tmp.up = 1;
    if(max == anc[1])
        tmp.right = 1;
    if(max == anc[2])
        tmp.down = 1;
    if(max == anc[3])
        tmp.left = 1;

    return tmp;
}
void clear(int tmp[][10], int arr[][10]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
}
void func(int k, int arr[][10]){
       if(k == cctvcnt){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 0)  cnt++;
            }
        }
        // //check
        // printf("check %d\n", idxtmp++);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //        printf("%d  ", arr[i][j]);
        //     }
        //     printf("\n");
        // }
        // //check

        if(cnt < mincnt)    mincnt = cnt;
        return;
    }

    int tmp[10][10] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
    for(int a = 0; a < cctvcnt; a++){
        int i = cctvarr[a].i;
        int j = cctvarr[a].j;
        if(isused[i][j])  continue;
        isused[i][j] = 1;

        if(arr[i][j] == 1){ // 1번 cctv
            if(rdluarr[i][j].right){
            right(i, j, tmp);   //오른쪽 방향으로 탐색
            func(k+1, tmp);
            clear(tmp, arr);
            }

            if(rdluarr[i][j].down){
            down(i, j, tmp);    //아래쪽 방향으로 탐색
            func(k+1, tmp);
            clear(tmp, arr);   
            }

            if(rdluarr[i][j].left){
            left(i, j, tmp);    //왼쪽 방향으로 탐색
            func(k+1, tmp);
            clear(tmp, arr);
            }

            if(rdluarr[i][j].up){
            up(i, j, tmp);      //위쪽 방향으로 탐색
            func(k+1, tmp);
            clear(tmp, arr);
            }
            isused[i][j]=0;
        }else if(arr[i][j] == 2){   //2번 cctv
            if(rdluarr[i][j].left){     //좌우 방향으로 탐색
                right(i, j, tmp);
                left(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            if(rdluarr[i][j].down){     //상하 방향으로 탐색
                down(i, j, tmp);
                up(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            isused[i][j] = 0;
        }else if(arr[i][j] == 3){   //3번 cctv
            if(rdluarr[i][j].up){   //위쪽과 오른쪽
                up(i, j, tmp);
                right(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            if(rdluarr[i][j].right){//오른쪽과 아래쪽
                right(i, j, tmp);
                down(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            if(rdluarr[i][j].down){ //아래쪽과 왼쪽
                down(i, j, tmp);
                left(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            if(rdluarr[i][j].left){ //왼쪽과 위쪽
                left(i, j, tmp);
                up(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            isused[i][j]=0;
        }else if(arr[i][j] == 4){   //4번 cctv
            if(rdluarr[i][j].up){   //위쪽 빼고 다   우 하 좌
                right(i, j, tmp);
                down(i, j, tmp);
                left(i, j, tmp);
                func(k+1, tmp);
                clear(tmp,arr);
            }
            if(rdluarr[i][j].right){//우측 빼고 다   하 좌 상 
                down(i, j, tmp);
                left(i, j, tmp);
                up(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }if(rdluarr[i][j].down){//아래쪽 빼고 다   좌 상 우 
                left(i, j, tmp);
                up(i, j, tmp);
                right(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }if(rdluarr[i][j].left){//좌측 빼고 다   상 우 하 
                up(i, j, tmp);
                right(i, j, tmp);
                down(i, j, tmp);
                func(k+1, tmp);
                clear(tmp, arr);
            }
            isused[i][j]=0;
        }else if(arr[i][j] == 5){
            right(i, j, tmp);
            down(i, j, tmp);
            left(i, j, tmp);
            up(i, j, tmp);
            func(k+1, tmp);
            clear(tmp, arr);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            scanf("%d", &arr[i][j]);
            if(1 <= arr[i][j] && arr[i][j] <= 5){
                cctvarr[idx].i = i;
                cctvarr[idx++].j = j;
                cctvcnt++;
                }
            else if(arr[i][j] == 0) mincnt++;
        }
    }
    for(int idx = 0; idx < cctvcnt; idx++){
        int i = cctvarr[idx].i;
        int j = cctvarr[idx].j;
        if(arr[i][j] == 1){
            //printf("%d %d's position", i, j);
            rdluarr[i][j] = cctv1(i, j);
        }else if(arr[i][j] == 2){
            rdluarr[i][j] = cctv2(i, j);
        }
        else if(arr[i][j] == 3){
            rdluarr[i][j] = cctv3(i, j);
        }
        else if(arr[i][j] == 4){
            rdluarr[i][j] = cctv4(i, j);
        }
    }
    // for(int idx = 0; idx < cctvcnt; idx++){
    //     int i = cctvarr[idx].i;
    //     int j = cctvarr[idx].j;
    //     //printf("%d %d %d %d\n", rdluarr[i][j].right, rdluarr[i][j].down, rdluarr[i][j].left, rdluarr[i][j].up);
    // }
    func(0, arr);
    printf("%d", mincnt);

    // for(int idx = 0; idx < cctvcnt; idx++){
    //     int i = cctvarr[idx].i;
    //     int j = cctvarr[idx].j;
    //     printf("\n");
    //     printf("%d %d %d %d\n", rdluarr[i][j].right, rdluarr[i][j].down, rdluarr[i][j].left, rdluarr[i][j].up);
    // }
    return 0;
}