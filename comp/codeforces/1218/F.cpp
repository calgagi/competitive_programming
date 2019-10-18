// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    ll n, k; cin >> n >> k;
    vector<pair<int,int> > gyms(n);
    for (int i = 0; i < n; i++)  
        cin >> gyms[i].first;
    int a; cin >> a;
    for (int i = 0; i < n; i++)
        cin >> gyms[i].second;
    
    ll res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {        
        pq.push(gyms[i].second);
        while (k < gyms[i].first) {
            k += a;
            if (pq.empty()) {
                cout << -1 << endl;
                return 0;
            }    
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << endl;

           

    return 0;
}
