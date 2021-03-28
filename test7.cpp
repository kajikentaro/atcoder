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
using namespace mystd;
int main(){
    string s = "hello";//stingが曖昧だというエラー
    s.print();
    cout << s;
}