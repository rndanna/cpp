#include <iostream>

using namespace std;

template <class T> T swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
    return a;
}

int main(){
    cout << swap(12, 21) << endl;
    
    return 0;
}
