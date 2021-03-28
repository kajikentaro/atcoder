#include<bits/stdc++.h>
namespace myextensions{
using namespace std;
template<typename T,typename U>
class pair :public std::pair<T,U>{
    using std::pair<T,U>::pair;
    public:
    pair<T,U> operator+(const pair<T,U> p){
        return pair<T,U>(this->first + p.first, this->second + p.second);
    }
};
struct string : std::string{
    using std::string::string;
    void print(){
        cout << *this << endl;
    }
};
}
using namespace std;
int main(){
    namespace std = myextensions;
    std::pair<int,int> test(1,2);
    std::pair<int,int> test2(1,2);
    cout << test.first << endl;
    cout << (test + test2).first << endl;
}