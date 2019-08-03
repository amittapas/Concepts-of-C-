#include <iostream>
using namespace std;

class ex {};
//The size of this object is 1 byte
//Every object is of non-zero byte, sine we will not able to get address then!

class ex1
{
	public:
		virtual void f()
		{}
};

int main()
{
	ex e1
	//Size of e1 is 1 byte

	ex1 e2;
	//Size of e2 is 4 byte!!!!!
	return 0;
}