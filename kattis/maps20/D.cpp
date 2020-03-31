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
    
    int N;
    cin >> N;
    cout << fixed << showpoint << setprecision(20);

    while (N--) {
        dd n, l, d, g;
        cin >> n >> l >> d >> g;
        dd ans = n * pow(l,2) * ((cos((dd)M_PI/n)/sin((dd)M_PI/n)) / (dd)4);
        dd r = g*d;
        // rectangles
        ans += n * r * l; 
        // circle
        ans += (dd) M_PI * pow(r,2);
        cout << ans << endl;
    }
    return 0;
}
