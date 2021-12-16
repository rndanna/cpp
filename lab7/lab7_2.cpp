#include <iostream>
#include <string>
using namespace std;

class Complex {
private:

    double m_re, m_im;

public:

    Complex();
    Complex(double re, double im = 0);

    double GetRe() {
        return m_re;
    }
    double GetIm() {
        return m_im;
    }


    Complex operator*(const Complex& a) {
        return Complex(m_re * a.m_re - m_im * a.m_im,
            m_re * a.m_im - m_im * a.m_re);
    }

    Complex operator*(const double& a) {
        return Complex(m_re * a, m_im * a);
    }

    Complex& operator=(const Complex& a)
    {
        if (this != &a)
        {
            m_re = a.m_re;
            m_im = a.m_im;
        }
        return *this;
    }
    double& operator=(const double& a)
    {
        return m_re;
    }

    friend ostream& operator<< (ostream& out, const Complex& x)
    {
        return (out << "(" << x.m_re << "," << x.m_im << ")");
    }
};


template <class T>
class matrix {

private:
    T** M;
    int m;
    int n;

public:

    matrix()
    {
        n = m = 0;
    }

    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;

        M = (T**) new T * [m];


        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }

    void Print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    matrix operator=(const matrix& _M)
    {
        if (n > 0)
        {

            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }

        m = _M.m;
        n = _M.n;

        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;


    }
    ~matrix()
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }


};

int main() {
    matrix<int> in(2, 3);
    in.SetMij(1, 1, 2.1);
    in.SetMij(1, 2, 3);
    in.SetMij(2, 1, 'h');

    in.Print();

    // Complex comp(1.0);

    // in.SetMij(2, 2, 3);
	return 0;
}
