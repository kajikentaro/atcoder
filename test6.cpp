#include<iostream>
namespace mystd{
    using namespace std;
    struct string : std::string{
        using std::string::string;
        void print(){
            std::cout << *this << std::endl;
        }
    };
}
using namespace std;
int main(){
    namespace std = mystd;
    string s = "hello";
    s.print();//printがメンバーに見つからないエラー
    cout << s;
}