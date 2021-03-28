#include <bits/stdc++.h>
using namespace std;
#define rep(x, y) for (int x = 0; x < y; x++)
#define MAX 2010
#define P pair<int, int>
#define INF 1e9
#define get(m, p) m[p.first][p.second]
char grid[MAX][MAX];
int cost[MAX][MAX];
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<P>> warp(200);
    queue<P> q;
    rep(i, h) rep(j, w){
        cost[i][j] = INF;
        cin >> grid[i][j];
        char ng = grid[i][j];
        if ('a' <= ng && ng <= 'z'){
            warp[ng].emplace_back(i, j);
        }
        if (ng == 'S')q.emplace(i, j);
    }
    P direction[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    get(cost, q.front()) = 0;
    int result = -1;
    while (q.size() != 0) {
        P now_p = q.front();
        q.pop();
        for (auto d : direction){
            P next_p(d.first + now_p.first, d.second + now_p.second);
            if (next_p.first < 0 || next_p.second < 0 || next_p.first >= h || next_p.second >= w)continue;
            int new_cost = get(cost, now_p) + 1;
            char next_g = get(grid, next_p);
            if (get(cost, next_p) <= new_cost)continue;
            if (next_g == '#')continue;
            q.push(next_p);
            get(cost, next_p) = new_cost;
            if ('a' <= next_g && next_g <= 'z'){
                for (auto j : warp[next_g]){
                    if (j.first == next_p.first && j.second == next_p.second)continue;
                    get(cost, j) = new_cost + 1;
                    q.push(j);
                }
                warp[next_g].clear();
            }
            if (next_g == 'G')result = new_cost;
        }
    }
    cout << result << endl;
    return 0;
}