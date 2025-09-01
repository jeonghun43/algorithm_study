#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> p(1000001, -1);
int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[u] < p[v]) swap(u,v);
    if(p[u] == p[v]) p[v]--;
    p[u] = v;
    return true;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, k, m;
        fill(p.begin(), p.end(), -1);
        cout << "Scenario " << i <<":\n";
        cin >> n >> k;
        while(k--){
            int u, v;
            cin >> u >> v;
            uni(u,v);
            // cout << "u : " << find(u) << "\nv : " << find(v) << "\n";
        }
        cin >> m;
        while(m--){
            int u, v;
            cin >> u >> v;
            u = find(u);
            v = find(v);
            // cout << "checking " << u << " " << v <<"\n";
            if(u == v) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
}