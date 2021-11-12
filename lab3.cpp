#include <iostream>

using namespace std;

class Goods
{
    string name;
    string date;
    int cost;
    int amount;
    int id;

public:
    Goods(string goodsName, string goodsDate, int goodsCost, int goodsAmount, int goodsId)
    {
        name = goodsName;
        date = goodsDate;
        cost = goodsCost;
        amount = goodsAmount;
        id = goodsId;

        cout << "Counstructor" << endl;
    }

    Goods()
    {
        name = "name";
        date = "1111-11-11";
        cost = 0;
        amount = 0;
        id = 0;

        cout << "Default constructor" << endl;
    }

    Goods(Goods &obj)
    {
        name = obj.name;
        date = obj.date;
        cost = obj.cost;
        amount = obj.amount;
        id = obj.id;

        cout << "Copy Counstructor" << endl;
    }

    ~Goods()
    {
        cout << "Destructor" << endl;
    };

public:
    void Show()
    {
        cout << endl;
        cout << "Наименование: " << name << endl;
        cout << "Дата поступления: " << date << endl;
        cout << "Стоимость: " << cost << endl;
        cout << "Количество: " << amount << endl;
        cout << "Идентификатор: " << id << endl;
    }

    Goods operator=(Goods &obj);
};

Goods tovar(Goods &s)
{
    return s;
}

Goods Goods::operator=(Goods &obj)
{
    name = obj.name;
    date = obj.date;
    cost = obj.cost;
    amount = obj.amount;
    id = obj.id;
    cout << "Operator" << endl;

    return *this;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Goods good0("tovar", "01.01.2001", 1111, 11, 1);
    Goods good1(good0);
    Goods good2;
    tovar(good1);
    good0 = good2;

    good0.Show();
    good1.Show();

    return 0;
}