#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
tuple<vector<int>,int> func(int a, int r){
    int now_v = a % r;
    int start_v = now_v;
    vector<int> ans;
    ans.push_back(now_v);
    map<int,int> m;
    m[now_v]++;
    int c = 0;
    while(1){
        int new_v = (start_v * now_v) % r;
        now_v = new_v;

        m[new_v]++;
        if(m[new_v] == 2){
            if(new_v != start_v)cout << 1/0;
            break;
        }
        ans.push_back(new_v);
    }
    return tie(ans, c);
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> r1,r2;
    int d1,d2;
    tie(r1,d1) = func(a,10);
    int r1_s = r1.size();

    tie(r2, d2) = func(b,r1_s);
    int r2_s = r2.size();

    int r2_n = r2[(c + r2_s -1) % r2_s];
    int r1_n = r1[(r2_n + r1_s - 1) % r1_s];

    cout << r1_n << endl;
}
