#include<iostream>
#include<vector>
using namespace std;
template<typename T>//my_vector<int>がint型でなくても使えるようテンプレート宣言する
struct my_vector :std::vector<T>{
    using std::vector<T>::vector;//最後のvectorは<T>をつけない
    void print(){
        for(int i=0;i<this->size();i++){
            cout << (*this)[i] << " ";// thisは宣言された要素のポインタ
        }
        cout << endl;
    }
};
int main(){
    my_vector<int> a = {1,2,3};
    a.print();
    //output
    //1 2 3 
}