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
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    bool ab = a==0;
    bool ac = a==0;
    bool bc = b==0;
    string s;
    vector<char> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "AB") {
            ans[i] = ab ? 'A' : 'B';
            if (ab) {
                a++, b--;
            } else {
                b++, a--;
            }
        } else if (s == "AC") {
            ans[i] = ac ? 'A' : 'C';
            if (ac) {
                a++, c--;
            } else {
                c++, a--;
            }
        } else if (s == "BC") {
            ans[i] = bc ? 'B' : 'C';
            if (bc) {
                b++, c--;
            } else {
                c++, b--;
            }
        }
        if (a == 1) {
            ac = 1;
            ab = 1;
        }
        if (b == 1) {
            ab = 0;
            bc = 1;
        }
        if (c == 1) {
            bc = 0;
            ac = 0;
        }
        if (min({a, b, c}) < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
 
    cout << "Yes" << endl;
    for (auto& x : ans) {
        cout << x << endl;
    }
 
    return 0;
}
