// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

long long num_intersects(vector<ii>& in, int l, int r) {
    if (l >= r) 
        return 0;

    int m = l + (r - l) / 2;
    long long ans = num_intersects(in, l, m) + num_intersects(in, m+1, r);

    vector<ii> left, right;
    for (int i = l; i <= m; i++)
        left.push_back(in[i]);
    for (int i = m+1; i <= r; i++)
        right.push_back(in[i]);
    
    int itr = 0, itl = 0;
    while (itr < (int) right.size() && itl < (int) left.size()) {
        int ql = left[itl].second, qr = right[itr].second;
        if (ql < qr) {
            in[itl+itr+l] = left[itl];
            itl++;
        } else {
            in[itl+itr+l] = right[itr];
            ans += (int) left.size() - itl; 
            itr++;
        }
    }

    while (itr < (int) right.size()) {
        in[itl+itr+l] = right[itr];
        itr++;
    }

    while (itl < (int) left.size()) {
        in[itl+itr+l] = left[itl];
        itl++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin >> n;
    vector<ii> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i].second;
    }  

    sort(in.begin(), in.end());
    
    cout << num_intersects(in, 0, n-1) << endl;

    return 0;
}
