#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

class Abonent
{
public:
    int id;

protected:
    string surname;
    string phoneNumber;

public:
    Abonent(int abonentId, string abonentSurname, string abonentPhoneNumber)
    {
        id = abonentId;
        surname = abonentSurname;
        phoneNumber = abonentPhoneNumber;
    };

    ~Abonent(){};

    friend class Notebook;
};

class Notebook
{
public:
    void change(Abonent &obj, string phoneNum)
    {
        obj.phoneNumber = phoneNum;
    }

    void show(Abonent &obj)
    {
        cout << "|" << setw(5) << obj.id;
        cout << "|" << setw(15) << obj.surname;
        cout << "|" << setw(11) << obj.phoneNumber << "|" << endl;
    }
};

int main()
{
    vector<Abonent> abonentArr;
    Notebook notebook;

    abonentArr.push_back(Abonent(1, "Abonent1", "89234234234"));
    abonentArr.push_back(Abonent(2, "Abonent2", "89182342424"));
    abonentArr.push_back(Abonent(3, "Abonent3", "89234252151"));
    abonentArr.push_back(Abonent(4, "Abonent4", "89124256216"));
    abonentArr.push_back(Abonent(5, "Abonent5", "89353535453"));

    for (int i = 0; i < abonentArr.size(); i++)
    {
        if (abonentArr[i].id == 2)
        {
            notebook.change(abonentArr[i], "89969053820");
            break;
        }
    }

    cout << "|" << setw(5) << "ID";
    cout << "|" << setw(15) << "SURNAME";
    cout << "|" << setw(11) << "PHONE"
         << "|" << endl;
    cout << setw(30) << " _________________________________" << endl;
    
    for (int i = 0; i < abonentArr.size(); i++)
    {
        notebook.show(abonentArr[i]);
    }

    return 0;
}