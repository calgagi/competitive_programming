/*
 * author: calgagi
 *         Calvin Gagliano 
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    // sparse table
    
    const int K = (int) (log(n)/log(2)) + 1;
    vector<vector<int>> st(n, vector<int>(K));
    
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int x = log(b-a+1)/log(2);
        cout << min(st[a][x], st[b - (1 << x) + 1][x]) << endl;
    }



    return 0;
}
