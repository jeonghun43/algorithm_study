#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
queue<int> q;
int n,m,s;
bool visited[1001];
bool visitedDfs[1001];
void dfs(int cur){
    visitedDfs[cur] = true;
    cout << cur << " ";
    for(auto nxt : adj[cur]){
        if(visitedDfs[nxt]) continue;
        dfs(nxt);
    }
}
void bfs(int s){
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(auto nxt : adj[cur]){
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(s);    cout << "\n";
    bfs(s);
}