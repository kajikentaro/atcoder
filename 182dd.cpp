#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
#define ll long long
#define rep(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
const char lamp = 1;
const char block = 2;
const char up = 1, down = 2,right = 3, left = 4;
char grid[1505][1505] ={};
char light[1505][1505] ={};
int height, width;
void turn(){
    char grid_tmp[1505][1505];
    char light_tmp[1505][1505];
    rep(i,1,height+1){
        rep(j,1,width+1){
            grid_tmp[j][height + 1 - i] = grid[i][j];
            light_tmp[j][height + 1 - i] = light[i][j];
        }

    }
    swap(grid,grid_tmp);
    swap(light,light_tmp);
    swap(height,width);
}
int main(){
    int n,m;
    cin >> height >> width >> n >> m;
    rep(i,0,n){
        int x,y;
        cin >> x >> y;
        grid[x][y] = lamp;
    }
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        grid[x][y] = block;
    }
    rep(k,1,5){
        rep(i,1,height+1){
            rep(j,1,width+1){
                if(light[i-1][j] == k && grid[i][j] != block){
                    light[i][j] = k;
                }
                if(grid[i][j] == lamp){
                    light[i][j] = k;
                }
            }
        }
        turn();
    }
    ll max = 0;
    rep(i,1,height+1){
        rep(j,1,width+1){
            if(light[i][j])max++;
        }
    }
    cout << max << endl;
    
}
