#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Date {
	int day, month, year;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    Date() {
            day = 0;
            month = 0;
            year = 0;
        }

	Date(int Day, int Month, int Year) { 
		day = Day;
		month = Month;
		year = Year;
	}

    friend ostream& operator<<(ostream& out, Date& ob);
    Date operator+(Date& ob);
	Date operator-(Date& ob);
	Date operator++(int _day);
	Date operator--(int _day);
	Date operator+(int _day);
	Date operator-(int _day);


	~Date() {};
};

Date Date::operator++(int _day) {

    Date temp;

    temp.month = month;
    temp.year = year;
    temp.day = day;
    
    if (day + 1 > temp.days[temp.month]) {
        temp.day = ((day + 1) - temp.days[temp.month]);
        if (temp.month + 1 > 12) {
            temp.month = 1;
            temp.year++;
        }
        temp.month++;
    }
    else temp.day = day + 1;

    return temp;
}

Date Date::operator--(int _day) {

        Date temp;

        temp.month = month;
        temp.year = year;
        temp.day = day;

        if (day - 1 < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - 1));
        }
        else temp.day = day - 1;

    return temp;
}

ostream& operator<<(ostream& out, Date& other) {

    return out << other.day << "." << other.month << "." << other.year;
}

Date Date::operator+ (Date& obj) {

        Date temp;

        temp.year = year + obj.year;

        if (month + obj.month > 12) {
            temp.year++;
            temp.month = ((month + obj.month) - 12) + 1;
        }

        temp.month = month + obj.month;

        if (day + obj.day > temp.days[temp.month]) {
            temp.day = ((day + obj.day) - temp.days[temp.month]);

            if (temp.month + 1 > 12) {
                temp.month = 1;
            }
            temp.month++;
        }
        temp.day = day + obj.day;

        return temp;
    }

Date Date::operator- (Date& obj) {

        Date temp;

        if (day - obj.day < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - obj.day));
        }

        temp.day = day - obj.day;

        if (month - obj.month < 0) {
            temp.year--;

            if (12 - abs((month - obj.month)) == 0) {
                temp.month = 1;
            }
            temp.month = (12 - abs((month - obj.month)));
        }else if(month - obj.month == 0) {
            temp.month = 12;
            temp.year--;
        }
        temp.month = month - obj.month;
        temp.year = year - obj.year;

        return temp;
    }


Date Date::operator+ (int _day) {
        Date temp;

        temp.month = month;
        temp.year = year;

        if (day + _day > temp.days[temp.month]) {
            temp.day = ((day + _day) - temp.days[temp.month]);
            if (temp.month + 1 > 12) {
                temp.month = 1;
                temp.year++;
            }
            temp.month++;
        }else temp.day = day + _day;
        
        return temp;
    }

Date Date::operator- (int _day) {
        Date temp;

        temp.month = month;
        temp.year = year;
        temp.day = day;

        if (day - _day < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - _day));
        }else temp.day = day - _day;
        
        return temp;
    }
 

int main(){
    setlocale(LC_ALL, "Russian");
    Date start(12, 4, 2010);
    Date time(12, 5, 5);
    Date end;
    cout << "Дата начала строительства(Start): " << start << endl;

    end  = start + time;
    cout << "Дата завершения строительства(End): " << end << endl;

    start  = end - time;
    cout << "Дата начала строительства(Start): " << start << endl;

    start  = start + 2;
    cout << "Start + 2: " << start << endl;

    start  = start - 2;
    cout << "Start - 2: " << start << endl;
    
    start = start++;
    cout << "Start++: " << start << endl;

    start = start--;
    cout << "Start--: " << start << endl;
}