/*
ID: calgagi1
LANG: C++
TASK: combo
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


set<array<int,3>> seen;
int n;

void calculate(array<int,3> l) {
    for (int i = 0; i < 3; i++) {
        l[i] -= 2;
        while (l[i] < 0) {
            l[i] += n;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                seen.insert({(l[0]+i)%n, (l[1]+j)%n, (l[2]+k)%n});
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("combo.in", "r", stdin), *OUT = freopen("combo.out", "w", stdout); 


    cin >> n;
    array<int, 3> a, b;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
        b[i]--;
    }

    calculate(a);
    calculate(b);

    cout << seen.size() << endl;

    return 0;
}
