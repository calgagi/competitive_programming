// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int a, b, c; cin >> a >> b >> c;
	int n = b / 2;
	int m = c / 4;
	int r = min(a, min(n, m));
	cout << r + r*2 + r*4 << endl;	

	return 0;
}
