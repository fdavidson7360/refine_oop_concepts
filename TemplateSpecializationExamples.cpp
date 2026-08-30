#include <iostream>
using namespace std;

template <class T>
class MyClass {
    public:
        MyClass (T x) {
            cout <<x<<" -  not a char"<<endl;
        }
};

template < >
class MyClass<char> {
    public:
        MyClass (char x) {
            cout <<x<<" is a char!"<<endl;
        }
};

int main () {
    MyClass<int> ob1(42);
    MyClass<double> ob2(5.47);
    MyClass<char> ob3('s');
}




// ===== End of Example 1: Template Specialization project


// You are given a Div class template, which has a constructor that takes two parameters and outputs their division.
// You need to specialize the class for strings, which should output the division of the lengths of the parameter strings, 
// as the division operator is not defined for strings.

#include <iostream>
#include <string>
using namespace std;
template <class T>
class Div {
    public:
        Div (T x, T y) {
            cout <<x / y<<endl;
        }
};

template <>
class Div<string> {
    public:
        Div (string x, string y) 
        {
            cout <<x.size() / y.size()<<endl;
        }
};

//your code goes here
int main () {
    string a, b;
    cin >> a >> b;
    int x, y;
    cin >> x >> y;
    
    Div <string> d2(a, b);
    Div <int> d1(x, y);
    
}