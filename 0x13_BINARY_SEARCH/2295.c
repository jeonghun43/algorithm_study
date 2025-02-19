// 2295 세 수의 합

// 얻은 것 : 뭔가 2개의 값을 묶고 어느 하나의 값을
// 이분탐색으로 찾아서 시간복잡도를 낮출 수 있다

// a + b + c = d 일때 해당 원소가 있다면
// 그 경우들 중에서 가장 큰 d값을 출력
// 그냥 4중반복문 돌리면 시간복잡도는 O(N^4)
// a + b + c까지만 하고 그 값에 대하여 이분탐색으로 찾아보는걸로 하면 
// 시간복잡도는 O(N^3 logN)
// N이 최대 1,000 이라서 시간초과
// 해결방법
// 두 원소끼리의 합을 우선 구해 O(N^2)
// two[] + c = d라고 할때, d - c를 하고 
//그 값이 two배열에 들어가 있는지 이분탐색으로 확인 
// 그러면 O(logN^2) 에 가능하므로
// 전체 시간복잡도 O(N^2 logN)
// HOLY 출력 조건에 x + y + z = k 에서 x,y,z가 서로 같아도 된다라고 나와있네요 그래서 중복 가능이었음 ㅎ..
#include <stdio.h>
int n;
int idx = 0; 
int tmp[1000001];
int arr[1001];
int two[1000001];
//정렬함수
void arrsort(){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void merge(int st, int en){
    int mid = (st+en) / 2;
    int a = st;
    int b = mid;
    for(int i = st; i < en; i++){
        if(a == mid)    tmp[i] = two[b++];
        else if(b == en) tmp[i] = two[a++];
        else if(two[a] <= two[b])   tmp[i] = two[a++];
        else tmp[i] = two[b++];
    }
    for(int i = st; i < en; i++){
        two[i] = tmp[i];
    }
}
void mergesort(int st, int en){
    int mid = (st+en) / 2;
    if(en - st == 1)    return;
    mergesort(st, mid);
    mergesort(mid, en);
    merge(st, en);
}
//정렬 끝
//이분탐색 함수
int func(int x){
    int st = 0;
    int en = idx-1;
    
    while(st<=en){
        int mid = (st+en) / 2;
        if(two[mid] == x) return 1;
        else if(two[mid] > x) en = mid-1;
        else st = mid+1;
    }   
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    arrsort();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            two[idx++] = arr[i] + arr[j];
        }
    }
    mergesort(0, idx);
    for(int i = n-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(func(arr[i] - arr[j])){
                printf("%d", arr[i]);
                return 0;
            }
        }
    }
    return 0;
}