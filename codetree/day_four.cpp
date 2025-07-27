#include <bits/stdc++.h>

using namespace std;

int n, sum, bsum, ans;
int num[20];
int arr[10];
bool visited[20];
int dif(int a, int b){
    if(a >= b) return a - b;
    return b-a;
}
void recur(int cur){
    if(cur == n){
        int asum = sum - bsum;
        int diff = dif(asum, bsum);
        if(ans > diff) ans = diff;
        return;
    }
    for(int i = 0; i < 2*n; i++){
        if(visited[i]) continue;
        arr[cur] = num[i];
        bsum += num[i];
        visited[i] = true;
        recur(cur+1);
        bsum -= num[i];
        visited[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    // Please write your code here.
    ans = sum;
    recur(0);
    cout << ans;
    return 0;
}

// // N자리 수를 구하고 해당 수에서 아름다운 수 카운트
// #include <iostream>
// using namespace std;
// int n, cnt = 0;
// int arr[15];
// void check(){
//     bool flag = true;
//     int i = 0;
//     while(i < n){
//         if(arr[i] == 1){
//             i++;
//             continue;
//         }else if(arr[i] == 2){
//             if(arr[i] != arr[i+1]) {
//                 flag = false;
//                 return;
//             }
//             i += 2;
//         }else if(arr[i] == 3){
//             if(arr[i] != arr[i+1] || arr[i] != arr[i+2]) {
//                 flag = false;
//                 return;
//             }
//             i += 3;
//         }else if(arr[i] == 4){
//              if(arr[i] != arr[i+1] || arr[i] != arr[i+2] || arr[i] != arr[i+3]) {
//                 flag = false;
//                 return;
//             }
//             i += 4;
//         }
//     }
//     cnt++;
// }
// void recur(int cur){
//     if(cur == n){
//         check();
//         return;
//     }
//     for(int i = 1; i <= 4; i++){
//         if(i >= 1 && cur != 0)
//         arr[cur] = i;
//         recur(cur+1);
//     }
// }
// int main() {
//     cin >> n;
//     // Please write your code here.
//     recur(0);
//     cout << cnt;
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int n, ans = 0;
// int arr[10];
// int info[5];
// bool check(){
//     int i = 0;
//     while(i < n){
//         if(arr[i] == 1){
//             i++;
//             continue;
//         }else if(arr[i] == 2){
//             if(arr[i] != arr[i+1]) {
//                 return false;
//             }
//             i += 2;
//         }else if(arr[i] == 3){
//             if(arr[i] != arr[i+1] || arr[i] != arr[i+2]) {
//                 return false;
//             }
//             i += 3;
//         }else if(arr[i] == 4){
//              if(arr[i] != arr[i+1] || arr[i] != arr[i+2] || arr[i] != arr[i+3]) {
//                 return false;
//             }
//             i += 4;
//         }
//     }
//     return true;
// }
// void recur(int cur){
//     if(cur == n){
//         if(check()) ans++;
//         return;
//     }
//     for(int i = 1; i <= 4; i++){
//         if(cur != 0 && i!= 1 && info[arr[cur-1]] < arr[cur-1]){
//             if(i != arr[cur-1]) continue;
//         }
//         arr[cur] = i;
//         info[i]++;
//         recur(cur+1);
//         info[i]--;
//     }
// }
// int main() {
//     cin >> n;

//     // Please write your code here.
//     recur(0);
//     cout << ans;
//     return 0;
// }
