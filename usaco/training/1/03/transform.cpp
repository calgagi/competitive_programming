/*
ID: calgagi1
LANG: C++
TASK: transform
*/

// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

int n;

bool equal(const vector<string>& a, const vector<string>& b) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

vector<string> rotate90(vector<string> a) { 
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n-i-1; j++) {
            char tl = a[i][j], tr = a[j][n-i-1], br = a[n-i-1][n-j-1], bl = a[n-j-1][i];
            a[i][j] = bl;
            a[j][n-i-1] = tl;
            a[n-i-1][n-j-1] = tr;
            a[n-j-1][i] = br;
        }
    }
    return a;
}

vector<string> reflect(vector<string> a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            swap(a[i][j], a[i][n-j-1]); 
        }
    }
    return a;
}

// DEBUG
void print(const vector<string>& r) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cerr << r[i][j];
        cerr << endl;
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("transform.in", "r", stdin), *OUT = freopen("transform.out", "w", stdout); 


    cin >> n;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i)
       cin >> a[i];
    for (int i = 0; i < n; ++i)
       cin >> b[i]; 
    
    // Check rotations
    vector<string> c = a;
    for (int i = 1; i <= 3; i++) {
        c = rotate90(c);
        if (equal(c, b)) {
            cout << i << endl;
            return 0;
        }
    }
    
    // Just reflection
    c = reflect(a);
    if (equal(b, c)) {
        cout << 4 << endl;
        return 0;
    }


    // Reflection + rotation
    for (int i = 1; i <= 3; i++) {
        c = rotate90(c);
        if (equal(c, b)) {
            cout << 5 << endl;
            return 0;
        }
    }

    // No change
    if (equal(a,b)) {
        cout << 6 << endl;
        return 0;
    }
    
    // Not valid
    cout << 7 << endl;
    return 0;
}
