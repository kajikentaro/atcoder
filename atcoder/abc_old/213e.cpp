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
struct grid{
	int k,r,c;
	grid(int k,int r,int c):k(k),r(r),c(c){}
};
bool operator>(const grid &a, const grid &b){
	return a.k > b.k;
}
int main(){
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h){
		cin >> s[i];
	}
	priority_queue<grid,vector<grid>,greater<grid>> que;
	vector<vector<int>> score(h,vector<int>(w,-1));
	que.push(grid(0,0,0));
	while(que.size()){
		auto q = que.top();
		que.pop();
		if(score[q.r][q.c] != -1)continue;
		score[q.r][q.c] = q.k;
		int a[] = {1,2,3};
		P dir[] = {{1,0},{0,1},{-1,0},{0,-1}};
		P dir2[] = {{-2,-1},{-2,0},{-2,1},{-1,-2},{-1,-1},{-1,0},{-1,1},{-1,2},{0,-2},{0,-1},{0,0},{0,1},{0,2},{1,-2},{1,-1},{1,0},{1,1},{1,2},{2,-1},{2,0},{2,1}};
		for(auto d : dir){
			int r = q.r + d.first;
			int c = q.c + d.second;
			if(r < 0 || c < 0 || r >= h || c >= w)continue;
			if(s[r][c] == '#')continue;
			que.emplace(q.k,r,c);
		}
		for(auto d : dir2){
			int r = q.r + d.first;
			int c = q.c + d.second;
			if(r < 0 || c < 0 || r >= h || c >= w)continue;
			que.emplace(q.k + 1,r,c);
		}
	}
	cout << score[h-1][w-1] << endl;
}
