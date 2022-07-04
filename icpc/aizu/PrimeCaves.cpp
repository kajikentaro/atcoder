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
  int n;
  vector<vector<int>> is_prime;
  vector<P> n_to_p;
  vector<vector<int>> p_to_n_private;
  Grid(int n) : n(n) {
    is_prime.resize(GRID_SIZE, vector<int>(GRID_SIZE, BAN));
    n_to_p.resize(n + 1);
    p_to_n_private.resize(GRID_SIZE, vector<int>(GRID_SIZE, -1));
    init();
  }
  int get(int h, int w) {
    return is_prime[h + GRID_SIZE / 2][w + GRID_SIZE / 2];
  }
  int p_to_n(int h, int w) {
    return p_to_n_private[h + GRID_SIZE / 2][w + GRID_SIZE / 2];
  }
  void set_p_to_n(int h, int w, int v) {
    p_to_n_private[h + GRID_SIZE / 2][w + GRID_SIZE / 2] = v;
  }
  void set(int h, int w, int v) {
    is_prime[h + GRID_SIZE / 2][w + GRID_SIZE / 2] = v;
  }
  void init() {
    int hi = 0, wi = 0;
    const P dirs[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int dir_n = 3;
    vector<bool> is_composit = calc_prime_list();
    orep(i, n) {
      n_to_p[i] = P{hi, wi};
      set_p_to_n(hi, wi, i);
      if (is_composit[i]) {
        set(hi, wi, NORMAL);
      } else {
        set(hi, wi, PRIME);
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

bool func() {
  int n, first;
  cin >> n >> first;
  if (n == 0 && first == 0) return false;
  Grid grid(n);
  P start = grid.n_to_p[first];
  // debug_output_grid(grid);

  P dirs[] = {{-1, -1}, {-1, 0}, {-1, 1}};
  vector<ll> dp(GRID_SIZE, -1);
  auto get = [&](int w) { return dp[w + GRID_SIZE / 2]; };
  auto set = [&](int w, ll val) { dp[w + GRID_SIZE / 2] = val; };
  int hi = start.first;

  ll ans = 0;
  ll ans_n = first;
  if (grid.get(start.first, start.second) == PRIME) {
    set(start.second, 1);
    ans = 1;
  } else {
    set(start.second, 0);
    ans = 0;
  }
  while (1) {
    // debug_output_vector(dp);
    vector<ll> dp_old(GRID_SIZE, -1);
    auto get_old = [&](int w) { return dp_old[w + GRID_SIZE / 2]; };
    swap(dp, dp_old);
    int new_hi = hi + 1;
    if (new_hi >= GRID_SIZE / 2) break;
    for (int wi = -GRID_SIZE / 2; wi < GRID_SIZE / 2; wi++) {
      ll score = get_old(wi);
      if (score == -1) continue;

      bool has_move = false;
      for (auto d : dirs) {
        int new_wi = wi + d.second;
        if (new_wi < -GRID_SIZE / 2 || GRID_SIZE / 2 <= new_wi) continue;
        if (grid.get(new_hi, new_wi) == BAN) continue;
        if (grid.get(new_hi, new_wi) == PRIME) {
          if (get(new_wi) < score + 1) {
            set(new_wi, score + 1);
          }
        }
        if (grid.get(new_hi, new_wi) == NORMAL) {
          if (get(new_wi) < score) {
            set(new_wi, score);
          }
        }
        has_move = true;
      }

      if (!has_move) {
        int last_n = grid.p_to_n(hi, wi);
        if (ans < score) {
          ans = score;
          ans_n = last_n;
        }
        if (ans == score && ans_n < last_n) {
          ans = score;
          ans_n = last_n;
        }
      }
    }
    hi++;
  }
  cout << ans << " " << ans_n << endl;

  return true;
}

int main() {
  while (func()) {
    ;
  }
}