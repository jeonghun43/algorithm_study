// 15688 수 정렬하기 5  counting sort 이용

//바킹독이 하는 방식
/*
#include <stdio.h>
int n;
int cnt[2000005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        cnt[1000000+tmp]++;
    }
    for(int i = 0; i <= 2000000; i++){
        while(cnt[i]--)
            printf("%d\n",i-1000000);
    }
    return 0;
}
*/

//내가 해봤음.. 바킹독이 한 것처럼 하는게 더 깔끔하고 쉬울듯?
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