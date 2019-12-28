// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<int> f(n), e;
    vector<bool> given(n, false);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
        if (f[i] != -1)
            given[f[i]] = true;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!given[i]) q.push(i);
    
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (f[i] == -1) {
            f[i] = q.front();
            q.pop();
            if (f[i] == i && prev == -1) {
                q.push(f[i]);
                f[i] = q.front();
                q.pop();
            } else if (f[i] == i && prev != -1) {
                swap(f[i], f[prev]);
            }
            prev = i;
        }
    }

    for (auto& i : f) cout << i+1 << " ";
    cout << endl;

    return 0;
}
