/*
위상정렬
교과목이수체계도느낌
방향 있는 그래프
*/ 
#include <bits/stdc++.h>
using namespace std;
int ans, edge, node;
vector<int> adj[101];
bool visited[101];
queue<int> q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = true;
            ans++;
        }
    }
    cout << ans;
}