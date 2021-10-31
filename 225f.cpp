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
	int n,k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i,n)cin >> s[i];
	auto cmp = [](string& a, string& b){
		int c = 0;
		while(1){
			if(c >= a.size() || c >= b.size())break;
			if(a[c] == b[c]){
				c++;
				continue;
			}
			return a[c] < b[c];
		}
		return a.size() < b.size();
	};
	sort(s.begin(), s.end(), cmp);
	rep(i,k){
		cout << s[i];
	}
	cout << endl;
}