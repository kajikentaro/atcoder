#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;
int n;
ll k;
int dist[10][10];
int calc(int visited, int now,ll road){
    int sum = 0;
    int flag = true;
    rep(i,n){
        if(visited & 1 << i){
            continue;
        }else{
            sum += calc(visited | 1 << i,i, road + dist[i][now]);
            flag = false;
        }
    }
    if(flag){
        if(road + dist[now][0] == k){
            sum += 1;
        }else{
            sum += 0;
        }
    }
    return sum;
}
int main(){
    cin >> n >> k;
    rep(i,n){
        rep(j,n){
            cin >> dist[i][j];
        }
    }
    cout << calc(1,0,0) << endl;
    return 0;

}