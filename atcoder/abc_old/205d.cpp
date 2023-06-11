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
	ll n,q;
	cin >> n >> q;
	vector<ll> a(n+1);
	a[0] = -100;
	map<ll,ll> gath;
	orep(i,n){
		cin >> a[i];
		if(a[i] - 1== a[i-1]){
			gath[a[i]] = gath[a[i-1]];
		}else{
			gath[a[i]] = a[i];
		}
	}
	rep(i,q){
		ll x;
		cin >> x;
		ll bo = 0;
		ll to = (ll)2e18;
		while(to - bo != 1){
			ll ce = (bo + to) / 2;

			ll wa = n+1;
			ll ac = 0;
			while(wa - ac != 1){
				ll wj = (wa + ac) / 2;
				if(a[wj] <= ce){
					ac = wj;
				}else{
					wa = wj;
				}
			}
			ll cnt = ac;
			if(cnt + x > ce){
				bo = ce;
			}else{
				to = ce;
			}
		}
		if(gath.find(to) == gath.end()){
			cout << to << endl;
		}else{
			cout << gath[to] - 1 << endl;
		}
	}
}
