#include <bits/stdc++.h>

using namespace std;
int n, m, v;
vector<int> adj[1001];
queue<int> q;
bool visitq[1001];
bool visitd[1001];
void dfs(int cur){
    visitd[cur] = true;
    cout << cur << " ";
    for(auto nxt : adj[cur]){
        if(visitd[nxt]) continue;
        dfs(nxt);
    }
}
void bfs(int c){
    q.push(c);
    visitq[c] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for(auto nxt : adj[cur]){
            if(visitq[nxt]) continue;
            q.push(nxt);
            visitq[nxt] = true;
        }
    }
}
int main(){
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //정렬
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
    return 0;
}