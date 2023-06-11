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
vector<int> used;
vector<vector<int>> path;
void dfs(int p,int depth){
	if(used[p] != -1)return;
	used[p] = depth;
	for(auto d : path[p]){
		dfs(d, depth+1);
	}
}
int main(){
	int n,q;
	cin >> n >> q;
	path.resize(n);
	used.resize(n,-1);
	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	dfs(0,0);
	rep(i,q){
		int a,b;
		cin >> a >> b;
		a--;b--;
		int len = used[a] + used[b];
		if(len % 2 == 0){
			cout << "Town" << endl;
		}else{
			cout << "Road" << endl;
		}
	}

}
