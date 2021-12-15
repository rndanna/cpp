#include <iostream>
#include <string>

using namespace std;

class Base1 {
    private: int i;

    public:
        Base1() {
            i = 0;
            cout << "Constructor  Base1 without parameters  \n";
        }
        Base1(int i_) {
            i = i_;
            cout << "Constructor  Base1 with parameters  \n";
        }
        ~Base1() {}

        void putI(int i_){
            i = i_;
        }

        int getI() {
            return i;
        }
};

class Base2 {
    private:  string name;

    public:
        Base2() {
            name = "Empty";
            cout << "Constructor Base2 without parameters \n";
            }
        Base2(string name_) {
            name = name_;
            cout << "Constructor  Base2 with parameters \n";
        }
        ~Base2() {}

        void putName(string name_){
            name = name_;
        }

        string getName() {
            return name;
        }
};

class Derived: public Base1, public Base2 {
    private: char ch;
    public:
    Derived() {
        ch = 'V';
        cout << "Constructor Derived without parameters \n";
    }
    Derived(char ch_, string name_, int i_): Base1(i_), Base2(name_) {
        ch = ch_;
        cout << "Constructor Derived with parameters \n";
    }

    void  putCh(char ch_){
        ch = ch_;
    }

    char getCh(){
        return ch;
    }

    friend ostream& operator<<(ostream& out, Derived& ob);
};

ostream& operator<<(ostream& out, Derived& ob) {

    out << ob.getI() << " " << ob.getName() << " " << ob.getCh() << endl;
    return out;
}

int main() {
    Derived test, test2('C', "name", 5);
    cout << test << test2;
}