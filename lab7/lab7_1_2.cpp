#include <iostream>

using namespace std;

template <typename T1, typename T2> T1 max(T1 x, T2 y)
{
	return (x > y) ? x : y;
}
int main(){
    cout << "a = " << max('a', '1') << endl;
    cout << "b = " << max(0, 1) << endl;
    cout << "ch = " << max("Hello","World") << endl;

	return 0;
}
