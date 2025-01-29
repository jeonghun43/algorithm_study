// 11652 카드
#include <stdio.h>
int n;
long long arr[100005];
long long tmp[100005];
void merge(int st, int en){
    int mid = (st+en) / 2;
    int aidx = st, bidx = mid;
    for(int i = st; i < en; i++){
        if(aidx == mid) tmp[i] = arr[bidx++];
        else if(bidx == en) tmp[i] = arr[aidx++];
        else if(arr[aidx] > arr[bidx])  tmp[i] = arr[bidx++];
        else tmp[i] = arr[aidx++]; 
    }
    for(int i = st; i < en; i++){
        arr[i] = tmp[i];
    }
}
void merge_sort(int st, int en){
    if(en-st == 1) return;
    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}
int main(){
    int cnt=1, mxcnt = 0; 
    long long mxval = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);     //long long 자료형은 lld 써주기 (엘 엘 디)
    }
    merge_sort(0, n);
    for(int i = 1; i < n; i++){
        if(arr[i-1] != arr[i]){     //이 조건도 처음에는 다르게 썼어서 틀렸음
            if(cnt > mxcnt){
            mxcnt = cnt;
            mxval = arr[i-1];       //[i]로 해서 틀렸었다
            }
            cnt = 1;
        }
        else    cnt++;
    }
    //n = 1일때 반복문 수행 안 해서.. 그 때도 mxval값 찾아줘야함
    if(cnt > mxcnt) mxval = arr[n-1];   // 겁나 틀리고 이 코드 추가해줌  
    printf("%lld", mxval);
    return 0;
}