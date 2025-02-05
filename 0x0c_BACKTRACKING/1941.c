// 1941 소문난 칠공주
#include <stdio.h>
struct data{
    int x;
    int y;
};
char board[10][10];
int isused[30];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int allcnt = 0;
struct data q[1000000];
struct data stack[1000000];
int head = 0;
int tail = 0;
int top = 0;
void Stack_push(int x, int y){
    stack[top++] = (struct data){x,y};
}
struct data Stack_pop(){
    return stack[--top];
}
struct data Stack_top(){
    return stack[top-1];
}
void Queue_push(int x, int y){
    q[tail++] = (struct data){x, y};
}
struct data Queue_pop(){
    return q[head++];
}
int Queue_isempty(){
    if(tail - head == 0)    return 1;
    return 0;
}
int isnearby(){
    struct data first = Stack_top();
    int tmpcnt = 1;
    int stackVisited[10] = {};

    Queue_push(first.x, first.y);

    while(!Queue_isempty()){
        struct data cur = Queue_pop();
        for(int idx = 0; idx < 6; idx++){
            if(stackVisited[idx]) continue;
            for(int dir = 0; dir < 4; dir++){           //1 2 3 4 5 6 7
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)  continue;
            if(nx == stack[idx].x && ny == stack[idx].y){
                tmpcnt++;
                Queue_push(nx, ny);
                stackVisited[idx] = 1;
                }
            }
            
        }
    }
    head = 0;
    tail = 0;
    if(tmpcnt == 7) return 1;
    else            return 0;

}
void func(int k, int cnt_s, int cnt_y){
    if(cnt_s + cnt_y == 7){
        if(cnt_s < 4) 
            return;
        if(isnearby()){ 
            allcnt++;
    }
        return;
    }
    
    for(int a = k; a < 25; a++){
        if(isused[a])    continue;
        int i = a / 5;
        int j = a % 5;

        Stack_push(i, j);
        isused[a] = 1;

        if(board[i][j] == 'S')  func(a+1, cnt_s+1, cnt_y);
        else     func(a+1, cnt_s, cnt_y+1);

        isused[a] = 0;
        Stack_pop();
    }

}
int main(){
    for(int i = 0; i < 5; i++){
        scanf("%s", &board[i]);
    }

    func(0, 0 , 0);
    printf("%d", allcnt);
    return 0;
}