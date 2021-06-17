#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Write your solution here
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start_timer = chrono::high_resolution_clock::now();
#endif

    int t = 1;
    cin >> t;  // Comment out if single test case
    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto stop_timer = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
    cerr << "Time taken : "
         << ((long double)duration.count()) / ((long double)1e9) << "s "
         << endl;
#endif
    return 0;
}

