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
    
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        
        if (x2-x1 == 0 && (a || b)) {
            cout << "No" << endl;
            continue;
        } else if (y2-y1 == 0 && (c || d)) {
            cout << "No" << endl;
            continue;
        } 
        ll dx = b-a, dy = d-c;
        //cout << dx+x << " " << dy+y << endl;
        if (x1 <= dx+x && x2 >= dx+x && y1 <= dy+y && y2 >= dy+y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
        

    return 0;
}
