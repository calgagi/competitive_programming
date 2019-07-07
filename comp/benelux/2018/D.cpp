// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool see;
    Node* r;
    Node* l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n; cin >> n >> a >> b;
    vector<Node*> m(n, NULL);
    int l, r, t;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> t;
        if (!m[i]) m[i] = new Node;
        m[i]->see = t;
        if (!m[l]) m[l] = new Node; 
        m[i]->l = m[l];
        if (!m[r]) m[r] = new Node;
        m[i]->r = m[r];
    }

    // BFS
    Node* startA = m[a], * startB = m[b];
    stack<pair<Node*, int> > sa;
    stack<pair<Node*, int> > sb;
    sa.push({startA, 0});
    sb.push({startB, 0});
    while (!sa.empty()) {
        startA = sa.top().first;
        a = sa.top().second;
        startB = sa.top().first;
        b = sa.top().second;
        sa.pop();
        sb.pop(); 
        if (startA->see != startB->see) {
            cout << a << endl; 
            return 0;
        }
        if (
    return 0;

}
