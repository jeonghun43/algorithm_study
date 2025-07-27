// 7 비를 피하기
#include <bits/stdc++.h>
using namespace std;
int n, h, m;
int board[100][100];
int newboard[100][100];
int arrboard[100][100];
bool visited[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> q;
vector<pair<int,int>> humans;
vector<pair<int,int>> shelters;
bool OOB(int nx, int ny){
    if(nx < 0 || nx>=n || ny<0 || ny>=n) return true;
    return false;
}
void to_zero(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            //0 이동가능, 1 벽, 2 사람, 3 대피공간
            if(board[i][j] == 2) humans.push_back({i,j});
            if(board[i][j] == 3) shelters.push_back({i,j});
        }
    }
    for(int i = 0; i < m; i++){
        int x = shelters[i].first;
        int y = shelters[i].second;
        q.push({x,y});
        visited[x][y] = true;
    }
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(OOB(nx, ny)) continue;
                if(board[nx][ny] == 1 || visited[nx][ny]) continue;
                if(board[nx][ny] == 2){
                    newboard[nx][ny] = newboard[cur.first][cur.second] + 1;
                    visited[nx][ny] = true;
                }
                q.push({nx,ny});
                visited[nx][ny] = true;
                newboard[nx][ny] = newboard[cur.first][cur.second] + 1;
            }
    }
    for(int i = 0; i < h; i++){
        int x = humans[i].first;
        int y = humans[i].second;
        if(newboard[x][y] == 0) arrboard[x][y] = -1;
        else arrboard[x][y] = newboard[x][y];
    }
    // //사람부터 가는 것보다 쉘터를 기반으로 가는 게 훨씬 낫다
    // for(int i = 0; i < h; i++){
    //     to_zero();
    //     int x = humans[i].first; int y = humans[i].second;
    //     newboard[x][y] = 0;
    //     q.push({x, y});
    //     visited[x][y] = true;
    //     while(!q.empty()){
    //         pair<int, int> cur = q.front();
    //         q.pop();
    //         for(int dir = 0; dir < 4; dir++){
    //             int nx = cur.first + dx[dir];
    //             int ny = cur.second + dy[dir];
    //             if(OOB(nx, ny)) continue;
    //             if(board[nx][ny] == 1 || visited[nx][ny]) continue;
    //             if(board[nx][ny] == 3){
    //                 arrboard[x][y] = newboard[cur.first][cur.second] + 1;
    //                 while(!q.empty()){
    //                 q.pop();
    //                 }
    //                 break;
    //             }
    //             q.push({nx,ny});
    //             visited[nx][ny] = true;
    //             newboard[nx][ny] = newboard[cur.first][cur.second] + 1;
    //         }
    //     }
     
    //     if(arrboard[x][y] == 0) arrboard[x][y] = -1;
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arrboard[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// // 6 갈 수 있는 곳들
// #include <bits/stdc++.h>
// using namespace std;
// int n, k, ans;
// int board[100][100];
// queue<pair<int,int>> q;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1,0,-1,0};
// bool OOB(int nx, int ny){
//     if(nx < 0 || nx >= n || ny < 0 || ny >= n) return true;
//     return false;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> board[i][j];
//         }
//     }
//     for(int i = 0; i < k; i++){
//         int r, c;
//         cin >> r >> c;
//         r--; c--;
//         if(board[r][c] == 1) continue;
//         q.push({r,c});
//         board[r][c] = 1;
//         while(!q.empty()){
//             pair<int, int> cur = q.front();
//             ans++;
//             q.pop();
//             for(int dir = 0; dir < 4; dir++){
//                 int nx = cur.first + dx[dir];
//                 int ny = cur.second + dy[dir];
//                 if(OOB(nx,ny) || board[nx][ny] == 1) continue;
//                 q.push({nx,ny});
//                 board[nx][ny] = 1;
//             }
//         }
//     }
//     //0 : 이동가능 /  1 : 불가능
//     cout << ans;
//     return 0;
// }

// // 5 마을 사람
// #include <bits/stdc++.h>
// using namespace std;
// int n, vill_cnt;
// vector<int> vill_person;
// int board[25][25];
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// queue<pair<int, int>> q;
// bool OOB(int nx, int ny){
//     if(nx < 0 || nx >= n || ny < 0 || ny >= n) return true;
//     return false;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> board[i][j];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(board[i][j] == 0) continue;
//             int person_cnt = 1;
//             q.push({i, j});
//             board[i][j] = 0;
//             while(!q.empty()){
//                 pair<int , int> cur = q.front();
//                 q.pop();
//                 for(int dir = 0; dir < 4; dir++){
//                     int nx = cur.first + dx[dir];
//                     int ny = cur.second + dy[dir];
//                     if(OOB(nx, ny) || board[nx][ny] == 0) continue;
//                     person_cnt++;
//                     q.push({nx, ny});
//                     board[nx][ny] = 0;
//                 }
//             }
//             vill_person.push_back(person_cnt);
//         }
//     }
//     sort(vill_person.begin(), vill_person.end());
//     vill_cnt = vill_person.size();
//     cout << vill_cnt << "\n";
//     for(int i = 0; i < vill_cnt; i++){
//         cout << vill_person[i] << "\n";
//     }
//     return 0;
// }

// 2 3 4 두,네가지방향탐색 + 최단거리
// #include <bits/stdc++.h>
// using namespace std;
// int n, m, ans=0;
// queue<pair<int, int>> q;
// int board[100][100];
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// bool OOB(int nx, int ny){
//     if(nx < 0 || nx >= n || ny < 0 || ny >= m) return true;
//     return false;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> board[i][j];
//             if(board[i][j] == 0) board[i][j] = -1; //뱀
//             else board[i][j] = 0;   //빈공간
//         }
//     }
//     board[0][0] = 1;
//     q.push({0, 0});
//     while(!q.empty()){
//         pair<int, int> cur = q.front();
//         q.pop();
//         for(int dir = 0; dir < 4; dir++){
//             int nx = cur.first + dx[dir];
//             int ny = cur.second + dy[dir];
//             if(OOB(nx, ny) || board[nx][ny] == -1) continue;
//             if(board[nx][ny] >= 1) continue;
//             if(nx == n-1 && ny == m-1) {
//                 cout << board[cur.first][cur.second];
//                 return 0;
//             }
//             q.push({nx, ny});
//             board[nx][ny] = board[cur.first][cur.second] + 1;
//         }
//     }
//     cout << -1;
//     return 0;
// }

// 1 그래프탐색
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> adj[1001];
// queue<int> q;
// bool visited[1001];
// int n, m, cnt = 0;
// void DFS(int cur){
//     for(auto nxt : adj[cur]){
//         if(visited[nxt]) continue;
//         visited[nxt] = true;
//         cnt++;
//         DFS(nxt);
//     }
// }
// /*
// 1. bfs 큐 이용
// 2. dfs 스택이용
// 3. dfs 재귀이용
// 4. 부모정보이용 with 부모배열 or 그냥부모변수(no배열)
// */
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // q.push(1);
//     // visited[1] = true;
//     // while(!q.empty()){
//     //     int cur = q.front();
//     //     q.pop();
//     //     for(auto nxt : adj[cur]){
//     //         if(visited[nxt]) continue;
//     //         q.push(nxt);
//     //         visited[nxt] = true;
//     //         cnt++;
//     //     }
//     // }
//     visited[1] = true;
//     DFS(1);
//     cout << cnt;
//     return 0;
// }