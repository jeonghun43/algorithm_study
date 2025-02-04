// 14956 Philosopher's Walk
#include <stdio.h>
struct data{
    int x;
    int y;
};
int n, m;
struct data func(int k, int val){
    if(k == 2){
        int onesize = (k / 2) * (k / 2);
        if(1 <= val && val <= onesize){  //3사분면   첫번째임
            return (struct data){1,1};
        }else if(onesize+1 <= val && val <= onesize*2){    //1사분면   두번째임
            return (struct data){1,2};
        }else if(2*onesize+1 <= val && val <= onesize*3){    //2사분면   세번째임
            return (struct data){2,2};
        }else if(3*onesize+1 <= val && val <= onesize*4){    //4사분면   네번째임
            return (struct data){2,1};
        }
    }
    int half = k/2;
    int onesize = half * half;
        if(1 <= val && val <= onesize){  //3사분면   첫번째임
            struct data tmp = func(k/2, val);
            return (struct data){tmp.y, tmp.x};
        }else if(onesize+1 <= val && val <= onesize*2){    //1사분면   두번째임
            val -= onesize;
            struct data tmp = func(k/2, val);
            return (struct data){tmp.x, half + tmp.y};
        }else if(2*onesize+1 <= val && val <= onesize*3){    //2사분면   세번째임
            val -= 2*onesize;
            struct data tmp = func(k/2, val);
            return (struct data){half + tmp.x,half + tmp.y};
        }else if(3*onesize+1 <= val && val <= onesize*4){    //4사분면   네번째임
            val -= 3*onesize;
            struct data tmp = func(k/2, val);
            return (struct data){2*half-tmp.y+1, half-tmp.x+1};
        }
}
int main(){
    scanf("%d %d", &n, &m);
    struct data ans = func(n, m);
    printf("%d %d", ans.x, ans.y);
    return 0;
}