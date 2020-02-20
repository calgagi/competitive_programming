// Calvin Gagliano 
// @calgagi
// Oregon State University
// Competitive Programming Template
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;

struct library {
    vector<int> book_ids;
    int signup;
    int scan;
    ll score;
    int id;
    int scanned_so_far = 0;

    bool operator<(const library& other) {
        return this->score > other.score;
    }
};

struct book {
    int id;
    int score;

    bool operator<(const book& other) {
        return this->score > other.score;
    }
};

vector<book> books;

struct compare {
    bool operator()(int a, int b) {
        return books[a].score > books[b].score;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

    // INPUT
    int B, L, D;
    cin >> B >> L >> D;
    books.resize(B);
    for (int i = 0; i < B; i++) {
        cin >> books[i].score;
        books[i].id = i;
    }
    
    vector<bool> seen(B, 0);

    vector<library> libs(L);
    for (int i = 0; i < L; i++) {
        library& l = libs[i];
        l.id = i;
        int s;
        cin >> s;
        l.book_ids.resize(s);
        cin >> l.signup >> l.scan;
        for (auto& i : l.book_ids) {
            cin >> i;
        }
    }

    // COMPUTE SCORE FOR LIBS
    for (auto& lib : libs) {
        for (auto& id : lib.book_ids) {
            lib.score += books[id].score;
        }
        lib.score *= lib.scan;
        lib.score -= lib.signup;
        sort(lib.book_ids.begin(), lib.book_ids.end(), compare());
    }

    // SORT LIBS
    sort(libs.begin(), libs.end());

    // ANSWER ARRAYS
    vector<int> ans_libs;
    vector<vector<int>> ans_books;

    // ALGORITHM
    for (int d = 0, l = 0; d < D; d++) {
        if (l < (int) libs.size() && libs[l].signup == 0) {
            ans_libs.push_back(libs[l].id);
            ans_books.push_back(vector<int>());
            l++;
        }
        
        for (int ll = 0; ll < l; ll++) {
            for (int b = 0; b < libs[ll].scan && b + libs[ll].scanned_so_far < (int) libs[ll].book_ids.size(); b++) {
                if (seen[libs[ll].book_ids[b + libs[ll].scanned_so_far]]) {
                    b--;
                    libs[ll].scanned_so_far++;   
                } else {
                    ans_books[ll].push_back(libs[ll].book_ids[b + libs[ll].scanned_so_far]);
                    seen[libs[ll].book_ids[b + libs[ll].scanned_so_far]] = 1;
                }
            }
            libs[ll].scanned_so_far += libs[ll].scan;
        }

        libs[l].signup--;
    }

    // OUTPUT
    cout << ans_libs.size() << endl;
    for (int i = 0; i < (int) ans_libs.size(); i++) {
        cout << ans_libs[i] << " " << ans_books[i].size() << endl;
        for (int j = 0; j < (int) ans_books[i].size(); j++) {
            cout << (j ? " " : "") << ans_books[i][j];
        }
        if ((int) ans_books[i].size() > 0) {
            cout << endl;
        }
    }
    return 0;
}
