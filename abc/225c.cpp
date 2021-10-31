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
string func(){
	int n,m;
	cin >> n >> m;
	vector<vector<ll>> b(n,vector<ll>(8));
	ll master;
	rep(i,n){
		rep(j,m){
			ll p;
			cin >> p;
			if(i ==0 && j == 0){
				master = p;
				ll z = master % 7;
				if(z == 0){
					if(m != 1)return "No";
				}else{
					if(z + m > 8){
						return "No";
					}
				}
			}
			b[i][j] = p - master;
		}
	}
	rep(i,n){
		rep(j,m){
			if(i - 1 >= 0){
				if(b[i-1][j] + 7 != b[i][j])return "No";
			}
			if(j - 1 >= 0){
				if(b[i][j-1] + 1 != b[i][j])return "No";
			}
		}
	}
	return "Yes";
}
int main(){
	cout << func() << endl;
}
