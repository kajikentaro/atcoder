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
using mint = modint998244353;
using P = pair<int,int>;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)cin >> a[i];
	vector<mint> dp_pre(10);
	dp_pre[a[0]] = 1;
	rep(i,n){
		if(i==0)continue;
		vector<mint> dp(10);
		rep(j,10){
			{
				int ans = (j + a[i])%10;
				dp[ans] += dp_pre[j];
			}
			{
				int ans = (j * a[i])%10;
				dp[ans] += dp_pre[j];
			}
		}
		swap(dp,dp_pre);
	}
	rep(i,10){
		cout << dp_pre[i].val() << endl;
	}
}