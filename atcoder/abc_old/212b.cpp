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
	string x;
	cin >> x;
	rep(i,4){
		x[i] -= '0';
	}
	if(x[0] == x[1] && x[1] == x[2] && x[2] == x[3]){
		cout << "Weak" << endl;
		return 0;
	}
	rep(i,10){
		int a[] = {i,i+1,i+2,i+3};
		rep(i,4){
			a[i] %= 10;
		}
		if(a[0] == x[0] && a[1] == x[1] && a[2] == x[2] && a[3] == x[3]){
			cout << "Weak" << endl;
			return 0;
		}
	}
	cout << "Strong" << endl;
}
