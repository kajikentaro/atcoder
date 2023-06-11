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
int dfs(int now){
	if(used[now])return 0;
	used[now] = 1;
	cout << now + 1 << " ";
	for(int next : path[now]){
		if(dfs(next)){
			cout << now + 1 << " ";
		}
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	used.resize(n);
	path.resize(n);
	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	rep(i,n){
		sort(path[i].begin(),path[i].end());
	}
	dfs(0);
	cout << endl;
}
