// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

int find(vector<int>& link, vector<int>& size, int a) {
    while (a != link[a]) {
        a = link[a];
    }
    return a;
}

void unite(vector<int>& link, vector<int>& size, int a, int b) {
    a = find(link, size, a);
    b = find(link, size, b);
    if (a == b) {
        return;
    }
    if (size[a] > size[b]) {
        swap(a, b);
    }
    link[a] = b;
    size[b] += size[a];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
   
    int n, m;
    cin >> n >> m;
    
    vector<int> link(n), size(n);
    for (int i = 0; i < n; i++) {
        link[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(link, size, a, b);
    }


    vector<int> cc;
    for (int i = 0; i < n; i++) {
        if (link[i] == i) {
            cc.push_back(i);
        }
    }
          
    cout << cc.size()-1 << endl;
    for (int i = 1; i < (int) cc.size(); i++) {
        cout << cc[0]+1 << " " << cc[i]+1 << endl;
    }

    return 0;
}
