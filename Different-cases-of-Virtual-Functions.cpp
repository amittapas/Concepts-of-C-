Usage of Virtual Functions
	- Runtime polymorphism
	- Calling Derived from base
	- Seperating Interface from Implementation

base
{
	h();									VTABLE
	virtual f();							&base::f();
	virtual g();							&base::g();
}
				
der1 : base									VTABLE
{											&der1::f();
	h();									&base::g(); [Tricky]
	virtual f();
}

der2 : der1
{
	virtual x();								VTABLE
	virtual g();								&der2::f();	
	virtual f();								&der2::g();
}												&der2::x();


main()
{
	//If der1 is not derived from base class
	and we do 
	b = (base*) &d1;
	b->f() will work
	if d1 doesnt have g(),
	then b->g() will throw exception!
	so always do static_cast<base*> ti catch such exception!

	base b;
	b.h() -> base class h
	b.f() -> base class f
	b.g() -> base class g

	der d1;
	d1.h() -> der1 class h
	d1.f() -> der1 class f
	d1.g() -> It will search in der1 and then it will go to base class's g();

	der d2;
	d2.h() -> it will call der1's h()
	d2.f() -> der2's f()
	d2.g() -> der2's g()
	d2.x() -> der2's x()

	base *b;
	der1 d1;
	b = &d1;
	b->h() -> Early Bound ,since h() is not virtual
	b->f() -> der1's f()
	b->g() -> base's g() [Tricky]

	base *b;
	der d2;
	b = &d2;
	b->h() ->  base class h()
	b->f() ->  der2 f()
	b->g() ->  der2 g()
	b->x() ->  ERROR!

	Since x is not virtual in the base class! Offset is not known in the VTABLE!

	der2 *d1;
	der2 d2;
	d1 = &d2;
	d ->h();	h is not virtual 
	d2->f();	der2 f()
	d->x();		It will not work!
}

class base{
	virtual void f1();
	void f2()
	{
		f1();
	}
}

class der:public base
{
	void f1();
}


b = &d;
b->f2() -- >f2() will call derived class f1()