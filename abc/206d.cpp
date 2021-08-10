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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)cin >> a[i];
	dsu uf(1e6);
	rep(i,n / 2){
		int x = a[i];
		int y = a[n - 1 - i];
		uf.merge(x,y);
	}
	int ans = 0;
	for(auto a :uf.groups()){
		ans += a.size() - 1;
	}
	cout << ans << endl;
}
