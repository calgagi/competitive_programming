// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)

using namespace std;

vector<int> primes_sorted;

unordered_set<int> sieve(int x) {
    vector<bool> p(x+1, true);
    unordered_set<int> res;
    for (int i = 2; i <= x; i++) {
	if (p[i]) {
	    if (i != 2) {
		res.insert(i);
		primes_sorted.pb(i);
	    }
	    for (int j = i+i; j <= x; j += i) {
		p[j] = false;
	    }
	}
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x; cin >> x;
    unordered_set<int> primes = sieve(x);    
    int res = 0;
    int i = primes_sorted.size()-1;

    while (x > 4) {
	for (; i >= 0; i--) {
	    if (primes.find(x-primes_sorted[i]) != primes.end()) {
		res++;
		x = primes_sorted[i] - (x - primes_sorted[i]);
		break;
	    }
	}
    }
    if (x == 4) res++;
    cout << res << endl;



    return 0;
}
