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
	vector<P> a;
	rep(i,n){
		int t;
		cin >> t;
		a.emplace_back(t,0);
	}
	rep(i,m){
		int t;
		cin >> t;
		a.emplace_back(t,1);
	}
	sort(a.begin(),a.end());

	int aa = -1e9;
	int bb = -1e9;

	int ans = 1e9;

	rep(i,n+m){
		if(a[i].second == 0)aa = a[i].first;
		if(a[i].second == 1)bb = a[i].first;
		chmin(ans, abs(aa - bb));
	}
	cout << ans << endl;


}
