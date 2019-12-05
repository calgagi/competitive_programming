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
const double EPS = 1E-9;

struct pt {
    double x, y;

    bool operator<(const pt& p) const
    {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
    pt(double _x, double _y) : x(_x), y(_y) {};
    pt() {};
};

struct line {
    double a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist(pt p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool betw(double l, double r, double x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(double a, double b, double c, double d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char in = ' ';
    double v; 
    double r = 0, c = 0;
    vector<pt> segments1 = {{0, 0}}, segments2 = {{0,0}};
    vector<int> diff;
    do {
        cin >> in;
        if (in == 'R') diff = {0, 1};
        else if (in == 'L') diff = {0, -1};
        else if (in == 'U') diff = {1, 0};
        else if (in == 'D') diff = {-1, 0};
        else if (in == 'W') break;
        cin >> v;
        r += diff[0] * v;
        c += diff[1] * v;
        segments1.pb({r, c});
    } while (in != 'W');

    string garb;
    cin >> garb;
    cout << garb << endl;
    r = 0, c = 0;
    while (true) {
        cin >> in >> v;
        if (cin.fail()) break;
        if (in == 'R') diff = {0, 1};
        else if (in == 'L') diff = {0, -1};
        else if (in == 'U') diff = {1, 0};
        else if (in == 'D') diff = {-1, 0};
        int oldc = c, oldr = r;
        r += diff[0] * v;
        c += diff[1] * v;
        segments2.pb({r,c});
    }
    cout << segments1.size() << " " << segments2.size() << endl;
    
    double res = INT_MAX;
    for (int i = 1; i < segments1.size(); i++) {
        for (int j = 1; j < segments2.size(); j++) {
            pt l, r;
            if (intersect(segments1[i-1],segments1[i],segments2[j-1],segments2[j],l,r)) {
               // if (l.x == 0 && l.y == 0) {
               //     if (r.x == 0 && r.y == 0) continue;
               //     cout << 1 << endl;
               //     return 0;
               // }
                if (l.x == 0 && l.y == 0) continue;
                res = abs(l.x)+abs(l.y);
            }
        }
    }

    cout << res << endl;
    return 0;
}
