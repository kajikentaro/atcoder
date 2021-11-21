#include<bits/stdc++.h>
using namespace std;
template<typename T,typename U>
struct my_pair1 :public std::pair<T,U>{
    using std::pair<T,U>::pair;
    pair<T,U> operator+(const pair<T,U> p){
        return pair<T,U>(this->first + p.first, this->second + p.second);
    }
};
template<typename T,typename U>
class my_pair2 :public std::pair<T,U>{
    using std::pair<T,U>::pair;
    public:
    pair<T,U> operator+(const pair<T,U> p){
        return pair<T,U>(this->first + p.first, this->second + p.second);
    }
};
struct my_string : std::string{
    using std::string::string;
    void print(){
        cout << *this << endl;
    }
};
int main(){
    my_string s;
    cin >> s;
    cout << s << endl;
    my_pair2<int,int> test(1,2);
    my_pair2<int,int> test2(1,2);
    cout << test.first << endl;
    cout << (test + test2).first << endl;
}