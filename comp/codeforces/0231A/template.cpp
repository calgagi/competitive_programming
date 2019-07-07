// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N; cin >> N;
	int r = 0;
	for (int i = 0; i < N; i++) {
		int p, v, t;
		cin >> p >> v >> t;
		if (p + v + t > 1) r++;
	}
	cout << r << endl;


	return 0;
}
