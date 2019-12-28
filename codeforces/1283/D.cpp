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

    int n, m; cin >> n >> m;
    vector<int> trees(n);
    set<int> seen;
    for (auto& i : trees) { 
        cin >> i;
        seen.insert(i);
    }

    vector<int> people;
    long long ans = 0;
    queue<pair<int,int>> q;
    
    for (int i = 0; i < n; i++) {
        q.push({trees[i]-1, 1});
        q.push({trees[i]+1, 1}); 
    }
    while ((int) people.size() < m) {
        pair<int,int> p = q.front();
        q.pop();
        if (seen.find(p.first) == seen.end()) {
            seen.insert(p.first);
            people.push_back(p.first);
            ans += p.second;
            if (seen.find(p.first+1) == seen.end())
                q.push({p.first+1, p.second+1});
            if (seen.find(p.first-1) == seen.end())
                q.push({p.first-1, p.second+1});
        }
    }

    cout << ans << endl;
    for (auto& item : people) cout << item << " ";
    cout << endl;
    
    return 0;
}
