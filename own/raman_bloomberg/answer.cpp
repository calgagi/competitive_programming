// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double

using namespace std;

struct Node {
    bool v;
    unordered_map<char, Node*> c;
    Node(bool v) { this->v = v; };
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // set up trie with input
    string s;
    int n;
    cin >> s >> n;
    string x;
    Node* trie = new Node(false);
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* it = trie;
        for (char &c : x) {
            if (it->c.find(c) == it->c.end())
               it->c[c] = new Node(false);
            it = it->c[c];
        } 
        it->v = true;
    }

    // algorithm (sliding window + dfs)
    stack<pair<int,string> > st;
    st.push({0, ""});
    string r;
    while (!st.empty()) {
        int i = st.top().first;
        string t = st.top().second;
        st.pop();
        if (i == s.length()) {
            r = t;
            break;
        }
        Node* it = trie;
        string cur = "";
        while (i < s.length()) {
            if (it->c.find(s[i]) == it->c.end()) 
                break;
            cur += s[i];
            if (it->c[s[i]]->v) st.push({i+1, t + " " + cur});
            it = it->c[s[i]];
            i++;
        }
    }

    if (r == "") cout << "No answer..." << endl;
    else cout << "Answer: " << r << endl;


    return 0;
}
