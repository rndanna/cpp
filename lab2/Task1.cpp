#include <iostream>

using namespace std;


class Test
{
protected:

    int W;

    void Z()
    {
        cout << "Это закрытая функция класса Test" << endl;
    };

public:

    Test(int num = 1)
    {
        W = num;
    };

    ~Test(){};

    friend void fun(Test _ob);
};

void fun(Test _ob)
{
    cout << "W = " << _ob.W << endl;

    _ob.Z();
}

int main()
{
    Test test;

    fun(test);

    return 0;
}

