#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
struct Solver {
    int md(int b, int m) {
        if (b > m)
            b = b % m + m;
        return b;
    }
    int f(int a, int b, int m) {
        a = md(a, m);
        b = md(b, m);
        int res = 1;
        rep(i, b) res = md(res * a, m);
        return res;
    }
    int solve() {
        int a, b, c;
        cin >> a >> b >> c;
        return f(a, f(b, c, 4), 10) % 10;
    }
};
int main() {
    Solver solver;
    cout << solver.solve() << endl;
    return 0;
}
