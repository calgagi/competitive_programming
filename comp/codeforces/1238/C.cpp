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
	
    int t; cin >> t;
    for (int Q = 0; Q < t; Q++) {
        int h, n;
        cin >> h >> n;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        q.push(0);
        q.pop();

        int res = 0;
        while (!q.empty() && h > 0) {
            int k = q.front();
            if (h - k >= 2)
                h = k+1;
            else {
                q.pop();
                if (h - q.front() > 2) {
                    res++;
                } else {
                    q.pop();
                }
                h -= 2;
            }
        }
        cout << res << endl;
    } 
        

    return 0;
}
