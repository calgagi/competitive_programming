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

void solve() {
    int n;
    cin >> n;

    vector<ii> points;

    // start
    points.push_back({0, 0});

    // long row
    for (int i = 1; i <= 2*n; i++) {
        points.push_back({i, 0});
        // pegs coming from each 4-neighbor point
        if ((i & 1)) {
            points.push_back({i, 1});
            points.push_back({i, -1});
        }
    }

    // top left corner connector
    points.push_back({1, 2});
    points.push_back({0, 2});
    points.push_back({-1, 2});
    points.push_back({-1, 1});
    points.push_back({-1, 0});

    if (!(n & 1)) {
        // top right corner connector
        points.push_back({2*n+1, 0});
        points.push_back({2*n+1, 1});
        points.push_back({2*n+1, 2});
        points.push_back({2*n, 2});
        points.push_back({2*n-1, 2}); 
        
        // top connectors
        for (int i = 3; i < 2*n-3; i += 4) {
            points.push_back({i, 2});
            points.push_back({i+1, 2});
            points.push_back({i+2, 2});
        }
            
        // bottom connectors
        for (int i = 1; i < 2*n; i += 4) {
            points.push_back({i, -2});
            points.push_back({i+1, -2});
            points.push_back({i+2, -2}); 
        }

    } else {
        // bottom right corner connector
        points.push_back({2*n+1, 0});
        points.push_back({2*n+1, -1});
        points.push_back({2*n+1, -2});
        points.push_back({2*n, -2});
        points.push_back({2*n-1, -2}); 

        // top connectors
        for (int i = 3; i < 2*n; i += 4) {
            points.push_back({i, 2});
            points.push_back({i+1, 2});
            points.push_back({i+2, 2});
        }
            
        // bottom connectors
        for (int i = 1; i < 2*n-3; i += 4) {
            points.push_back({i, -2});
            points.push_back({i+1, -2});
            points.push_back({i+2, -2}); 
        }
    }


    
    cout << points.size() << endl;
    for (ii& point : points) {
        cout << point.f << " " << point.s << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
