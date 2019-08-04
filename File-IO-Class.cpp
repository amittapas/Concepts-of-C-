/*
Limitations of stdio.h

1)Difficult to remember different format specifiers-%c%d%o etc
2)Illogical Conversions - int to float, float to int
3)Poor reporting in case of mismatch
4)Not easily extensible - overloading of printf() not possible
							eg position cursor and then printf()
5)Too Manu overheads	- interpreter loaded at runtime
							eg printf() has %c%f%c%c ----too much overhead


ios library

Stream -> flow of data


Formatiing Flags 	<----ios [IO specification class] ------> streambuf pointer
Error,file oprtatio mode										Manages buffer
																Low level functions

istream derived from ios << receive data
ostrea, dervied from ios >> output data

istream_withassign   from istream   ------> cin
ostream_Withassign   from ostream   ------> cout

cin >> i ---> overloaded operatiion using cin object 

*/
#include <iostream>
#include <stdio.h>
using namespace std;

class inputFile
{
	private:
		FILE *fp;
	public:
		inputFile(char *n)
		{
			fp = fopen(n,"rb");
		}
		void read(void *x,int size)
		{
			//1 is the frequecy of the oepration
			fread(x,size,1,fp);
		}
		void close()
		{
			fclose(fp);
		}
};

class outputFile
{
	private:
		FILE *fp;
	public:
		outputFile(char *n)
		{
			fp = fopen(n,"wb");
		}
		void write(void *x,int size)
		{
			//1 is the frequecy of the oepration
			fwrite(x,size,1,fp);
		}
		void close()
		{
			fclose(fp);
		}
};

struct emp
{
	char name[20];
	int age;
	float salary;
};


int main(int argc, char const *argv[])
{
	emp e1 = {"Amit",29,4000000},e2;

	outputFile w("samplefile");
	w.write(&e1,sizeof(emp));
	w.close();

	inputFile r("samplefile");
	r.read(&e2,sizeof(emp));
	r.close();

	cout<<e2.name<<" "<<e2.age<<" "<<e2.salary<<endl;
	return 0;
}