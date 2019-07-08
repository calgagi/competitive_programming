// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool see;
    Node* r;
    Node* l;
    int i;
};

int find(vector<int>& u, int a) {
    while (u[a] != a) a = u[a];
    return a;
}

void unite(vector<int> &u, int x, int y) {
    int xset = find(u, x);
    int yset = find(u, y);
    if (xset != yset) {
        u[xset] = yset;
    }
    return;
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
        m[i]->i = i;
        if (!m[l]) m[l] = new Node; 
        m[i]->l = m[l];
        if (!m[r]) m[r] = new Node;
        m[i]->r = m[r];
    }

    // BFS
    Node* startA = m[a], * startB = m[b];
    queue<tuple<Node*, Node*, int> > sa;
    sa.push(make_tuple(startA, startB, 0));
    vector<int> u(n);
    for (int i = 0; i < n; i++) u[i] = i;
    int i = n-1;
    while (i && sa.size()) {
        startA = get<0>(sa.front());
        startB = get<1>(sa.front()); 
        a = get<2>(sa.front());
        sa.pop();
        if (startA->see ^ startB->see) {
            cout << a << endl; 
            return 0;
        }
        if (find(u, startA->i) == find(u, startB->i)) continue;
        unite(u, startA->i, startB->i); 
        sa.push(make_tuple(startA->l, startB->l, a+1));
        sa.push(make_tuple(startA->r, startB->r, a+1));
        i--;
    }
    cout << "indistinguishable" << endl;
    return 0;

}
