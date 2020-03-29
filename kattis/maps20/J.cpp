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
using dd = long double;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    const dd M = 0.8, F = 0.2;

    int n;
    cin >> n;
    vector<dd> ans(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    dd full = 0;
    for (int i = 0; i < n; i++) {
        full += s[i] * pow(M, i);
    }
    full *= (dd) F;
    printf("%.*Lf\n",20,full);
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        dd m = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            ans[i] += s[j] * m;
            m *= M;
        }
        ans[i] *= F;
    }

    dd avg = 0;
    for (int i = 0; i < n; i++) {
        avg += ans[i];
    }
    avg /= (dd) n;
    cout << fixed << showpoint << setprecision(20);
    printf("%.*Lf\n",20,avg);
    cout << avg << endl;

    return 0;
}
