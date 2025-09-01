#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[32001];
vector<int> ans;
int deg[32001];
queue<int> q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    for(auto x : ans){
        cout << x << " "; 
    }
}