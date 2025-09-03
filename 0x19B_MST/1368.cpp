#include <bits/stdc++.h>
using namespace std;
int ans, n, cnt, weight;
vector<int> p(305, -1);
tuple<int, int, int> edge[46005];
int board[305][305];
int c[305];
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
    //     cout << "--root--\n";
    // for(int i = 1; i <= n+1; i++){
    //     cout << p[i] << " ";
    // }cout << "\n";
    return true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int min = 100001;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        edge[weight++] = {c[i], i+1, n+1};
    }       
    sort(c, c+n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            edge[weight++] = tie(board[i][j], i, j);
            //edge {간선,정점}
        }
    } 
    sort(edge, edge+weight);
    for(int i = 0; i < weight; i++){
        int w,a,b;
        tie(w,a,b) = edge[i];
        // cout << w << ", " << a << ", " << b << "\n";
    }
    for(int i = 0; i < weight; i++){
        int w,a,b;
        tie(w,a,b) = edge[i];
        
        if(!uni(a,b)) continue;
        ans += w;
        cnt++;
        if(cnt == n) break;
    }
    cout << ans;
}