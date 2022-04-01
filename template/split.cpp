#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;

vector<string> split(string text, string delimiter = " "){
  vector<string> words{};
  size_t pos = 0;
  while ((pos = text.find(delimiter)) != string::npos) {
    words.push_back(text.substr(0, pos));
    text.erase(0, pos + delimiter.length());
  }
  words.push_back(text);
  return words;
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  string s;
  getline(cin, s);
  vector<string> list = split(s);
  for(auto e : list){
    cout << e << " ";
  }
  cout << endl;
}

/* example input
3
a b c

*/