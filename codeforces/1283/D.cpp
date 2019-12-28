// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    // Greedy?
    //  Find all points 1 spot away from xmas trees, 2 spots, etc.
    //  Basic n^2 solution not fast enough
    //  Priority queue = not fast enough because 10^9 space needed
    //
    //  For each distance 1..2..3, use hashmap to see if taken.
    //  Loop through each tree

    int n, m; cin >> n >> m;
    vector<int> trees(n);
    for (auto& i : trees) { 
        cin >> i;
    }
    
    int dist = 1;
    vector<int> people(m);

    sort(trees.begin(), trees.end());


    int j = 0, ans = 0;
    while (j < m) {
        people[j++] = trees[0]-dist;
        ans += dist;
        if (j < m) {
            people[j++] = trees[(int)trees.size()-1]+dist;
            ans += dist;
        }
        if (j < m) {
            for (int i = 1; i < (int)trees.size(); i++) {
                if (trees[i-1] + dist < trees[i] - dist) {
                    people[j++] = trees[i-1]+dist;
                    ans += dist;
                    if (j < m) {
                        people[j++] = trees[i]-dist;
                        ans += dist;
                    }
                } else if (trees[i-1] + dist == trees[i] - dist) {
                    people[j++] = trees[i-1]+dist;
                    ans += dist;
                } else if ((int)trees.size() > 2) {
                    if (i == 1) {
                        trees.erase(trees.begin()+i);
                        i--;
                    } else {
                        trees.erase(trees.begin()+i-1);
                        i--;
                    }
                }
            }
        }
        dist++;
    }

            

    cout << ans << endl;
    for (auto& i : people) cout << i << " ";
    cout << endl; 


    return 0;
}
