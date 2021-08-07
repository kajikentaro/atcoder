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
vector<vector<mint>> dp;
vector<vector<ll>> dp_cnt;
mint func(int type, int n){
	dp_cnt[type][n]++;
	if(n == 1)return 1;
	if(dp[type][n] != 0)return dp[type][n];
	if(type == 1){
		return dp[type][n] = func(1, n-1) + func(0, n-1);
	}else{
		return dp[type][n] = func(1, n-1);
	}
}
mint mypow(mint a, int b){
	if(b == 0)return 1;
	mint res = 1;
	if(b % 2 == 1){
		res *= a;
		b--;
	}
	mint k = mypow(a, b/2);
	res *= k;
	res *= k;
	return res;

}
int main(){
	int n;
	cin >> n;
	dp.resize(2, vector<mint>(n));
	dp_cnt.resize(2, vector<ll>(n));
	mint ans = 0;
	vector<int> a(n);
	rep(i,n)cin >> a[i];

	func(0,n);
	func(1,n);



	rep(i,n){
		if(i==0){
			ans += mypow(a[0], n-1);
			continue;
		}
		mint plus = func(1,n-i);
		mint minus = func(0,n-i);
		ans += (plus - minus) * a[i];
	}
	cout << ans.val() << endl;
}
