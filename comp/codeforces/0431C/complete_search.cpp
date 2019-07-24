// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;
    
    queue<pair<bool,int>> q;
    ll r = 0;
    bool f;
    int x;

    q.push({false, n});
    while (!q.empty()) {
        f = q.front().first;
        x = q.front().second;
        q.pop();
        if (f && x == 0) r = (r+1) % 1000000007;
        for (int i = 1; i <= min(k,x); i++) {
            if (i >= d || f) q.push({true, x-i});
            else q.push({false, x-i});
        }
    }
    cout << r << endl;
            
        



    return 0;
}
