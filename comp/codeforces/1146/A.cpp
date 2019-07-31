// Calvin Gagliano
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < s.length(); i++) if (s[i] == 'a') a++;
	
	int x = s.length();
	cout << min(x, (a*2)-1) << endl;

	return 0;
}
