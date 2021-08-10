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
	int n,m;
	cin >> n >> m;
	const int inf = 1e9;
	vector<vector<int>> dist(n,vector<int>(n,inf));
	rep(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		chmin(dist[a][b],c);
	}
	ll ans = 0;
	rep(i,n)dist[i][i] = 0;
	rep(k,n){
		rep(i,n)rep(j,n){
			chmin(dist[i][j],dist[i][k] + dist[k][j]);
			if(dist[i][j] == inf)ans += 0;
			else ans += dist[i][j];
		}
	}
	cout << ans << endl;
}
