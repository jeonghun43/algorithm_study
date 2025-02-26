// 7785 회사에 있는 사람
#include <stdio.h>
#include <string.h>
char name[1000001][10];
char enle[10];
char tmp[10];
char ans[1000005][10];
char key[1000005][10];
int val[1000005];
int nxt[1000005];
int pre[1000005];
int head[1000005];

int n;
int m = 1000003;
int a = 1000;
int unused = 0;
int ansidx = 0;
void sort(){
    for(int i = 0; i < ansidx-1; i++){
        for(int j = i+1; j < ansidx; j++){
            if(strcmp(ans[i], ans[j]) < 0){
                strcpy(tmp, ans[i]);
                strcpy(ans[i], ans[j]);
                strcpy(ans[j], tmp);
            }
        }
    }
}
int mysize(char k[]){
    int size = 0;
    while(k[size] != '\0'){
        size++;
    }
    return size;
}
int my_hash(char k[]){
    int s = mysize(k);
    int h = 0;
    for(int i = 0; i < s; i++){
        h = (h * a + k[i]) % m;
    }
    return h;
}
int find(char k[]){
    int s = mysize(k);
    int h = my_hash(k);
    int cur = head[h];
    // printf("In find %s %d\n", k, cur);
    
    int flag = 1;
    while(cur != -1){
        flag = 1;
    
        for(int i = 0; i < s; i++){
            if(key[cur][i] != k[i]){
                flag = 0;
                break;
            }
        }   
        if(flag){
            // printf("this is return cur\n");
            return cur;
        }
        cur = nxt[cur];
    }
    
    return -1;
}
void insert(char k[], int v){
    int s = mysize(k);
    int h = my_hash(k);
    int idx = find(k);
    if(idx != -1){
        val[idx] = v;
        return;
    }
    for(int i = 0; i < s; i++){ //얘를 빼먹었었다!
        key[unused][i] = k[i];
    }

    val[unused] = v; 
    if(head[h] != -1){
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}
void erase(char k[]){
    int s = mysize(k);
    int h = my_hash(k);
    int idx = find(k);
    int left = pre[idx];
    int right = nxt[idx];
    if(idx == -1)   return;
    if(left != -1)  nxt[left] = right;
    if(right != -1) pre[right] = left;
    if(head[h] == idx)  head[h] = right;
}
int main(){
    for(int i = 0; i < 1000005; i++){
        nxt[i] = -1;
        pre[i] = -1;
        val[i] = -1;
        head[i] = -1;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s", &name[i], &enle);
        if(enle[0] == 'e'){ //enter
            insert(name[i],1);
            // printf("(check) Insert %s\n", name[i]);
        }else{  //leave
            erase(name[i]);
            // printf("(check) Erase %s\n", name[i]);
        }
    }
    for(int i = 0; i < n; i++){
        //printf("check name %s\n", name[i]);
        if(find(name[i]) == -1) continue;
        else{
            //printf("check else\n");
            int s = mysize(name[i]);
            //printf("%s's size is %d\n", name[i], s);
            for(int j = 0; j < s; j++){
                ans[ansidx][j] = name[i][j];
            }
            ansidx++;
    }
}
//sort();
// printf("yeaeh! %s\n", ans[0]);
    for(int i = 0; i < ansidx; i++){
        printf("%s\n", ans[i]);
    }

    return 0;
}