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
    string s;
    cin >> s;
    vector<char> out(s.size() * 2);
    int right = 0 + s.size();
    int left = -1 + s.size();
    bool reverse = false;
    int cnt = 0;
    rep(i,s.size()){
        if(s[i] == 'R'){
            reverse = !reverse;
            continue;
        }
        cnt++;
        if(reverse){
            out[left] = s[i];
            left--;
        }else{
            out[right] = s[i];
            right++;
        }
    }
    right--;
    left++;
    auto pop = [&](){
        char ans;
        if(reverse){
            ans = out[right];
            right--;
        }else{
            ans = out[left];
            left++;
        }
        return ans;
    };
    vector<char> sta;
    rep(i,cnt){
        sta.push_back(pop());
        while(1){
            if(sta.size() < 2)break;
            if(sta[sta.size() - 1] == sta[sta.size() - 2]){
                sta.pop_back();
                sta.pop_back();
            }else break;
        }
    }
    for(auto ch : sta){
        cout << ch;
    }
    cout << endl;
}
