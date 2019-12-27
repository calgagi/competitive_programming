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
    vector<tuple<int,int,int>> p(n);
    for (auto& x : p)
        cin >> get<0>(x) >> get<1>(x) >> get<2>(x);

    // Simple algorithm: n^2
    //  For each point, find closest point
    //  How to remove other point though? erase
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {  
        if (used[i]) continue;
        int closest = i+1;
        double dist = 1e9;
        for (int j = i+1; j < n; j++) {
            if (used[j]) continue;
            double d = sqrt(pow(get<0>(p[j])-get<0>(p[i]), 2) +
                            pow(get<1>(p[j])-get<1>(p[i]), 2) +
                            pow(get<2>(p[j])-get<2>(p[i]), 2));
            if (d < dist) {
                closest = j;
                dist = d;
            }
        }
        cout << i+1 << " " << closest+1 << endl;
        used[i] = used[closest] = true;
    }

    return 0;
}
