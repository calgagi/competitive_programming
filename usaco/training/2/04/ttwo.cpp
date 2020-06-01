/*
ID: calgagi1
LANG: C++
TASK: ttwo
*/
/* 
 * author: calgagi
 *         Calvin Gagliano
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define ar array
#define f first
#define s second
#define dd long double

const int N = 10;
const vector<ii> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
    vector<string> g(N, string(N, ' '));

    int fx, fy, cx, cy, fd = 0, cd = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'F') {
                fx = i, fy = j;
            } else if (g[i][j] == 'C') {
                cx = i, cy = j;
            }
        }
    }

    bool visit[N][N][N][N][4][4] = {0};

    int ans = 0;
    while (!(fx == cx && fy == cy)) {
        if (visit[fx][fy][cx][cy][fd][cd]) {
            ans = 0;
            break;
        }
        visit[fx][fy][cx][cy][fd][cd] = 1;

        if (fx + dir[fd].f >= N || fy + dir[fd].s >= N || fx + dir[fd].f < 0 || fy + dir[fd].s < 0 || g[fx + dir[fd].f][fy + dir[fd].s] == '*') {
            fd = (fd + 1) % 4;
        } else {
            fx += dir[fd].f;
            fy += dir[fd].s;
        }

        if (cx + dir[cd].f >= N || cy + dir[cd].s >= N || cx + dir[cd].f < 0 || cy + dir[cd].s < 0 || g[cx + dir[cd].f][cy + dir[cd].s] == '*') {
            cd = (cd + 1) % 4;
        } else {
            cx += dir[cd].f;
            cy += dir[cd].s;
        }

        ans++;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    FILE *IN = freopen("ttwo.in", "r", stdin), *OUT = freopen("ttwo.out", "w", stdout); 

    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
