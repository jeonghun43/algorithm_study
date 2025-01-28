// 15688 수 정렬하기 5  counting sort 이용
#include <stdio.h>
int n;
int arr[2000005];
int cnt[2000005];
void counting_sort(){
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0) cnt[arr[i]]++;
        else    cnt[2000001+arr[i]]++;
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    counting_sort();
    for(int i = -1000000; i <= -1; i++){
        if(cnt[2000001+i] > 0)
            for(int j = 0; j < cnt[2000001+i]; j++)
                printf("%d\n", i);
    }
    for(int i = 0; i <= 1000000; i++){
        if(cnt[i] > 0)
            for(int j = 0; j < cnt[i]; j++)
                printf("%d\n", i);
    }
    return 0;
}