#include <iostream>
#include <string>

using namespace std;

class DomesticAnimal {
    protected:
        int weight;
        int price;
        string color;

    public:
        DomesticAnimal() {
            price = 0;
            weight = 0;
            color = "black";
        }
        DomesticAnimal(int price_, int weight_, string color_) {
            price = price_;
            weight = weight_;
            color = color_;
        }
        void print(){
            cout << "Class DomesticAnimal \n";
            cout << price << "  " << weight << "  " << color << "  ";
        }
};

class Cow: virtual public DomesticAnimal {
    public:
        Cow() {}

        Cow(int price_, int weight_, string color_) : DomesticAnimal(price_, weight_, color_) {}

        void print() {
            cout << "Class Cow \n";
            cout << price << "  " << weight << "  " << color << "  ";
        }
};

class Buffalo : virtual public DomesticAnimal {
    public:
        Buffalo() {}

        Buffalo(int price_, int weight_, string color_) : DomesticAnimal(price_, weight_, color_) {}

        void print() {
            cout << "Class Buffalo \n";
            cout << price << "  " << weight << "  " << color << "  ";
        }
};

class Beefalo : public Cow,  public Buffalo {
    public:
        Beefalo() {}

        Beefalo(int price_, int weight_, string color_){
            price = price_;
            weight = weight_;
            color = color_;
        }

        void print() {
            cout << "Class Beefalo \n";
            cout << price << "  " << weight << "  " <<  color << endl;
        }
};

int main() {
	Beefalo test(1000, 1, "green");
	test.print();
    
    Cow test1(1001, 4, "blue");
	test1.print();

	return 0;
}
