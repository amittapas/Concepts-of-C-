/*
Formatting Flags:

1)On/Off Flags
	
	one argument setf()
	unsetf()

2)Group Flags
	
	two argument setf()

Flags		Meaning

skipws		Skip whitespace
showbase	Use base indicator on output
showpoint	Show decimal point and trailing zeros for floats in output
uppercase	Use uppercase A-F
dec         decimal
oct			octal
hex			hexadecimal
left		Left Justify Output
right		Right justify Output

----------Manipulators--------------------

No argument  - iostream
	hex
	oct
	
One Argument - iomanip
	Uppercase
	left

Manipulators list

dec
oct
hex
flush
setw(int n)
setfill(char n)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout.setf(ios::right);
	cout<<"Open Your eyes"<<endl;
	cout.unsetf(ios::right);

	cout.setf(ios::showbase | ios::uppercase);
	int i = 32767;
	int j = 2000;
	//Two argument setf
	cout.setf(ios::hex,ios::basefield);  //Flags in group
	cout<<i<<" "<<j<<endl;

	cout.setf(ios::basefield,ios::dec);

	cout.width(40);
	cout<<"Hello"<<endl;


	cout.setf(ios::left,ios::adjustfield);
	cout.width(40);

	cout<<"Then make it true"<<endl;

	//Manipulators

	cout<<hex<<i<<endl;
	cout<<oct<<i<<endl;
	cout<<setw(40)<<"Hello"<<endl;

	cout<<setiosflags(ios::left);
	cout<<resetiosflags(ios::showbase | ios::uppercase);

	return 0;
}

