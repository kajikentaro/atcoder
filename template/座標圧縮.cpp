#include <bits/stdc++.h>
using namespace std;
#define rep(x, y) for (int x = 0; x < y; x++)

// xの値は圧縮せずにy方向のみ圧縮する
struct CC {
  vector<int> f;
  vector<int> y_list;
  CC(int n) : f(n) {}
  void add(int x, int y) {
    f[x] = y;
    y_list.push_back(y);
  }
  // O(n log(n))
  vector<int> compress() {
    int n = f.size();
    vector<int> ans(n);

    // remove duplicated y
    sort(y_list.begin(), y_list.end());
    y_list.erase(unique(y_list.begin(), y_list.end()), y_list.end());

    rep(i, n) {
      // yが何番目の何番目に大きいかを新しいyの値にする
      ans[i] =
          upper_bound(y_list.begin(), y_list.end(), f[i]) - y_list.begin() - 1;
    }
    return ans;
  }
};

signed main() {
  CC cc(4);
  cc.add(0, 100);
  cc.add(1, 1000);
  cc.add(3, 300);
  cc.add(2, 100);

  vector<int> compressed = cc.compress();

  cout << compressed[0] << endl;  // 0
  cout << compressed[1] << endl;  // 2
  cout << compressed[3] << endl;  // 1
  cout << compressed[2] << endl;  // 0
}