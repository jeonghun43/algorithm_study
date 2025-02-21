// 1920 수찾기 투포인터버전 
// 아직 해결못함...ㅜㅜ 런타임에러 OutOfBounds

// 범위는 약 -21억~21억이므로 int 사용
// n 배열 정렬
// m 배열은 정렬 수행한 값들을 새로운 배열에 따로 저장
// 투포인터(투커서) 풀이
// 되네요..!
// 그니까 런타임에러 났던 코드는 투포인터 자체에서 문제 일어난게 아니라
// 그 정답 값을 저장하고 출력할때 문제 생겼던 거임
// 정수범위가 약-21억~21억 정도라서 값에 따라서 저장하는 걸로 하면 범위 한참 벗어남
// 그래서 솔루션! n과m 둘다 10만이므로 이를 활용한다
// 몇번째에 들어온 친구인지를 저장한 뒤
// 그걸 활용해서 답을 저장하고 출력하면 됨!
#include <stdio.h>
struct data{
    int val;
    int key;
};
int n, m;
int arr1[100005];
struct data arr2[100005];
struct data tmp[100005];
int ans[100005];
int prt[100005]; 
void mapmerge(int st, int en, struct data board[]){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid) tmp[i] = board[b++];
        else if(b == en) tmp[i] = board[a++];
        else if(board[a].val <= board[b].val) tmp[i] = board[a++];
        else tmp[i] = board[b++];
    }
    for(int i = st; i < en; i++){
        board[i] = tmp[i];
    }
}
void mapmergesort(int st, int en, struct data board[]){
    int mid = (st+en) / 2;
    if(en - st == 1)    return;
    mapmergesort(st, mid, board);
    mapmergesort(mid, en, board);  
    mapmerge(st, en, board);
}

void merge(int st, int en, int board[]){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid) tmp[i].val = board[b++];
        else if(b == en) tmp[i].val = board[a++];
        else if(board[a] <= board[b]) tmp[i].val = board[a++];
        else tmp[i].val = board[b++];
    }
    for(int i = st; i < en; i++){
        board[i] = tmp[i].val;
    }
}
void mergesort(int st, int en, int board[]){
    int mid = (st+en) / 2;
    if(en - st == 1)    return;
    mergesort(st, mid, board);
    mergesort(mid, en, board);  
    merge(st, en, board);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &arr2[i].val);
        arr2[i].key = i;
    }
    mergesort(0, n, arr1);
    mapmergesort(0, m, arr2);
    //투포인터 풀이
    int en = 0;
    for(int st = 0; st < m; st++){
        while(en < n && arr2[st].val > arr1[en]){
            en++;
        }
        if(en == n) break;
        if(arr2[st].val == arr1[en])    ans[arr2[st].key] = 1;
    }    
    for(int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}