#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;

struct Point {
  int x, y;
};

#define N 30
vector<vector<int>> input_tiles(N, vector<int>(N));

int path[8][4] = {
    {3, -1, -1, 0}, {-1, -1, 3, 2}, {-1, 2, 1, -1}, {1, 0, -1, -1},
    {3, 2, 1, 0},   {1, 0, 3, 2},   {-1, 3, -1, 1}, {2, -1, 0, -1},
};

void rewrite_same_pos(int &i2, int &j2, int &k2) {
  switch (k2) {
    case 0:
      i2--;
      break;
    case 1:
      j2++;
      break;
    case 2:
      i2++;
      break;
    case 3:
      j2--;
      break;
  }
  k2 = (k2 + 2) % 4;
}

int compute_score(const vector<vector<int>> &tiles) {
  bool used[N][N][4] = {};
  vector<int> sycle_len_list;
  rep(i, N) rep(j, N) rep(k, 4) {
    int i2 = i, j2 = j, k2 = k;
    int tmp_sycle_len = 0;
    while (!used[i2][j2][k2]) {
      used[i2][j2][k2] = true;
      k2 = path[tiles[i2][j2]][k2];
      if (k2 == -1) break;
      used[i2][j2][k2] = true;
      rewrite_same_pos(i2, j2, k2);
      tmp_sycle_len++;
      if (i2 < 0 || j2 < 0 || i2 >= N || j2 >= N) break;
      if (i2 == i && j2 == j && k2 == k) {
        sycle_len_list.push_back(tmp_sycle_len);
        break;
      }
    }
  }
  sort(sycle_len_list.rbegin(), sycle_len_list.rend());
  if (sycle_len_list.size() <= 1) return 0;
  return sycle_len_list[0] * sycle_len_list[1];
}

vector<vector<int>> rotate_tiles(vector<vector<int>> origin,
                                 vector<vector<int>> rotate) {
  vector<vector<int>> c(N, vector<int>(N));
  rep(i, N) rep(j, N) {
    if (origin[i][j] <= 3) {
      c[i][j] = (origin[i][j] + rotate[i][j]) % 4;
      continue;
    }
    if (!(rotate[i][j] % 2)) {
      c[i][j] = origin[i][j];
      continue;
    }
    if (origin[i][j] == 4)
      c[i][j] = 5;
    else if (origin[i][j] == 5)
      c[i][j] = 4;
    else if (origin[i][j] == 6)
      c[i][j] = 7;
    else if (origin[i][j] == 7)
      c[i][j] = 6;
  }
  return c;
}

string get_output_str(const vector<vector<int>> a) {
  string outline = "";
  rep(i, N) rep(j, N) outline = outline + to_string(a[i][j]);
  return outline;
}

struct Item {
  int score;
  vector<vector<int>> rotate;
  Item(int score, vector<vector<int>> rotate) : score(score), rotate(rotate) {}
};

void burn(const vector<vector<vector<int>>> &root_rotate_list,
          vector<vector<vector<int>>> &result_rotate_list) {
  int VAR1 = 3;   // 回転が起こる確率
  int VAR2 = 10;  // 何倍にするか
  for (auto &root : root_rotate_list) {
    result_rotate_list.push_back(root);
    rep(i, VAR2) {
      vector<vector<int>> rotate(N, vector<int>(N));
      rep(i, N) rep(j, N) rotate[i][j] =
          (rand() % 10 <= VAR1) ? rand() % 4 : root[i][j];
      result_rotate_list.push_back(rotate);
    }
  }
}

void get_top_n(const vector<vector<vector<int>>> &rotate_list,
               vector<vector<vector<int>>> &result_rotate_list) {
  vector<P> holder;
  rep(i, rotate_list.size()) {
    vector<vector<int>> tmp = rotate_tiles(input_tiles, rotate_list[i]);
    int score = compute_score(tmp);
    holder.emplace_back(score, i);
  }
  sort(holder.rbegin(), holder.rend());
  int VAR1 = 4;
  rep(i, VAR1) { result_rotate_list.push_back(rotate_list[holder[i].second]); }
}

int main() {
  srand(1234);
  rep(i, N) {
    string line;
    cin >> line;
    rep(j, N) { input_tiles[i][j] = line[j] - '0'; }
  }

  vector<vector<vector<int>>> random_rotate_list;
  rep(i, 12) {
    vector<vector<int>> rotate(N, vector<int>(N));
    rep(i, N) rep(j, N) rotate[i][j] = rand() % 4;
    random_rotate_list.push_back(rotate);
  }

  vector<vector<vector<int>>> random_rotate_top;
  get_top_n(random_rotate_list, random_rotate_top);

  rep(i, 5e2) {
    vector<vector<vector<int>>> random_rotate_res;
    burn(random_rotate_top, random_rotate_res);
    random_rotate_top.resize(0);
    get_top_n(random_rotate_res, random_rotate_top);
  }

  vector<P> holder;
  rep(i, random_rotate_top.size()) {
    vector<vector<int>> tmp = rotate_tiles(input_tiles, random_rotate_top[i]);
    int score = compute_score(tmp);
    holder.emplace_back(score, i);
  }
  cout << get_output_str(random_rotate_top[holder[0].second]) << endl;
}