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
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // calculate log base 2
    vector<int> l(n+1);
    l[1] = 0;
    for (int i = 2; i <= n; i++) {
        l[i] = l[i/2]+1;
    }

    // calculate sparse table
    vector<vector<int>> rmq(n, vector<int>(l[n]+1));
    for (int j = 0; j < n; j++) {
        rmq[j][0] = A[j];
    }

    for (int j = 1; j <= l[n]; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }

    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        int D = R-L+1;
        cout << min(rmq[L][l[D]], rmq[R-(1<<l[D])+1][l[D]]) << endl;
    }
        

    return 0;
}
