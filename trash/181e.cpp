#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,y) for(int x=0;x<y;x++)
#define get(a,b) (b < 0 ? 0 : a[b])
vector<int> front;
vector<int> back;
vector<int> stu;
vector<int> tra;
int n,m;
ll cal(int stu_order, int t_tall);
int main(){
    cin >> n >> m;
    stu.resize(n);
    tra.resize(m);
    rep(i,n){
        cin >> stu[i];
    }
    stu.push_back(1e9);
    stu.push_back(1e9);
    stu.push_back(-1e9);
    stu.push_back(-1e9);
    n+= 4;
    rep(i,m){
        cin >> tra[i];
    }
    sort(stu.begin(),stu.end());

    if(n > 1){
        int a = 0;
        int b = n-2-a;
        front.push_back(stu[a+1] - stu[a]);
        back.push_back(stu[b+1] - stu[b]);
        a+=2;
        while(a+1 <= n-1){
            b = n-2-a;
            front.push_back(front[front.size()-1] + stu[a+1] - stu[a]);
            back.push_back(back[back.size()-1] + stu[b+1] - stu[b]);
            a+=2;
        }
    }
    ll min = 1e9;
    for(int t=0;t<m;t++){
        int j = lower_bound(stu.begin(),stu.end(),tra[t]) - stu.begin();
        if (j % 2 != 0)j--;
        ll result = cal(j,t);
        if(min > result)swap(min,result);
    }
    cout << min << endl;
}
ll cal(int s, int t){
    return front[s/2 - 1] + back[(n - 1 - s)/2 - 1] + abs(stu[s] - tra[t]);
}