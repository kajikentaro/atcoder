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
	int h,w,n;
	cin >> h >> w >> n;
	vector<P> a(n);
	vector<P> b(n);
	rep(i,n){
		cin >> a[i].first >> b[i].first;
		a[i].second = i;
		b[i].second = i;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<P> ans_a;
	vector<P> ans_b;
	auto func = [](int n,auto &in, auto &out){
		int cnt = 0;
		rep(i,n){
			if(i == 0 || in[i].first == in[i-1].first){
				out.emplace_back(in[i].second,cnt);
			}else{
				cnt++;
				out.emplace_back(in[i].second,cnt);
			}
		}
		sort(out.begin(),out.end());
	};
	func(n,a,ans_a);
	func(n,b,ans_b);
	rep(i,n){
		cout << ans_a[i].second+1 << " " << ans_b[i].second+1 << endl;
	}
}
