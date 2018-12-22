#include <iostream>


using namespace std;

#define MKSTR(x) #x
#define CONCAT(x, y) x ## y


int main()
{
	cout << MKSTR(hell c++) << endl;
	
	int xy = 100;
    cout << CONCAT(x, y) << endl;

	return 0;
}
