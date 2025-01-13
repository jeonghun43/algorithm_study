//3986 좋은 단어
#include <stdio.h>

char tmp[100005];
char dat[100005];
int pos = 0;
int a=0, b=0;

void push(char x){
    dat[pos++] = x;
}

void pop(){
    pos--;
}

char top(){
    return dat[pos-1];
}

int size(){
    return pos;
}

int main(){
    int N, cnt = 0;
    scanf("%d", &N);
    getchar();

    while(N-- > 0){
        pos = 0;
        a = 0, b = 0;
        scanf("%s", &tmp);
        getchar();
        for(int i = 0; i < 100000; i++){
            if(tmp[i] == 'A'){
                if(a && top() =='A'){   // A가 스택에 있고, 맨 위가 A라면
                        pop();          // A pop해서 없애
                        a--;      // A개수 감소
                    }
                else{  // 그렇지 않다면
                    push('A');  // push해주고
                    a++;   // A개수 증가 
                }
            }else if(tmp[i] == 'B'){
                if(b && top() == 'B'){
                        pop();
                        b--;
                    }
                else{
                    push('B');
                    b++;
                }
            }else{
                break;}
        }

        if(pos == 0)    cnt++;
    }

    printf("%d", cnt);
    return 0;
}

// #include <stdio.h>
// #include <stdbool.h>
// char dat[105];
// char tmp[105];
// int pos = 0;

// void push(char x){
//     dat[pos++] = x;
// }

// void pop(){
//     pos--;
// }

// char top(){
//     return dat[pos-1];
// }

// int size(){
//     return pos;
// }


// int main(){
    
//     while(true){
//         scanf("%[^\n]s", &tmp);
//         getchar();
//         if(tmp[0] == '.')   break;  // .하나 들어오면 종료

//         int i = 0;
//         bool judge = true;

//         while(tmp[i] != '.'){     // 그게 아니라면 판단시작 .하나 들어올때까지
//             if(tmp[i] == '(' || tmp[i] == '[')  push(tmp[i]);
//             else if(tmp[i] == ')'){
//                 if(top() != '('){
//                     judge = false;
//                     break;
//                 }
//                 pop();
//             }else if(tmp[i] == ']'){
//                 if(top() != '['){
//                     judge = false;
//                     break;
//                 }
//                 pop();
//             }
//             i++;
//         }    
        
//         if(size() != 0) judge = false;  //스택 안 비어있으면 false

//         if(judge)   printf("yes\n");    //판단에 따른 YES OR NO 출력
//         else        printf("no\n");

//         pos = 0;
//         judge = true;
//     }

//     return 0;
// }