/*

base class :	private,protected,public

class derived1: public base -> private,protected,public

This is called private inheritance
class derived2: *private* base -> private,protected,public


base b 	   -> can only access public variables of base class.
derived d1 -> public variables of derived1
derived d2 -> public members of derived 2

Protected variables are only available in the class hierarchy.

Can d1 access public members of base class?
	Yes

For Public Inheritance, can  private,protected,pulic can access to protected of the base class
Also or Private Inheritance it is smae

Using d1 I can access public of base class
Using d2, I cannot access public of base class
This is the difference between public and private Inheritance.
*/

class shape{

protected:
		int *p;
public:
		shape(){
			p = new int;
			*p = 20;
		}
		// Make destructor of shape virtual
		~shape(){
			delete p;
		}
};
class circle:public shape{
	public:
		circle()
		{
			int q = *p;
		}
		~circle()
		{
			cout <<*p<<endl;
		}
};

class base{
public:
	~base()
	{
		cout<<"in dtor"<<endl;
	}
	virtual void fun1()
	{
		cout<<"in Base"<<endl;
	}
};


//Calling virtual function from destructor!
class derived:public base
{
public:
	~derived()
	{
		base *p;
		p = this;
		this->fun1();
	}
	void fun1()
	{
		cout<<"In derived"<<endl;
	}
};

int main()
{
	shape *s;
	circle *c;

	c = new circle;

	s = c;
	//s is the upcasted pointer!
	delete s;
	// This will call destructor of shape class
	// But destruction should happen of circle
	// since we need to print 'p'
	// Flow of destruction should happen from derived to base

	derived d;

	//Destructor of d will be called
	// this will contain derived class object
	// p->fun1() will be called and "in der" will be printed.
	return 0;
}


// Virtual Base class
/*

			   Base
	derived1         derived2

			derived3
       from derived1,derived2


How will you solve the ambiguity of Base class data in this configuration?
*/

//Solution


class base
{
protected:
	int data;
public:
	base() {data = 500;}
}

class derived1: virtual public base{};
class derived2: virtual public base{};

class derived3:public derived1,public derived2
{
	int getdata()
	{
		return data;
	}
};

if we do derived3.getdata() we will get one copy of data
because of 'Virtual' keyword!





