// 1759 암호만들기
// 결국 이 문제도 백트래킹 
// 해당하는 알파벳 암호를 찾기위해 모든 경우의 수들을 고려해봐야하기 때문
// a t c i s w
// a c i s t w
#include <stdio.h>
int L, C;
char arr[20];
char ans[20];
int isused[20];
void sort(){
    char tmp;
    for(int i = 0; i < C-1; i++){
        for(int j = i+1; j < C; j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }   
    }
}
void func(int k){
    if(k == L){
        int aeiou = 0;
        for(int i = 0; i < L; i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
                aeiou++;
        }
        if(!aeiou || L-aeiou < 2)  return; //모음이 없거나 || 아니면 자음개수가 모자랄때
        for(int i = 0; i < L; i++){
            printf("%c", ans[i]);           
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < C; i++){
        if(isused[i] || ans[k-1] > arr[i])   continue;
        ans[k] = arr[i];
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}
int main(){
    scanf("%d %d", &L, &C);
    for(int i = 0; i < C; i++){
        scanf("%s", &arr[i]);
    }
    sort();
    func(0);
    return 0;
}