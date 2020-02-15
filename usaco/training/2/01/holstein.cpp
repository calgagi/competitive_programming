/*
ID: calgagi1
LANG: C++
TASK: holstein
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

const int MAX_V = 25;
const int MAX_G = 15;
int G, V;
int req[MAX_V];
int feed[MAX_G][MAX_V];

ii dfs(int in, int s) {
    int a[MAX_V];
    memset(a, 0, sizeof(a));
    // Calc current feed
    int count = 0;
    for (int i = 0; i < G; i++) {
        if ((in & (1 << i))) {
            count++;
            for (int j = 0; j < V; j++) {
                a[j] += feed[i][j];
            }
            /* cerr << i << " "; */ 
        }
    } 
    /* cerr << endl; */
    // Check if everything above req
    bool good = true;
    for (int i = 0; i < V; i++) {
        if (a[i] < req[i]) {
            good = false;
            break;
        }
    }
    if (good) {
        return {count, in};
    }
    ii best = {INT_MAX, INT_MAX};
    for (int i = s; i < G; i++) {
        best = min(dfs((in | (1 << i)), i+1), best);
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("holstein.in", "r", stdin), *OUT = freopen("holstein.out", "w", stdout); 

    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> req[i];
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < V; j++) {
            cin >> feed[i][j];
        }
    }

    ii ans = dfs(0, 0);

    cout << ans.first << " ";
    for (int i = 0, f = 1; i < MAX_G; i++) {
        if ((ans.second & (1 << i))) {
            if (!f) {
                cout << " ";
            }
            cout << i+1;
            f = 0;
        }
    }
    cout << endl;
    
    return 0;
}
