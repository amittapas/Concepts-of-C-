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