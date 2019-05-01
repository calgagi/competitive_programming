// Calvin Gagliano
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, Q;
    cin >> T;
    string str;

    for(int x = 0; x < T; x++){
        cin >> N >> Q >> str;
        int map[N+1][26], count = 0;
        for(int y = 0; y < 26; y++){
            map[0][y] = 0;
		}
		for(int y = 1; y < N+1; y++){
            for(int z = 0; z < 26; z++){
                map[y][z] = map[y-1][z];
			}
            map[y][str[y-1] - 65] += 1;
        }
        int c, l, r;
        for(int y = 0; y < Q; y++){
            c = 0;
            cin >> l >> r;
            for(int z = 0; z < 26; z++){
                if((map[r][z] - map[l-1][z]) % 2 == 1){
                    c++;
				}
            }
            if(c < 2){
                count += 1;
            }
        }
        cout << "Case #" << x+1 << ": " << count << endl;
    }
    return 0;
}
