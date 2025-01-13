//1874 스택수열
#include <stdio.h>
#include <stdbool.h>
int k;
int dat[100001];
int pos = 0, num=1;
int indexInt = 0;
char answer[200001] ;
bool flag = true;
int N;

void push(int x){
    dat[pos++] = x;
}

int pop(){
    if(pos == 0) return -1;
    pos--;
    return dat[pos];
}

int top(){
    if(pos == 0) return -1;
    return dat[pos-1];
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){

        scanf("%d", &k);

        if(num <= k){
            while(num <= k){
                push(num++);
                answer[indexInt++] = '+';
            }
        }

        if(top() == k){
            pop();
            answer[indexInt++] = '-';
        }else{
            printf("NO");
            flag = false;
            break;
        }
    }
if(flag){
    for(int i = 0; i < indexInt; i++){
        printf("%c\n", answer[i]);
    }
}
    return 0;
}

// // 10773 제로
// #include <stdio.h>
// int dat[100005];
// int pos = 0;

// void push(int x){
//     dat[pos++] = x;
// }
// void pop(){
//     pos--;
// }
// void sum(){
//     int sum = 0;
//     int size = pos;
//     for(int i = 0; i < size; i++){
//         sum += dat[pos-1-i];
//     }
//     printf("%d", sum);
// }

// int main(void){
//     int K;
//     scanf("%d", &K);

//     while(K > 0){
//         int tmp;
//         scanf("%d", &tmp);
//         if(tmp == 0) pop();
//         else    push(tmp);
//         K--;
//     }
//     sum();
//     return 0;
// }

// // 10828 스택
// #include <stdio.h>
// int dat[100005];
// int pos = 0;

// void push(int x){
//     dat[pos++] = x;
// }

// void pop(){
//     if(pos == 0)   
//         printf("-1\n");
//     else {
//         printf("%d\n", dat[pos-1]);
//         pos--;
//         }

// }

// void top(){
//     if(pos == 0) printf("-1\n");
//     else    printf("%d\n", dat[pos-1]);
// }

// int main(void){
//     int N;
//     scanf("%d", &N);
//     while(N > 0){
//         char str[6];
//         int tmp;
//         scanf("%s", &str);

//         if(str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h'){
//             scanf("%d", &tmp);
//             push(tmp);
//         }else if(str[0] == 'p' && str[1] == 'o' && str[2] == 'p'){
//             pop();
//         }else if(str[0] == 's' && str[1] == 'i' && str[2] == 'z' && str[3] == 'e' ){
//             printf("%d\n", pos);
//         }else if(str[0] == 'e' && str[1] == 'm' && str[2] == 'p' && str[3] == 't' && str[4] == 'y'){
//             if(pos == 0) printf("1\n");
//             else    printf("0\n");
//         }else{
//             top();
//         }

//         N--;
//     }
// }