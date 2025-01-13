#include <stdio.h>

int dat[20005];
int head = 10000, tail = 10000;
int cnt = 0;

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

int pop_front(){
    if(head == tail)    return -1;
    else    return dat[head++];
}

int pop_back(){
    if(head == tail)    return -1;
    else    return dat[--tail];
}

int front(){
    if(head == tail)    return -1;
    else    return dat[head];
}

void moveLeft(){
    push_back(pop_front());
    cnt++;
}

void moveRight(){
    push_front(pop_back());
    cnt++;
}

int main(void){
    int N, M;
    char pick[51];
    int x;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++){
        scanf("%d", &pick[i]);
    }
    for(int i = 0; i < N; i++){
        push_back(i+1);   
    }

    for(int i = 0; i < M; i++){
        if(front() == pick[i]){
            pop_front();
            continue;
        }else{
            int size = tail - head;

            for(int j = head+1; j < tail; j++){
                if(dat[j] != pick[i]) continue;

                if(j <= head + (size / 2)){
                    while(front() != pick[i]){
                    moveLeft();
                    }
                    pop_front();
                    break;
                }
                else{
                    while(front() != pick[i]){
                    moveRight();  
                    }
                    pop_front();
                    break;
                }
                               
            }
        }
    }

    printf("%d", cnt);

    return 0;
}