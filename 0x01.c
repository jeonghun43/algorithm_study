#include <stdio.h>
#include <stdbool.h>

void main(){
    int a = func4(97615282);
    printf("%d", a);
    // int a = func3(9);
    // printf("%d", a);
    // func3(693953651);
    // func3(756580036);

    // int arrB[3] = {1, 52, 48};
    // int arrC[2] = {50, 42};
    // int arrD[4] = {4, 13, 63, 87};
    // int b = func2(arrB, 3);
    // int c = func2(arrC, 2);
    // int d = func2(arrD, 4);
    // printf("%d\n", b);
    // printf("%d\n", c);
    // printf("%d\n", d);
}
int func4(int N){
    int a = 1; // 2의 거듭제곱수이니까 a=1로 해야겠네
    while(a * 2 <= N){
        a = a * 2;
    }
    return a;
}

int func3(int N){
    for(int i = 2; i * i <= N; i++){
        if(i * i == N) return 1;
    }
    return 0;

       // 밑에 코드처럼 하는 것보다는 N의 범위를 루트로 나눠주는게 훨씬 깔끔할듯 
    // int sqrArr[8] = {4, 9 , 16, 25, 36, 49, 64, 81};

    // for(int i = 0; i < 8; i++){
    //     if(N == sqrArr[i]) return 1;
    // }

    // for(int i = 2; i < N / 8; i++){
    //     if(N == i * i)  return 1;
    // }
    // return 0;
  
}

int func2(int arr[], int N){
    bool check = false;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(arr[i] + arr[j] == 100)  return 1;
        }
    }
    return 0;
}

int func1(int N){
    int sum = 0;
    for(int i = 1; i <= N; i++){
        if(i % 3 == 0) {
            sum += i;
            //printf("check : %d add\n", i);
            }
        else if(i % 5 == 0) {
            sum += i;
            //printf("check : %d add\n", i);
        }
    }
    return sum;
}

