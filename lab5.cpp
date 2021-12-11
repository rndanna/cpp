#include <iostream>

using namespace std;

void ff() {
	cout << "GLOBAL" << endl;
}

class BASE {
	friend class DERIVED;

    public: int i;

    protected: long l;

    private: double d;

    public:
        BASE(int i_, long l_, double d_) {
            i = i_;
            l = l_;
            d = d_;
        }
        BASE() {
            i = 0;
            l = 0;
            d = 0;
	    }
        ~BASE() {}

        double GetD() {
            return d;
        }

        void SetD(double d_) {
            d = d_;
        }

        void ff() {
            cout << " Class BASE" << endl;
        }

        double* GetAdressD() {
            return &d;
        }

        int* GetAdressI() {
            return &i;
        }

        long* GetAdressL() {
            return &l;
        }
};

class DERIVED : public BASE {
    private: float f;

    public:
        DERIVED(float f_, int i_, long l_, double d_) :BASE(i_, l_, d_) {
            f = f_;
            i = i_;
            l = l_;
            d = d_;
        }
        DERIVED() {
            f = 0;
        }
        ~DERIVED() {};

        float* GetAddresF() {
            return &f;
        }
        
        void ff() {
            cout << "Class DERIVED" << endl;
        }
        friend class DERIVED_1;
        friend ostream& operator<<(ostream& out, DERIVED& ob);
};

ostream& operator<<(ostream& ostream, DERIVED& ob) {

	ostream << ob.f << " " << ob.i << " " << ob.l << " " << ob.GetD() << endl;
	ostream << ob.GetAddresF() << " " << ob.GetAdressI() << " " << ob.GetAdressL() << " " << ob.GetAdressD();

	return ostream;
}

class DERIVED_1 : public DERIVED {
    public:
        DERIVED_1(float f_, int i_, long l_, double d_) :DERIVED(f_, i_, l_, d_) {
            f = f_;
            i = i_;
            l = l_;
            SetD(d_);
        }
        void foo() {
            i++;
            l += 1;
            ff();
        }
};



int main() {
	DERIVED_1 test(1.0, 2, 300000, 4.000000);
	test.foo();
	cout << "Size BASE: " << sizeof(BASE) << endl;
	cout << "Size DERIVED: " << sizeof(DERIVED) << endl;
	cout << test;

	return 0;
}