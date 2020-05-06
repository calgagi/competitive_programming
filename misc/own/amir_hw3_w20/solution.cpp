// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

struct DisjointSetUnion {
    vector<int> size;
    vector<int> link;

    int num_components;
    ll mst_weight;

    DisjointSetUnion(int n) {
        size.resize(n);
        link.resize(n);
        for (int i = 0; i < n; i++) {
            link[i] = i;
            size[i] = 1;
        }
        num_components = n;
        mst_weight = 0;
    }

    int find(int a) {
        while (a != link[a]) {
            a = link[a];
        }
        return a;
    }

    void unite(int a, int b, int w = 0) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (size[b] < size[a]) {
            swap(a, b);
        }
        mst_weight += w;
        num_components--;
        link[a] = b;
        size[b] += size[a];
    }
};

struct edge {
    int u, v, w;
    edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {};
    bool operator<(const edge& other) {
        return this->w < other.w;
    }
};

vector<ii> points;


int get_num(int& i, string s) {
    string r = "";
    while (s[i] >= '0' && s[i] <= '9') {
       r += s[i];
       i++;
    }
    return stoi(r);
} 

void get_points() {
    string in;
    getline(cin, in);
    int n = in.length();

    for (int i = 0; i < n; i++) {
        if (in[i] == '(') {
            ii p;
            i++;
            p.first = get_num(i, in);
            i++;
            p.second = get_num(i, in);
            points.push_back(p);
        } 
    }
}

void get_e_prime(DisjointSetUnion& dsu) {
    string in;
    getline(cin, in);
    int n = in.length();
    if (in == "none") {
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (in[i] == '(') {
            i++;
            int j = get_num(i, in);
            i++;
            int k = get_num(i, in);    
            j--;
            k--;
            // cout << "E': " << j << " " << k << endl;
            dsu.unite(j, k);
        }
    }
    return;
}

ll kruskals(DisjointSetUnion& dsu, vector<edge>& edge_list) {
    sort(edge_list.begin(), edge_list.end());

    for (auto& edge : edge_list) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            // cout << "KRUSKAL: " << edge.u << " " << edge.v << endl; 
            dsu.unite(edge.u, edge.v, edge.w);
        }
    } 
    return dsu.mst_weight;
}

vector<edge> generate_edge_list() {    
    // The slowest part of the algorithm: generating all edges
    // To make it faster, somehow do this faster
    vector<edge> edge_list;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edge_list.push_back(edge(i, j, abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second))); 
        }
    }
    return edge_list;
}


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    
    get_points(); 
    int n = points.size();
    DisjointSetUnion dsu(n);
    get_e_prime(dsu);

    vector<edge> edge_list = generate_edge_list();
    
    cout << kruskals(dsu, edge_list) << endl;

    return 0;
}
