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
	multiset<P> balls;
	vector<ll> adds;
	int cnt = 0;
	rep(i,n){
		int q;
		cin >> q;
		if(q == 1){
			int a;
			cin >> a;
			balls.insert(P(a,cnt));
		}
		if(q == 2){
			int a;
			cin >> a;
			adds.push_back(a);
			cnt++;
		}
		if(q == 3){
			cout << mi << endl;
		}
	}
}
