#include <iostream>
#include <vector>

using namespace std;

class Worker
{
    string surname;
    string position;
    int year;
    int salary;

    public:

    Worker();
    Worker(string surname, string position, int year, int salary);
    ~Worker(){};

    void show();
    int getSalary();
    int getYear();
    string getPosition();
    void setSalary(int newSalary);
};

Worker::Worker()
{
    cout<< "Фамилия: \n";
    cin>>surname;
    cout<< "Должность: \n";
    cin>>position;
    cout<< "Стаж работы: \n";
    cin>>year;
    cout<< "ЗП: \n";
    cin>>salary;
};

Worker::Worker(string name, string post, int date, int sal)
{
        surname = name;
		position = post;
		year = date;
		salary = sal;
};

void Worker::show()
 {
        cout<<"Фамилия:"<<surname<<endl;
        cout<<"Должность:"<<position<<endl;
        cout<<"Стаж работы:"<<year<<endl;
        cout<<"ЗП:"<<salary<<endl;
 }

 int Worker::getSalary()
{
    return salary;
}

 int Worker::getYear()
{
    return year;
}

 string Worker::getPosition()
{
    return position;
}

void Worker::setSalary(int newSalary)
{
    salary = newSalary;
}


int main() {
	setlocale(LC_ALL, "Russian");

    vector<Worker> array;
	Worker first("Petrov", "Work1", 2010, 25333);
	array.push_back(first);
	Worker second("Petrov2", "Work2", 2011, 20000);
	array.push_back(second);
	Worker third("Petrov3", "Work2", 2012, 19000);
	array.push_back(third);
    array.push_back(Worker());

    int size = array.size();

    cout<<"Работники, стаж которых превышает 5 лет"<<endl;
    for (int i = 0; i < size; i++){
        if ((2021 - array[i].getYear()) > 5){
            array[i].show();
            cout<<"______________________"<<endl;
        }
    }

    cout<<"Работники, зарплата которых больше 19000"<<endl;
    for (int i = 0; i < size; i++){
        if (array[i].getSalary() > 19000){
            array[i].show();
            cout<<"______________________"<<endl;
        }
    }

    cout<<"Работники, у которых работа  Work2"<<endl;
    for (int i = 0; i < size; i++){
        if (array[i].getPosition() == "Work2"){
            array[i].show();
            cout<<"______________________"<<endl;
        }
    }

    return 0;
};



