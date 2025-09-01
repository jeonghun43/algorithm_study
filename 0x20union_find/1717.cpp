#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> p(1000001, -1);
int find(int x){
    // cout << "Start find " << x << "\n";
    if(p[x] <= -1) return x;
    return p[x] = find(p[x]);
}
bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[u] < p[v])
        swap(u, v);
    if(p[u] == p[v])
        p[v]--;
    p[u] = v;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int act, a, b;
        cin >> act >> a >> b;
        if(act == 0){
            // cout << "act 0 In " << m <<" " << a << " " << b << "\n"; 
            uni(a,b);
        }else if(act == 1){
            // cout << "act 1 In " << m <<" " << a << " " << b << "\n"; 
            a = find(a);
            b = find(b);
            // cout << "act 1-2 In " << m <<" " << a << " " << b << "\n"; 
            if(a==b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}