#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define MAX 2010
#define P mypair<int,int>
template<typename T,typename U>
struct mypair :std::pair<T,U>{
    using std::pair<T,U>::pair;
    mypair<T,U> operator+(pair<T,U> p){
        return mypair<T,U>(this->first + p.first, this->second + p.second);
    }
    void set(T a,T b){
        this->first = a;
        this->second = b;
    }
    bool isNURUPO(int a_max,int b_max){
        if(this->first < 0 || this->second < 0 || this->first >= a_max || this->second >= b_max)return true;
        return false;
    }
};
template<typename T>
struct Z_box{
    T z_box[MAX][MAX] = {};
    T& operator[](pair<int,int> p){
        return z_box[p.first][p.second];
    }
    T* operator[](int n){
        return z_box[n];
    }
};
#define pair mypair
#define INF 1e9
Z_box<int> cost;
Z_box<char> grid;
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h)rep(j,w){
        cin >> grid[i][j];
        cost[i][j] = INF;
    }
    vector<vector<P>> warp(200);
    P start,end;
    rep(i,h)rep(j,w){
        char ng = grid[i][j];
        if('a' <= ng && ng <= 'z'){
            warp[ng].emplace_back(i,j);
        }
        if(ng =='S')start.set(i,j);
        if(ng =='G')end.set(i,j);
    }
    queue<P> q;
    q.push(start);
    cost[start] = 0;
    pair<int,int> direction[] = {{0,1},{1,0},{-1,0},{0,-1}};
    int goal_cost = -1;
    while(q.size() != 0){
        P now = q.front();
        q.pop();
        rep(i,4){
            P next = now + direction[i];
            if(next.isNURUPO(h,w))continue;
            char ng = grid[next];
            if(ng == '#')continue;
            if(cost[now] + 1 < cost[next]){
                cost[next] = cost[now]+1;
                q.push(next);
            }else continue;
            if(ng == 'G'){
                if(goal_cost == -1)goal_cost = cost[next];
                goal_cost = min(goal_cost, cost[next]);
            }
            if('a' <= ng && ng <= 'z'){
                rep(j,warp[ng].size()){
                    if(warp[ng][j] != next){
                        cost[warp[ng][j]] = cost[next] + 1; 
                        q.push(warp[ng][j]);
                    }
                }
                warp[ng].resize(0);
            }
        }
    }
    cout << goal_cost << endl;
    /*
    rep(i,h){
        rep(j,w){
            if(cost[i][j] == INF)cost[i][j] = -1;
            printf("%3d",cost[i][j]);
        }
        cout << endl;
    }*/
    return 0;
}