#include<bits/stdc++.h>
using namespace std;
int main(){
	long long N;
	cin >> N;
	vector<long long> ans_front;
	vector<long long> ans_back;
	for(int i=1;i<sqrt(N);i++){
		if(N%i==0){
			ans_front.push_back(i);
			ans_back.push_back(N/i);
		}
	}
	if(sqrt(N) - (int)sqrt(N) ==0){
		ans_front.push_back(sqrt(N));
	}
	for(int i=0;i<ans_front.size();i++){
		cout << ans_front[i] << endl;
	}
	for(int i=ans_back.size()-1;i>=0;i--){
		cout << ans_back[i] << endl;
	}
	return 0;
}
