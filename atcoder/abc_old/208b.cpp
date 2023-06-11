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
	int p;
	cin >> p;
	vector<int> coin;
	orep(i,11){
		int res = 1;
		orep(j,i){
			res *= j;
		}
		coin.push_back(res);
	}
	int ans = 0;
	rrep(i,11){
		while(p >= 0){
			ans++;
			p -= coin[i];
		}
		p += coin[i];
		ans--;
	}
	cout << ans << endl;
}
