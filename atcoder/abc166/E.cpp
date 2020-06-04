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
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto& i : A) {
        cin >> i;
    }

    map<ll,ll> past;
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ll search = (j+1) - A[j], x = A[j]+(j+1);
        ans += past[search];
        past[x]++;
    }

    cout << ans << endl;

    return 0;
}
