#include <stdio.h>
//0x03기본문제 3273 두수의합
int main(void){
    int check[200000] = {};
    int n, x;
    int inputArr[100000];
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &inputArr[i]);
    }
    scanf("%d", &x);
    
    for(int i = 0; i < n; i++){
        int tmp = inputArr[i];
        if(tmp > x) continue;
        check[tmp]++;

        if(x - tmp == tmp) continue;
        if(check[x - tmp])  cnt++;
    }
    printf("%d", cnt);
    return 0;
}

// // 0x03기본문제 1475 방번호
// int main(void){
//     int input;
//     scanf("%d", &input);
//     int check[10]={};
//     int set = 1;
//     while(input >= 1){
//         int tmp = input % 10;
//         if(check[tmp] < set)
//             check[tmp]++;
//         else if(tmp == 6 || tmp == 9){
//             int idx = tmp == 6 ? 9 : 6;
//             if(check[idx] < set) check[idx]++;
//             else{
//                 check[tmp]++;
//                 set++;
//             }
//         }else{
//             check[tmp]++;
//             set++;
//         }
//         input /= 10;
//     }
//     printf("%d", set);
//     return 0;
// }

// //0x03기본문제 2577 숫자의개수
// int main(void){
//     int a,b,c, sum;
//     int cnt[10] = {};
//     scanf("%d", &a);
//     scanf("%d", &b);
//     scanf("%d", &c);
//     sum = a * b * c;
//     while(sum>=1){
//         cnt[sum % 10]++;
//         sum = sum / 10;
//     }

//     for(int i = 0; i < 10; i++){
//         printf("%d\n", cnt[i]);
//     }
//     return 0;
// }

// //0x01강의 연습문제 중... 문제2번 합이 100되는 게 있으면 1 반환하기
// int func2(int arr[], int N){
//     int check[101] = {};
//     for(int i = 0; i < N; i++){
//         int tmp = arr[i];
//         if(check[tmp] != 0)
//             return 1;
//         else{
//             check[tmp]++;
//             check[100-arr[i]]++;
//         }
//     }
//     return 0;
// }
// int main(void){
//     int arr[5] = {4,96,63,85,6};
//     printf("%d", func2(arr, 5));
//     return 0;
// }

// int main(void){
//     int arr[26] = {};
//     char str[100]= {};
//     scanf("%s", &str);
//     for(int i = 0; i < 100; i++){
//         if(str[i] == 0) break;
//         arr[str[i]-97]++;
//     }
//     for(int i = 0; i < 26; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;   
// }

// void insert(int idx, int num, int arr[], int* len){
//     for(int i = *len; i > idx; i--){
//         arr[i] = arr[i-1];
//     }
//     arr[idx] = num;

//     *len += 1;
// }

// void delete(int idx, int arr[], int * len){
//     for(int i = idx; i < *len-1; i++){
//         arr[i] = arr[i+1];
//     }
//     *len -= 1;
// }
// int main(void){
//     int arr[10];
    
//     // int arr[10] = {10, 50, 40, 30, 70, 20};
//     // int length = 6;
//     // int * len = &length;
//     // insert(3, 60, arr, len);
//     //  for(int i = 0; i < length; i++){
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("\n");
//     // delete(4, arr, len);

//     // for(int i = 0; i < length; i++){
//     //     printf("%d ", arr[i]);
//     // }
//     return 0;
// }
