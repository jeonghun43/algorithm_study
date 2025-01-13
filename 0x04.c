// 1158 요세푸스
#include <stdio.h>
    int dat[5005];
    int nxt[5005];
    int pre[5005];
    int cur = 1;
void delete(int cur){
    if(pre[cur] != -1) nxt[pre[cur]] = nxt[cur];
    if(nxt[cur] != -1) pre[nxt[cur]] = pre[cur];
}

int main(void){
    
    int N, K;

    scanf("%d %d", &N, &K);

    for(int i = 0; i < 5005; i++){
        dat[i] = -1;
        nxt[i] = -1;
        pre[i] = -1;
    }
    for(int i = 1; i <= N; i++){
        dat[i] = i;
        pre[i] = i-1;
        if(i == N) {
            nxt[i] = 1;
            break;
        }
        nxt[i] = i+1;
    }
    pre[1] = N;
    printf("<");
    while(N > 0){
        int tmp = 0;
        for(int i = 1; i < K; i++){
            cur = nxt[cur];
        }
        tmp = dat[cur];
        delete(cur);
        cur = nxt[cur];
        if(N-1 == 0)    printf("%d>", tmp);
        else    printf("%d, ", tmp);
        N--;
    }
    return 0;
}

// //5397 키로거
// #include <stdio.h>

// char str[1000005];
// char answer[1000005];
// int nxt[1000005];
// int pre[1000005];
// int cur=0;
// int unused=1;
// int main(void){
//     int T;
//     scanf("%d", &T);
    
//     while(T > 0){
//         cur = 0;
//         unused = 1;
//         int len = 0;
//         scanf("%s", &str);
//         for(int i = 0; i < 1000005; i++){
//             nxt[i] = -1;
//             pre[i] = -1;
//         }

//         for(int i = 0; i < 1000005; i++){
//             if(str[i] == '\0') break;
//             else len++;
//         }
//         for(int i = 0; i < len; i++){
//             if(str[i] == '-'){
//                 if(pre[cur] == -1)  continue;
//                 nxt[pre[cur]] = nxt[cur];
//                 if(nxt[cur] != -1)  pre[nxt[cur]] = pre[cur];
//                 cur = pre[cur];
//             }else if(str[i] == '>'){
//                 if(nxt[cur] != -1) cur = nxt[cur];
//             }else if(str[i] == '<'){
//                 if(pre[cur] != -1) cur = pre[cur];
//             }else{
//                 answer[unused] = str[i];
//                 pre[unused] = cur;
//                 if(nxt[cur] != -1)pre[nxt[cur]] = unused;
//                 nxt[unused] = nxt[cur];
//                 nxt[cur] = unused;
//                 cur = unused;
//                 unused++;
//             }
//         }
//         int idx = nxt[0];
//         while(idx != -1){
//             printf("%c", answer[idx]);
//             idx = nxt[idx];
//         }
//         printf("\n");
//         T--;
//     }
//     return 0;
// }

// // 1406 에디터
// #include <stdio.h>
//     char str[600005];           //이런 것처럼 범위가 큰 배열들은 전역변수에다가 선언해줘야함
//     int nxt[600005] = {};       //main() 함수처럼 함수에다가 선언하면 터진다
//     int pre[600005] = {};       
// int main(){
//     int cur = 1;
//     int unused = 1;
//     int N = 0;
//     scanf("%s", &str[1]);
//     scanf("%d", &N);
//     getchar();
//     for(int i = 0; i < 600005; i++){    //pre nxt 모든 값을 -1로 초기화
//         nxt[i] = -1;
//         pre[i] = -1;
//     }
//         nxt[0] = 1;                     //0번 노드는 더미 노드. 더미노드의 nxt를 1로 설정

//     for(int i = 1; i < 600005; i++){    //입력 받은 문자열에 대한 pre nxt 값 설정해주기
//         pre[i] = i-1;
//         unused++;
//         if(str[i+1] >= 97 && str[i+1] <= 122) {
//             nxt[i] = i+1; //다시보니 이거 잘못된듯. 다음 값 없을때도 nxt[i]값이 초기화 되버리니까 땡
//             cur++;
//         }
//         else break;
//     }
//     for(int i = 0; i < N; i++){         //커맨드를 입력받음
//         char command;
//         char tmp;
//         scanf("%c", &command);
//         getchar();
//         switch (command)                //입력받은 커맨드에 따라 실행
//         {
//         case 'L' :                      //커서를 왼쪽으로 옮김
//             if(pre[cur] != -1)  cur = pre[cur];  //문장 맨 앞이면 안 함
//             break;
//         case 'D':                       //커서를 오른쪽으로 옮김
//             if(nxt[cur] != -1)  cur = nxt[cur]; //문장 맨 뒤면 안 함
//             break;
//         case 'B':
//             if(pre[cur] == -1) break;         //커서 맨 앞이면 안 함
//             nxt[pre[cur]] = nxt[cur];    //왼쪽 데이터 nxt 값을 업데이트
//             if(nxt[cur] != -1) pre[nxt[cur]] = pre[cur];   //오른쪽 데이터 pre 값을 업데이트
//             cur = pre[cur];                      //커서 정보 업데이트
//             break;
//         case 'P':
//             scanf("%c", &tmp);
//             getchar();
//             str[unused] = tmp;              //데이터를 넣어줌
//             nxt[unused] = nxt[cur];         //새로운 데이터 nxt값을 오른쪽 주소로
//             if(nxt[cur] != -1){
//                 pre[nxt[cur]] = unused;     //오른쪽 데이터 pre값을 새로운 데이터 주소로
//                 }  
//             nxt[cur] = unused;              //왼쪽   데이터 nxt값을 새로운 데이터 주소로
//             pre[unused] = cur;              //새로운 데이터 pre값을 왼쪽 주소로
              
//             cur = nxt[cur];  //커서 위치 업데이트
//             unused++;
//             break;
//         }
//     }
//     int idx = nxt[0];
//     while(idx != -1){
//         printf("%c", str[idx]);
//         idx = nxt[idx];
//     }
//     return 0;
// }

// // 야매 연결리스트 insert함수 erase함수 구현
// #include <stdio.h>
// const int MX = 1000005;
// int dat[1000005] = {};
// int pre[1000005] = {};
// int nxt[1000005] = {};
// int unused = 1;

// void insert(int addr, int num){
//     dat[unused] = num;
//     nxt[unused] = nxt[addr];
//     pre[unused] = addr;
//     if(nxt[addr] != -1) pre[nxt[addr]] = unused; // 이 조건은 생각도 못했는데 ㅎ 근데 배열 음수 인덱스가 있네요?? 뭐지
//     nxt[addr] = unused;

    
//     unused++;
// }

// void erase(int addr){
//     int left = pre[addr];
//     int right = nxt[addr];
//     nxt[left] = right;
//     if(right != -1) pre[right] = left;
//     dat[addr] = -1;
//     pre[addr] = -1;
//     nxt[addr] = -1;
// }

// void traverse(){
//   int cur = nxt[0];
//   while(cur != -1){
//     printf("%d ", dat[cur]);
//     cur = nxt[cur];
//   }
//   printf("\n\n");
// }

// void insert_test(){
//   printf("****** insert_test *****\n");
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
// }

// void erase_test(){
//   printf("****** erase_test *****\n");
//   erase(1); // 30 40 20 70
//   traverse();
//   erase(2); // 40 20 70
//   traverse();
//   erase(4); // 40 70
//   traverse();
//   erase(5); // 40
//   traverse();
// }

// int main(void) {
// for(int i = 0; i < MX; i++){
//     pre[i] = -1;
//     nxt[i] = -1;
// }
//   insert_test();
//   erase_test();

// }

// 야매 연결리스트 traverse함수 구현 : 모든 원소들을 출력하는 함수
// #include <stdio.h>
//     int dat[10] = {};
//     int pre[10] = {};
//     int nxt[10] = {};

// void traverse(){
//     int cur = nxt[0];
//     while(cur != -1){
//         printf("%d ", dat[cur]);
//         cur = nxt[cur];
//     }
// }
// int mytraverse(int idx){ // wow 재귀로 하는거 생각해봤는데 된다
//     if(dat[idx] == -1){
//         mytraverse(nxt[idx]);
//     }else{
//         printf("%d ", dat[idx]);
//         if(nxt[idx] == -1)  return 0;
//         mytraverse(nxt[idx]);
//     }
//     return 0;
// }
// int main(void){
//     dat[0] = -1;
//     dat[1] = 65;
//     dat[2] = 13;
//     dat[4] = 21;
//     dat[5] = 17;

//     pre[0] = -1;
//     pre[1] = 2;
//     pre[2] = 0;
//     pre[4] = 1;
//     pre[5] = 4;

//     nxt[0] = 2;
//     nxt[1] = 4;
//     nxt[2] = 1;
//     nxt[4] = 5;
//     nxt[5] = -1;

//     traverse();
//     printf("\n____________________\n");
//     mytraverse(0);
//     return 0;
// }