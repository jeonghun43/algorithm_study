#include <stdio.h>
int dat[1000005];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}
int pop(){
if(head != tail)
    return dat[head++];
else return -1;
}

int size(){
    return tail - head;
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){
        push(i);
    }

    while(size() > 1){
        pop();
        if(size() == 1) break;
        push(pop());
    }
    printf("%d", pop());
    return 0;
}

#include <stdio.h>
int dat[2000005];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

int pop(){
    if(head == tail) return -1;
    else{
        return dat[head++];
    }
}

// int size(){
//     return tail-head;
// }

// int empty(){
//     if(head == tail) return 1;
//     else return 0;
// }

// int front(){
//     if(head == tail) return -1;
//     else{
//     return dat[head];
//     }
// }

// int back(){
//     if(head == tail) return -1;
//     else{
//     return dat[tail-1];
//     }
// }

// int main(void) {
//     int N;
//     scanf("%d", &N);

//     while(N-- > 0){
//         char cmd[6];
//         scanf("%s", &cmd);

//         if(cmd[0] == 'p' && cmd[1] == 'u'){         //push
//             int tmp;
//             scanf("%d", &tmp);
//             push(tmp);
//         }else if(cmd[0] == 'p' && cmd[1] == 'o') {  //pop
//             printf("%d\n", pop());
//         }else if(cmd[0] == 's'){                    //size
//             printf("%d\n", size());
//         }else if(cmd[0] == 'e'){                    //empty
//             printf("%d\n", empty());
//         }else if(cmd[0] == 'f'){                    //front
//             printf("%d\n", front());
//         }else if(cmd[0] == 'b'){                    //back
//             printf("%d\n", back());
//         }
//     }
// }