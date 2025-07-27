#include <bits/stdc++.h>
/*
구슬 이동
생존 구슬 업데이트
T초만큼 반복

남은 구슬개수 출력
*/
using namespace std;

int n, m, t, k;
int board[50][50];
int r[2500], c[2500];
char d[2500];
int dir[2500];
int v[2500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void move(){
    int newboard[50][50] = {};
    for(int i = 0; i < m; i++){
        if(r[i] == -1) continue;
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = newboard[i][j];
        }
    }
}
void update(){
    vector<pair<int, int>> beads;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] > k){
                for(int a = 0; a < m; a++){
                    if(r[a] == i && c[a] == j)  beads.push_back({a, v[a]});                
                }
                stable_sort(beads.begin(), beads.end(),[](auto& a, auto& b){return a.second < b.second;});
                int del = beads.size()-k;
                for(int idx = 0; idx < del; idx++){
                    pair<int, int> tmp = beads.at(idx);
                    r[tmp.first] = -1; c[tmp.first] = -1;
                }
            }
        }
    }
}
int main() {
    cin >> n >> m >> t >> k;
    int tmp['Z'];
    tmp['R'] = 0;
    tmp['D'] = 1;
    tmp['L'] = 2;
    tmp['U'] = 3;
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> v[i];
        r[i]--; c[i]--;
        dir[i] = tmp[d[i]];
    }
    vector<pair<int,int>> bs = {
        {1, 5},
        {2, 3},
        {3, 5},
        {4, 20}
    };

    // Please write your code here.
    // while(t--){
    //     move();
    //     update();
    // }
    // int ans = 0;
    // for(int i = 0; i < m; i++){
    //     if(r[i] == -1) ans++;
    // }
    // cout << ans;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n, m, r, c, cnt = 0;
// int board[100][100];
// bool visit[100][100];
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// queue<pair<int, int>> q;
// bool OOB(int nx, int ny){
//     if(nx < 0 || nx >= n || ny < 0 || ny >= n) return true;
//     return false;
// }
// void push_in_the_queue(){
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(board[i][j] == 1){
//                 q.push({i,j});
//                 visit[i][j] = true;
//             }
//         }
//     }
// }
// int main() {
//     cin >> n >> m >> r >> c;
//     // Please write your code here.
//     r--; c--;
//     board[r][c] = 1; cnt++;   
//     for(int time = 1; time <= m; time++){
//         push_in_the_queue();
//         while(!q.empty()){
//             pair<int, int> cur = q.front();
//             q.pop();
//             for(int dir = 0; dir < 4; dir++){
//                 int nx = cur.first + dx[dir] * time;
//                 int ny = cur.second + dy[dir] * time;
//                 if(OOB(nx, ny)) continue;
//                 if(visit[nx][ny]) continue;
//                 board[nx][ny] = 1;
//                 cnt++;
//                 visit[nx][ny] = true;
//             }
//         }
//     }  
//     cout << cnt;
//     return 0;
// }


// // // // #include <iostream>
// // // // using namespace std;
// // // // int N;
// // // // int grid[20][20];
// // // // int main() {
// // // //     int cnt=0;
// // // //     cin >> N;
// // // //     for (int i = 0; i < N; i++) {
// // // //         for (int j = 0; j < N; j++) {
// // // //             cin >> grid[i][j];
// // // //         }
// // // //     }
// // // //     // Please write your code here.
// // // //     for(int i = 0; i < N-2; i++){
// // // //         for(int j = 0; j < N-2; j++){
// // // //             int tmp = 0;
// // // //             for(int a = i; a <= i+2; a++){
// // // //                 for(int b = j; b <= j+2; b++){
// // // //                     tmp += grid[a][b];
// // // //                 }
// // // //             }
// // // //             if(tmp > cnt) cnt = tmp;
// // // //         }
// // // //     }
// // // //     cout << cnt;
// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // using namespace std;
// // // int n, t;
// // // int u[200];
// // // int d[200];
// // // int main() {
// // //     cin >> n >> t;
// // //     for (int i = 0; i < n; i++) cin >> u[i];
// // //     for (int i = n-1; i >= 0; i--) cin >> d[i];
// // //     // Please write your code here.
// // //     for(int i = 0; i < t; i++){
// // //         int tmp;
// // //         tmp = u[n-1];
// // //         for(int i = n-1; i > 0; i--){
// // //             u[i] = u[i-1];
// // //         }
// // //         u[0] = d[0];
// // //         for(int i = 0; i < n-1; i++){
// // //             d[i] = d[i+1];
// // //         }
// // //         d[n-1] = tmp;
// // //     }
// // //     for(int i = 0; i < n; i++){
// // //         cout << u[i] << " ";
// // //     }
// // //     cout << "\n";
// // //     for(int i = n-1; i >= 0; i--){
// // //         cout << d[i] << " ";
// // //     }
// // //     return 0;
// // // }

// // #include <iostream
// // using namespace std;
// // int n;
// // int blocks[101];
// // int s1, e1;
// // int s2, e2;
// // int main() {
// //     int minus;
// //     cin >> n;
// //     for (int i = 1; i <= n; i++) {
// //         cin >> blocks[i];
// //     }
// //     cin >> s1 >> e1;
// //     cin >> s2 >> e2;
// //     minus = e1 - s1 + 1;
// //     // Please write your code here.
// //     for(int i = e1+1; i <= n; i++){
// //         blocks[s1++] = blocks[i];
// //     }
// //     n -= minus;
// //     minus = e2 - s2 + 1;
// //      for(int i = e2+1; i <= n; i++){
// //         blocks[s2++] = blocks[i];
// //     }
// //     n -= minus;
// //     cout << n << endl;
// //     if(n == 0) return 0;
// //     for(int i = 1; i <= n; i++)
// //         cout << blocks[i] << endl;
// //     return 0;
// // }
