#include <bits/stdc++.h>
using namespace std;
int ans, v, e, cnt;
tuple<int,int,int> edge[100005];
vector<int> p(10005, -1);
int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(p[a] < p[b]) swap(a,b);
    if(p[a] == p[b]) p[b]--;
    p[a] = b;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int w,a,b;
        //문제를 잘 읽자
        //정점 a b 그리고 간선이 주어진다고 했는데
        //난 간선 먼저 주어지는줄..
        cin >> a >> b >> w;
        edge[i] = tie(w,a,b);
    }
    sort(edge, edge+e);
    for(int i = 0; i < e; i++){
        int w,a,b;
        tie(w,a,b) = edge[i];
        if(!uni(a,b)) continue;
        ans += w;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
}