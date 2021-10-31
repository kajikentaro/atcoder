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
using P = pair<ll,ll>;
int main(){
	int n;
	cin >> n;
	vector<P> p(n);
	rep(i,n){
		ll x,y;
		cin >> p[i].first >> p[i].second;
	}
	auto cmp = [](P& a, P& b){
		ll a_child = a.second * (b.first - 1);
		ll b_child = b.second * (a.first - 1);
		return a_child < b_child;
	};
	sort(p.begin(), p.end(), cmp);
	P now_p;
	auto can = [](P& a, P& next){
		ll a_child = a.second * next.first;
		ll next_child = (next.second - 1) * (a.first - 1);
		return a_child <= next_child;
	};
	ll ans = 0;
	rep(i,n){
		if(i == 0){
			now_p.first = p[i].first;
			now_p.second = p[i].second;
			ans++;
		}else{
			if(can(now_p, p[i])){
				ans++;
				now_p = p[i];
			}
		}
	}
	cout << ans << endl;

}