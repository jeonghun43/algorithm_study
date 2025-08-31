#include <bits/stdc++.h>
using namespace std;
int n,m, cnt;
vector<int> adj[501];
int dist[501];
queue<int> q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    fill(dist+1, dist+501, -1);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            if(dist[cur] + 1 == 3){
                while(!q.empty()) q.pop();
                break;
            }
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            cnt++;
        }
    }
    cout << cnt;
}