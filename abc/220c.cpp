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
	vector<ll> a(n);
	rep(i,n)cin >> a[i];
	ll x;
	cin >> x;

	ll sum = 0;
	rep(i,n)sum += a[i];

	ll loop = x / sum;
	ll tmp_ans = loop * n;

	x -= loop * sum;
	rep(i,n){
		x -= a[i];
		if(x < 0){
			cout << tmp_ans + i + 1 << endl;
			return 0;
		}
	}
}