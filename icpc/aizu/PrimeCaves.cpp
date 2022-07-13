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

vector<bool> calc_prime_list() {
  ll SEARCH_MAX = 1e6 + 10;
  vector<bool> tmp(SEARCH_MAX);
  for (ll i = 2; i * i <= SEARCH_MAX; i++) {
    if (tmp[i] == true) continue;
    for (ll j = i * 2; j < SEARCH_MAX; j += i) {
      tmp[j] = true;
    }
  }
  tmp[1] = true;
  return tmp;
}

const int GRID_SIZE = 1e3 + 10;
const int PRIME = 2;
const int BAN = 0;
const int NORMAL = 1;

struct Grid {
 private:
  vector<vector<int>> p_to_n_private;
  vector<vector<int>> is_prime;

 public:
  int n;
  vector<P> n_to_p;

  Grid(int n) : n(n) {
    is_prime.resize(GRID_SIZE, vector<int>(GRID_SIZE, BAN));
    n_to_p.resize(n + 1);
    p_to_n_private.resize(GRID_SIZE, vector<int>(GRID_SIZE, -1));
    init();
  }
  int &get(P p) {
    return is_prime[p.first + GRID_SIZE / 2][p.second + GRID_SIZE / 2];
  }
  int &get(int h, int w) {
    return is_prime[h + GRID_SIZE / 2][w + GRID_SIZE / 2];
  }
  int &p_to_n(int h, int w) {
    return p_to_n_private[h + GRID_SIZE / 2][w + GRID_SIZE / 2];
  }
  int &p_to_n(P p) {
    return p_to_n_private[p.first + GRID_SIZE / 2][p.second + GRID_SIZE / 2];
  }
  void init() {
    int hi = 0, wi = 0;
    const P dirs[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int dir_n = 3;
    vector<bool> is_composit = calc_prime_list();
    orep(i, n) {
      n_to_p[i] = P{hi, wi};
      p_to_n(hi, wi) = i;
      if (is_composit[i]) {
        get(hi, wi) = NORMAL;
      } else {
        get(hi, wi) = PRIME;
      }
      P tmp = dirs[(dir_n + 1) % 4];
      if (get(hi + tmp.first, wi + tmp.second) == BAN) {
        dir_n = (dir_n + 1) % 4;
      }
      hi += dirs[dir_n].first;
      wi += dirs[dir_n].second;
    }
  }
};

void debug_output_grid(Grid grid, int n) {
  int sqn = sqrt(n);
  for (int i = -sqn; i <= sqn; i++) {
    for (int j = -sqn; j <= sqn; j++) {
      cout << grid.get(i, j) << " ";
    }
    cout << endl;
  }
}

void debug_output_vector(vector<ll> dp) {
  for (auto d : dp) {
    if (d != -1) {
      cout << d << " ";
    }
  }
  cout << endl;
}

struct DP {
 private:
  vector<vector<ll>> dp;

 public:
  DP() { dp.resize(GRID_SIZE, vector<ll>(GRID_SIZE, -1)); }

  ll &get(int h, int w) { return dp[h + GRID_SIZE / 2][w + GRID_SIZE / 2]; }
  ll &get(P p) { return dp[p.first + GRID_SIZE / 2][p.second + GRID_SIZE / 2]; }

  void update(P p, ll score) { chmax(get(p), score); }
};

struct Point {
  P p;
  ll score = 0;
};

bool func() {
  int n, first;
  cin >> n >> first;
  if (n == 0 && first == 0) return false;

  // グリッド作成
  Grid grid(n);

  // 結果格納用変数
  DP res;
  Point ans;

  // 開始位置設定
  P start = grid.n_to_p[first];
  set<P> can;
  can.insert(start);
  if (grid.get(start) == PRIME) {
    res.get(start) = 1;
    ans.p = start;
    ans.score = 1;
  } else {
    res.get(start) = 0;
  }

  while (can.size()) {
    set<P> can_old;
    swap(can_old, can);
    for (auto now : can_old) {
      ll now_score = res.get(now);
      const P dirs[] = {{1, -1}, {1, 0}, {1, 1}};
      for (auto d : dirs) {
        P next = now;
        next.first += d.first;
        next.second += d.second;

        if (grid.get(next) == BAN) continue;
        if (grid.get(next) == NORMAL) {
          can.insert(next);
          res.update(next, now_score);
        }
        if (grid.get(next) == PRIME) {
          ll next_score = now_score + 1;
          can.insert(next);
          res.update(next, next_score);

          if (ans.score < next_score) {
            ans = Point{next, next_score};
          } else if (ans.score == next_score) {
            int ans_n = grid.p_to_n(ans.p);
            int next_n = grid.p_to_n(next);
            if (ans_n < next_n) ans = Point{next, next_score};
          }
        }
      }
    }
  }

  int ans_n = grid.p_to_n(ans.p);
  if (ans.score == 0) {
    cout << "0 0" << endl;
  } else {
    cout << ans.score << " " << ans_n << endl;
  }

  return true;
}

int main() {
  while (func()) {
    ;
  }
}