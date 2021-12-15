#include "figure.h"
#include "figure.cpp"
#include "new_fig.h"
#include "triangle.cpp"
#include <iostream>

int main() {
	Circle ob1(4);
	Rectangle ob2(2);
	Rectangle ob3(3,1);
	Triangle ob4(3.1, 3.0, 6.0);

	ob1.show();
	ob2.show();
	ob3.show();
	ob4.show();

	return 0;
}
