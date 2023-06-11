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
struct my{
    string a;
    bool ex;
    my(string ain, bool exin){
        a = ain;
        ex = exin;
    }
};
bool cmp(const my &a, const my &b){
    return a.a > b.a;
}
int main(){
    int n;
    cin >> n;
    vector<my> data;
    rep(i,n){
        string str;
        cin >> str;
        if(str[0] == '!'){
            string newstr = "";
            rep(i,str.length()){
                if(i ==0)continue;
                newstr += str[i];
            }
            data.emplace_back(newstr, true);
        }
        else data.emplace_back(str, false);
    }
    sort(data.begin(), data.end(),cmp);
    my pre = data[0];
    rep(i,n){
        if(i == 0)continue;
        if(data[i].a == pre.a && pre.ex != data[i].ex){
            cout << data[i].a << endl;
            return 0;
        }
        pre = data[i];
    }
    cout << "satisfiable" << endl;
}
