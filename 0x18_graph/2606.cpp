#include <bits/stdc++.h>

using namespace std;
int n, m, cnt;
vector<int> adj[101];
queue<int> q;
bool visited[101];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = true;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto nxt : adj[cur]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
            cnt++;
        }
    }
    cout << cnt;
}