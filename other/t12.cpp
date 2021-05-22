#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h,vector<int>(w));
    dsu uf(h*q);
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            int r,c;
            cin >> r >> c;
            r--;c--;
            grid[r][c] = 1;
            int pos_now = r * w + c;
            const P dirs[] = {{1,0},{0,1},{-1,0},{0,-1}};
            for(auto d : dirs){
                int x = d.first + c;
                int y = d.second + r;
                if(x < 0 || y < 0 || x >= w || y >= h)continue;
                if(grid[y][x] == 0)continue;
                int pos_next = y * w + x;
                uf.merge(pos_now, pos_next);
            }
        }else{
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;c1--;r2--;c2--;
            if(grid[r1][c1] == 0 || grid[r2][c2] == 0){
                cout << "No" << endl;
                continue;
            }
            int pos1 = r1 * w + c1;
            int pos2 = r2 * w + c2;
            if(uf.same(pos1, pos2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
