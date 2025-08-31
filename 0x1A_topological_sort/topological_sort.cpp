#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
vector<int> ans;
int indegree[10];
queue<int> q;
int n;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    //a=1 b=2 c=3 d=4 e=5 f=6 g=7
    
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }
}