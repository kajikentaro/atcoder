#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define INF 5000
struct P{
    int first,second;
    P(int first=0,int second=0):first(first),second(second){}
    void set(int first,int second){
        first = first;
        second = second;
    }
    const P operator+(const P& right){
        return P(first+right.first,second+right.second);
    }
};
struct Warp{
    vector<vector<P>> warp;
    Warp(){
        warp.resize(26);
    }
    vector<P>& operator[](char n){
        return warp[n - 'a'];
    }
};
struct Dist{
    vector<vector<int>> dist;
    Dist(int h,int w):dist(h,vector<int>(w,INF)) {}
    int& operator()(P p){
        return dist[p.first][p.second];
    }
    vector<int>& operator[](int n){
        return dist[n];
    }
};
struct Map{
    vector<vector<char>> map;
    Map(int h,int w):map(h,vector<char>(w)) {}
    char& operator()(P p){
        return map[p.first][p.second];
    }
    vector<char>& operator[](int n){
        return map[n];
    }
};
int main(){
    int h,w;
    Warp warp;
    queue<P> q;

    cin >> h >> w;
    Map map(h,w);
    Dist dist(h,w);
    rep(i,h)rep(j,w)cin >> map[i][j];
    rep(i,h)rep(j,w){
        char cursor = map[i][j];
        if(cursor == 'S'){
            q.emplace(i,j);
            dist[i][j] = 0;
        }
        if('a' <= cursor && cursor <= 'z')warp[cursor].emplace_back(i,j);
    }
    vector<P> D = {{1,0},{0,1},{-1,0},{0,-1}};
    while(q.size() != 0){
        P now = q.front();
        q.pop();
        for(auto d : D){
            P next = now + d;
            int next_dist = dist(now) + 1;
            if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w)continue;
            if(next_dist > dist(next))continue;
            q.push(next);
            dist(next) = next_dist;
            if('a' <= map(next) && map(next) <= 'z'){
                for(auto p:warp[map(next)]){
                    dist(p) = next_dist;
                }
                warp[map(next)].resize(0);
            }
            if(map(next) == 'G'){
                cout << dist(next) << endl;
                return 0;
            }
        }
    }
}