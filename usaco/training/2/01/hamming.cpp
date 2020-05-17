/*
ID: calgagi1
LANG: C++
TASK: hamming
*/
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

int hamming(int a, int b) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if ((a & (1 << i)) != (b & (1 << i))) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("hamming.in", "r", stdin), *OUT = freopen("hamming.out", "w", stdout); 

    int n, b, d;
    cin >> n >> b >> d;

    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i < (1 << b); i++) {
        bool g = 1;
        for (int a : ans) {
            if (hamming(a, i) < d) {
                g = 0;
            }
        }
        if (g) {
            ans.push_back(i);
        }
    }

    int x = 0;
    //cerr << ans.size() << endl;
    for (int i = 0; i < ceil((double)n/10); i++) {    
        for (int j = 0; j < 10 && x < n; j++, x++) {
            cout << ans[x] << (j != 9 && x != n-1 ? " " : "");
        }
        cout << endl;
    }

    return 0;
}
