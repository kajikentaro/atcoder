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
struct Job{
    int start,end,fee;
    static bool comp(Job &a, Job &b){
        return a.end < b.end;
    }
};
int main(){
    int n;
    cin >> n;
    vector<Job> jobs(n);
    rep(i,n){
        int c;
        cin >> jobs[i].end >> c >> jobs[i].fee;
        jobs[i].start = jobs[i].end - c + 1;
    }
    sort(jobs.begin(), jobs.end(), Job::comp);
    int day = 1e4+10;
    vector<ll> dp(day);
    int c = 0;
    orep(i,day-1){
        if(c <= n-1 && jobs[c].end == i){
            chmax(dp[i], dp[jobs[c].start - 1] + jobs[c].fee);
            c++;
        }
        chmax(dp[i], dp[i-1]);
    }
    cout << dp[day-1] << endl;
}
