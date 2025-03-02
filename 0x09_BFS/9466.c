// 9466 텀 프로젝트
// n 최대값 10만 이므로
// n^2은 절대 안 됨 못해도 nlongn 이런느낌?
// 프로젝트에 속하지 못한 학생들의 수 출력
//tlqkf ehoTek
#include <stdio.h>
int t, n, ans;
int arr[100005];
int d[100005];
int visited[100005];
int varr[100005];
int s[100005];
int point = 0;
void push(int x){
    s[point++] = x;
}
int pop(){
    point--;
    return s[point];
}
// 2
// 5
// 2 3 1 1 1
// 5
// 5 5 4 5 3
int isempty(){
    if(point == 0) return 1;
    return 0;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1 ; i <= n; i++){
            scanf("%d", &arr[i]);
            if(i == arr[i]) visited[i] = 2;
        }
        for(int i = 1; i <= n; i++){
            // printf("%d  dd\n", i);
            if(visited[i] ==2 || visited[i] == -1) continue; 
            int flag = 1;
            int cur = i;
            while(flag){
                if(visited[cur] == 2){
                    while(!isempty()){
                        visited[pop()] = -1;
                    }
                    break;
                }
                if(visited[cur] == 1){
                    int ff = 1;
                    while(!isempty()){
                        int idx = pop();
                        // printf("in %d pop %d\n", i, idx);
                        if(!ff){
                            visited[idx] = -1;
                            // printf("wtf %d : %d \n", idx, visited[idx]);
                        }else visited[idx] = 2;
                        if(ff && idx == cur){
                            ff = 0;
                        }
                    }
                    flag = 0;
                    break;

                }else if(visited[cur] == -1){
                    while(!isempty()){
                        int idx = pop();
                        visited[idx] = -1;
                    }
                    break;
                }
                visited[cur] = 1;
                push(cur);
                cur = arr[cur];
            }
            // printf("check %d\n", i);
            // for(int j = 1; j <= n; j++){
            //     printf("%d ", visited[j]);
            // }
            // printf("\n");
        }
        int cnt = 0;
        point = 0;
        for(int j = 1; j <= n; j++){
            if(visited[j] == -1) cnt++;
            visited[j] = 0;
        }
        printf("%d\n", cnt);
    }
    return 0;
}