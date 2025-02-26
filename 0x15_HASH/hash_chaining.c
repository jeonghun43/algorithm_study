// hash Chaining 구현
// 연결리스트 먼저 구현
#include <stdio.h>
int head[1000005];
char key[1000005][20];
int dat[1000005];
int pre[1000005];
int nxt[1000005];
int unused = 0;
const int M = 1000003;
const int a = 1000;
int mysize(char k[]){
    int size = 0;
    for(int i = 0 ; i < 100; i++){
        if(k[i] == '\0')  break;
        size++;
    }
    return size;
}
int my_hash(char k[]){
    int s = mysize(k);
    int h = 0;
    for(int i = 0; i < s; i++){
        char tmp = k[i];
        h = (h * a +tmp) % M;
    }
    return h;
  }
  int find(char k[]){
    int s = mysize(k);
    int hash = my_hash(k);
    int cur = head[hash];
    int flag = 1;
    while(cur != -1){
        flag = 1;
        for(int i = 0; i < s; i++){
            if(key[cur][i] != k[i]){
                flag = 0;
                break;
            }
        }
        if(flag) return cur;
        cur = nxt[cur];
    }
    return -1;
  }
  void insert(char k[], int v){
    int s = mysize(k);
    int hash = my_hash(k);
    int idx = find(k);

    if(idx != -1){
        dat[idx] = v;
        return;
    }

    for(int i = 0; i < s; i++){
        key[unused][i] = k[i];
    }

    dat[unused] = v;
    if(head[hash] != -1){
        nxt[unused] = head[hash];
        pre[head[hash]] = unused;
    }
    head[hash] = unused;
    unused++;
  }
  
  void erase(char k[]){
    int s = mysize(k);
    int cur = find(k);
    int hash = my_hash(k);
    int right = nxt[cur];
    int left = pre[cur];
    if(cur == -1) return;
    if(left != -1)  nxt[left] = right;
    if(right != -1) pre[right] = left;
    if(head[hash] == cur){  //head값 업데이트
        head[hash] = right;
    }
  }
void test(){
    insert("orange", 724); // ("orange", 724)
    insert("melon", 20); // ("orange", 724), ("melon", 20)
    if(dat[find("melon")] == 20) printf("yes1\n");
    insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
    insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
    insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    if(dat[find("banana")] == 52) printf("yes2\n");
    if(dat[find("orange")] == 100) printf("yes3\n");
    erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
    if(find("banana") == -1) printf("yes4\n");
    erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
    insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
    if(dat[find("orange")] == 15) printf("yes5\n");
    insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
    insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
    insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
    if(dat[find("cherry")] == 27) printf("yes6\n");
    erase("xxxxxxx");
    printf("good!");
    if(dat[find("apple")] == 36) printf("yes7\n");
    if(dat[find("melon")] == 20) printf("yes8\n");
    if(dat[find("banana")] == 52) printf("yes9\n");
    if(dat[find("cherry")] == 27) printf("yes10\n");
    if(dat[find("orange")] == 701) printf("yes11\n");
    if(dat[find("lemon")] == 6) printf("yes12\n");
  }
int main(){
    for(int i = 0; i < 1000005; i++){
        dat[i] = -1;
        pre[i] = -1;
        nxt[i] = -1;
        head[i] = -1;
    }
    test();
    // printf("****** insert_test *****\n");
    //   insert(0, 10); // 10(address=1)
    //   traverse();
    //   insert(0, 30); // 30(address=2) 10
    //   traverse();
    //   insert(2, 40); // 30 40(address=3) 10
    //   traverse();
    //   insert(1, 20); // 30 40 10 20(address=4)
    //   traverse();
    //   insert(4, 70); // 30 40 10 20 70(address=5)
    //   traverse();
    return 0;
}