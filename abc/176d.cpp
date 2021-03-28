#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define srep(x,y) for(int x=(-y);x<=y;x++)
using namespace std;
using ll = long long;
#define P pair<int,int>
int main(){
    int h,w;
    cin >> h >> w;
    P s,g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;s.second--;g.first--;g.second--;
    vector<vector<char>> grid(h,vector<char>(w));
    vector<vector<int>> cost(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> grid[i][j];
    rep(i,h)rep(j,w)cost[i][j] = 1e8;

    queue<P> q1;
    queue<P> q2;
    q1.push(s);
    P dir[] = {{1,0},{0,1},{-1,0},{0,-1}};

    cost[s.first][s.second] = 0;
    while(q1.size() != 0 || q2.size() != 0){
        if(q1.size() == 0)swap(q1,q2);
        P now = q1.front();
        q1.pop();
        srep(i,2)srep(j,2){
            P next(now.first + i,now.second + j);
            if(abs(i) + abs(j) <= 1)continue;
            if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w)continue;
            if(cost[next.first][next.second] <= cost[now.first][now.second] + 1)continue;
            if(grid[next.first][next.second] == '#')continue;
            q2.push(next);
            cost[next.first][next.second] = cost[now.first][now.second] + 1;
        }
        for(auto d : dir){
            P next(d.first + now.first, d.second + now.second);
            if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w)continue;
            if(cost[next.first][next.second] <= cost[now.first][now.second])continue;
            if(grid[next.first][next.second] == '#')continue;
            q1.push(next);
            cost[next.first][next.second] = cost[now.first][now.second];
        }
    }
    if(cost[g.first][g.second] == 1e8)cost[g.first][g.second] = -1;
    cout << cost[g.first][g.second] << endl;

}