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
struct Person{
	ll num,idx,res;
	static bool comp_num(Person &a, Person &b){
		return a.num < b.num ;
	}
	static bool comp(Person &a, Person &b){
		return a.idx < b.idx;
	}
};
int main(){
	ll n,k;
	cin >> n >> k;
	vector<Person> people(n);
	rep(i,n){
		cin >> people[i].num;
		people[i].idx = i;
	}
	sort(people.begin(), people.end(), Person::comp_num);
	ll remainder = k % n;
	ll quotient = k / n;
	rep(i,n){
		people[i].res = quotient;
		if(i < remainder)people[i].res++;
	}
	sort(people.begin(), people.end(), Person::comp);
	rep(i,n){
		cout << people[i].res << endl;
	}
}
