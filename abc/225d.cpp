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
	int n,q;
	cin >> n >> q;
	vector<int> forward(n, -1);
	vector<int> backward(n, -1);
	rep(i,q){
		int query;
		cin >> query;
		switch (query) {
			int x,y;
			case 1:
				cin >> x >> y;
				x--;y--;
				backward[x] = y;
				forward[y] = x;
				break;
			case 2:
				cin >> x >> y;
				x--;y--;
				backward[x] = -1;
				forward[y] = -1;
				break;
			case 3:
				cin >> x;
				x--;
				int c = x;
				while(1){
					if(forward[c] == -1)break;
					c = forward[c];
				}
				vector<int> ans;
				while(1){
					ans.push_back(c + 1);
					c = backward[c];
					if(c == -1)break;
				}
				cout << ans.size() << " ";
				rep(i,ans.size()){
					cout << ans[i] << " ";
				}
				cout << endl;
				break;
		}
	}
}