#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[1001];
vector<int> ans;
int deg[1001];
int line[1001];
queue<int> q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v, alln;
        cin >> alln;
        cin >> u;
        while(alln-- > 1){
            cin >> v;
            adj[u].push_back(v);
            deg[v]++;
            u = v;
        }
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
    if(ans.size() == n){
        for(auto num : ans){
            cout << num << "\n";
        }
    }
    else cout << "0";
}