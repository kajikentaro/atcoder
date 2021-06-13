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
string func(ll a, ll b, ll c){
	if(c == 0)return "=";
	if(a >= 0 && b >= 0){
		if(a < b) return "<";
		if(a == b)return "=";
		return ">";
	}
	ll reverse = 0;
	if(a <= 0 && b >= 0){
		if(c % 2 == 0){
			string res = func(abs(a), b, c);
			return res;
		}
		return "<";
	}
	if(a >= 0 && b <= 0){
		if(c % 2 == 0){
			string res = func(a, abs(b), c);
			return res;
		}
		return ">";
	}
	if(a <= 0 && b <= 0){
		if(c % 2 == 0){
			return func(abs(a), abs(b), c);
		}
		return func(abs(b), abs(a) , c);
	}

}
int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	cout << func(a,b,c) << endl;
}
