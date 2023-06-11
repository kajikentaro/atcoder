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
	map<ll,ll> margin;
	rep(i,n){
		ll a,b;
		cin >> a >> b;
		margin[a]++;
		margin[a+b]--;
	}
	vector<ll> ans(n+1);
	ll human = 0;
	ll nowDate = 0;
	for(auto m : margin){
		ll dateSize = m.first - nowDate;
		ans[human] += dateSize;
		human += m.second;
		nowDate = m.first;
	}
	rep(i,n+1){
		if(i==0)continue;
		cout << ans[i] << " ";
	}
	cout << endl;
}