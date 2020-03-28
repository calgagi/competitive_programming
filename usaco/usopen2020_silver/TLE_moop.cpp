/*
ID: calgagi1
LANG: C++
TASK: moop
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

vector<int> link, big;

int find(int a) {
    while (a != link[a]) {
        a = link[a];
    }
    return a;
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return 0;
    }
    if (big[a] > big[b]) {
        swap(a, b);
    }
    link[a] = b;
    big[b] += big[a];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("moop.in", "r", stdin), *OUT = freopen("moop.out", "w", stdout); 

    const int Z = 1e9;
    int n;
    cin >> n;
    vector<ar<int,3>> p(n);
    for (auto& i : p) {
        cin >> i[1] >> i[2];
        i[1] += Z;
        i[2] += Z;
        i[0] = min(i[1], i[2]);
    }

    sort(p.begin(), p.end());

    link.resize(n);
    big.resize(n);
    for (int i = 0; i < n; i++) {
        link[i] = i;
        big[i] = 1;
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i][1] >= p[j][1] && p[i][2] >= p[j][2] && unite(i,j))
                ans--;
            } 
        }
    }

    cout << ans << endl;

    return 0;
}
