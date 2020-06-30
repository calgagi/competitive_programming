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

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    vector<int> first;
    for (int i = 0; i < K; i++) {
        first.push_back(A[i]);
    }

    sort(first.begin(), first.end());
    multiset<int> before, after;

    for (int i = 0; i < K/2; i++) {
        before.insert(first[i]);
    }

    for (int i = K/2; i < K; i++) {
        after.insert(first[i]);
    }

    int median = ((K & 1) ? *after.begin() : *--before.end());
    cout << median << " ";

    for (int i = K; i < N; i++) {
        if (A[i] < median) {
            before.insert(A[i]);
        } else {
            after.insert(A[i]);
        }

        if (before.find(A[i-K]) != before.end()) {
            auto to_delete = before.find(A[i-K]);
            before.erase(to_delete);
        } else {
            auto to_delete = after.find(A[i-K]);
            after.erase(to_delete);
        }

        while (after.size() != before.size() + (K & 1)) {
            if (after.size() < before.size() + (K & 1)) {
                auto move = --before.end();
                after.insert(*move);
                before.erase(move);
            } else {
                auto move = after.begin();
                before.insert(*move);
                after.erase(move);
            }
        }

        median = ((K & 1) ? *after.begin() : *--before.end());
        cout << median << " ";
    } 
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count()); 
    
    int t = 1;
    /* cin >> t; */
    while (t--) {
        solve();
    }

    return 0;
}
