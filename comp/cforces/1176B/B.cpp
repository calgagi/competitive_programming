// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		int z = 0, o = 0, t = 0;
		for (int j = 0; j < s; j++) {
			int x; cin >> x;
			if (x % 3 == 0) z++;
			else if (x % 3 == 1) o++;
			else if (x % 3 == 2) t++;
		}
		int d = min(o, t);
		o -= d; t -= d;
		cout << z + d + (o / 3) + (t / 3) << endl;
	}	
	return 0;
}
