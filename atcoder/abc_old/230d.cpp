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
struct wall{
  ll left,right,idx;
};
int main(){
  ll n,d;
  cin >> n >> d;
  vector<wall> block_left(n);
  rep(i,n){
    cin >> block_left[i].left >> block_left[i].right;
    block_left[i].idx = i;
  }
  vector<wall> block_right = block_left;

  auto cmp_right = [](wall &a, wall& b){return a.right < b.right;};
  auto cmp_left = [](wall &a, wall& b){return a.left < b.left;};
  sort(block_left.begin(), block_left.end(), cmp_left);
  sort(block_right.begin(), block_right.end(), cmp_right);

  ll li = 0;
  vector<ll> used(n);
  ll ans = 0;
  rep(ri,n){
    if(used[block_right[ri].idx])continue;
    ans++;
    while(1){
      if(li >= n)break;
      if(block_left[li].left <= block_right[ri].right + d-1){
        used[block_left[li].idx] = true;
        li++;
      }else{
        break;
      }
    }
  }
  cout << ans << endl;

}

