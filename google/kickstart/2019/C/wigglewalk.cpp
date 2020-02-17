// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};

pair<int,int> get_neighbor(unordered_map<pair<int,int>, unordered_map<char, pair<int,int> >, pair_hash>& neighbors, pair<int,int> c, char d) {
    if (neighbors.find(c) != neighbors.end() && neighbors[c].find(d) != neighbors[c].end())
        return neighbors[c][d];
    if (d == 'N')
        c.first--;
    if (d == 'S')
        c.first++;
    if (d == 'W')
        c.second--;
    if (d == 'E')
        c.second++;
    return c;
}


void link_neighbor(unordered_map<pair<int,int>, unordered_map<char, pair<int,int> >, pair_hash>& neighbors, pair<int,int> c) {
    pair<int,int> n = get_neighbor(neighbors, c, 'N');
    pair<int,int> s = get_neighbor(neighbors, c, 'S');
    pair<int,int> w = get_neighbor(neighbors, c, 'W');
    pair<int,int> e = get_neighbor(neighbors, c, 'E');

    neighbors[n]['S'] = s;
    neighbors[s]['N'] = n;
    neighbors[e]['W'] = w;
    neighbors[w]['E'] = e;
}
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, R, C, Sr, Sc;
        cin >> N >> R >> C >> Sr >> Sc;
        Sr--; Sc--;
        unordered_map<pair<int,int>, unordered_map<char, pair<int,int> >, pair_hash> neighbors;
        for (int i = 0; i < N; i++) {
            char m;
            cin >> m;
            link_neighbor(neighbors, {Sr, Sc});
            pair<int,int> n = get_neighbor(neighbors, make_pair(Sr, Sc), m);
            Sr = n.first;
            Sc = n.second;   
        }
        cout << "Case #" << i+1 << ": " << Sr+1 << " " << Sc+1 << endl;
    }               

    return 0;
}
