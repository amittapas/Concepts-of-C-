//Polymorphism is same interface but different implementation.
//Virtual functions are used for Run-time (Dynamic) polymorphism.
#include <iostream>
using namespace std;

class shape
{
	public:
	//Make this virtual
	//So that p->draw() will call draw of the derived class method.
	virtual void draw()
	{
		cout<<"shape"<<endl;
	}

};

class circle : public shape
{
	public:
	void draw()
	{
		cout<<"circle"<<endl;
	}
	// virtual void draw() = 0
	// This will make draw() a 'pure virtual function'
	// Such class is called abstract class ,we are not allowed to create object of such class.
	// Shape s , new shape() is not allowed
	// Shape *p is allowed.
	// We do not want developer to call or creater Shape objects.
};

class rectangle : public shape
{
	public:
	void draw()
	{
		cout<<"rect"<<endl;
	}
};

int main()
{
	shape *p;
	
	circle c;
	rectangle r;

	p = &c; 	// C++ makes an exception here for parent child mismatch
	p->draw(); 	//This is called Upcasted pointer

	p= &r;		
	p->draw();

	//This will call shape's draw() function ,if we are not making it virtual.
	//If we use upcasted pointer then the base class function will get call.
	//The pointer 'p' ie the type decides which function will be called. (if draw is not virtual)
}
/*
	Notes-:
				1)Data cannot be virtual ,only functions can be virtual.
				2)For class to be abstract, only one function must be virtual others can be non virtual.
				3) base *b
				   derived d;
				   b = &d;  ---> This is called upcasting
				4)Abstract class must contains one pure virtual functions. May contain non virtual functions.
				  Object creation is not allowed.
				5)Virtual function mechanism
					- Upcasted pointer
					- If function names are same
						-Base class function is called if non- virtual
						-Derived class function is called if virtual

				6) A virtual function is early bound (Compiler-time) if called through object
				   A virtual function is late bound  (Run-time) if called thorugh pointer(upcasted or not).
*/
