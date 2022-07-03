#include <bits/stdc++.h>

#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  return a < b ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return b < a ? (a = b, 1) : 0;
}
using namespace std;
using P = pair<int, int>;

const vector<P> DIRS = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

struct Dice {
  int top_n = -1, front_n = -1;

  vector<int> get_sides() {
    if (top_n == 6) {
      return vector<int>{2, 3, 5, 4};
    }
    if (top_n == 5) {
      return vector<int>{3, 1, 4, 6};
    }
    if (top_n == 4) {
      return vector<int>{1, 2, 6, 5};
    }
    if (top_n == 3) {
      return vector<int>{2, 1, 5, 6};
    }
    if (top_n == 2) {
      return vector<int>{1, 3, 6, 4};
    }
    if (top_n == 1) {
      return vector<int>{3, 2, 4, 5};
    }
    exit(1);
  }

  int get_bottom() { return 7 - top_n; }

  vector<P> get_dirs() {
    vector<int> sides = get_sides();

    vector<int> idx_list;
    for (int i = 6; i >= 4; i--) {
      rep(si, 4) {
        if (sides[si] == i) idx_list.push_back(si);
      }
    }

    int rotate_cnt = -1;
    rep(i, 4) {
      if (sides[i] == front_n) {
        rotate_cnt = i;
      }
    }

    return vector<P>{DIRS[(idx_list[0] - rotate_cnt + 4) % 4],
                     DIRS[(idx_list[1] - rotate_cnt + 4) % 4]};
  }

  Dice rotate(P dir) {
    vector<int> sides = get_sides();
    int rotate_cnt = -1;
    rep(i, 4) {
      if (sides[i] == front_n) {
        rotate_cnt = i;
      }
    }

    int dir_no = -1;
    rep(i, 4) {
      if (DIRS[i].first == dir.first && DIRS[i].second == dir.second) {
        dir_no = i;
      }
    }

    int under_n = sides[(dir_no + rotate_cnt) % 4];
    if (dir_no == 0) {
      return Dice{7 - under_n, top_n};
    }
    if (dir_no == 2) {
      return Dice{7 - under_n, get_bottom()};
    }
    if (dir_no % 2) {
      return Dice{7 - under_n, front_n};
    }
    exit(1);
  }
};
struct Floor {
  vector<vector<Dice>> floor;
  Floor() {
    vector<vector<Dice>> new_floor(100, vector<Dice>(100));
    swap(new_floor, floor);
  }

  Dice &get(int h, int w) { return floor[h + 50][w + 50]; }
};

struct Field {
  int highest = 0;

  vector<Floor> field;
  Field() {
    vector<Floor> new_field(100);
    swap(field, new_field);
  }

  void fall(Dice a) {
    int now = highest - 1;
    Dice dice = a;
    int h = 0;
    int w = 0;
    while (1) {
      if (now < 0) break;
      bool has_move = false;
      auto dirs = a.get_dirs();
      for (auto d : dirs) {
        int new_h = h + d.first;
        int new_w = w + d.second;
        if (field[now].get(new_h, new_w).top_n == -1) {
          has_move = true;
          a = a.rotate(d);
          h = new_h;
          w = new_w;
          break;
        }
      }
      if (has_move) {
        now--;
        while (now >= 0 && field[now].get(h, w).top_n == -1) {
          now--;
        }
      } else {
        break;
      }
    }
    if (h == 0 && w == 0) {
      field[highest].get(h, w) = a;
      highest++;
    } else {
      field[now + 1].get(h, w) = a;
    }
  }

  void output() {
    vector<vector<bool>> used(100, vector<bool>(100, false));
    vector<int> ans(7);
    rrep(layer, 100) {
      rep(hi, 100) rep(wi, 100) {
        if (used[hi][wi]) continue;
        if (field[layer].floor[hi][wi].top_n == -1) continue;
        used[hi][wi] = true;
        ans[field[layer].floor[hi][wi].top_n]++;
      }
    }
    rep(i, 7) {
      if (i == 0) continue;
      if (i == 6) {
        cout << ans[i] << endl;
      } else {
        cout << ans[i] << " ";
      }
    }
  }
};

bool func() {
  int n;
  cin >> n;
  if (n == 0) return false;

  Field field;
  rep(i, n) {
    int top, front;
    cin >> top >> front;
    field.fall(Dice{top, front});
  }
  field.output();
  return true;
}

int main() {
  while (func()) {
    ;
  }
}