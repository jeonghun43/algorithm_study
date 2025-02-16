// 1920 수 찾기
// 이분탐색
// 숫자 10개 있을때의 상황 예시
// 0~9인덱스에 들어가있음
// 가운데인 (0+9)/2 = 4 4번째 인덱스 값과 x값 비교
// 만약 x가 더 크다면 범위는 +1인덱스 부터 끝까지
// 만약 X가 더 작다면 범위는 처음부터 -1인덱스까지
#include <stdio.h>
int n, m;
int dn[100001];
int dm[100001];
int tmp[100001];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
    if(a == mid)  tmp[i] = dn[b++];
    else if(b == en)    tmp[i] = dn[a++];
    else if(dn[a] <= dn[b])    tmp[i] = dn[a++];
    else    tmp[i] = dn[b++];
    }
    for(int i = st; i < en; i++){
        dn[i] = tmp[i];
    }
    
}
void mergeSort(int st, int en){    //버블정렬 하면 안됨 시간복잡도 때문에.. n,m이 최대 100,000 까지 이므로 
                    //O(nLogn)의 형태인 합병정렬 같은 거 사용해야함
    if(en-st == 1)  return;
    int mid = (st+en) / 2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}
void binarySearch(int x){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = (st+en) / 2;
        if(x > dn[mid]) st = mid+1;
        else if(x < dn[mid]) en = mid-1;
        else if(x == dn[mid]){
            printf("1\n");
            return;
        }    
    }
    printf("0\n");
}
int main(){ 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &dn[i]); 
    }
    mergeSort(0, n);

// printf("\n");
// for(int i = 0; i < n; i++){
//     printf("%d ", dn[i]); 
// }
// printf("\n");

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &dm[i]); 
    }

    for(int i = 0; i < m; i++){
        binarySearch(dm[i]);
    }
    return 0;
}