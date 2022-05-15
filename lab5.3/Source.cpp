#include <iostream>
using namespace std;
class A
{
protected:
	int x;
public:
	A(int x = 0)
	{
		this->x = x;
	}
};
class B
	: public A
{
	int y;

public:
	B(int x = 0, int y= 0)
		: A(x)
	{
		this->x = x;
	}
	B(A a)
	{
		throw a;
	}
};
int main()
{
	A a(1);
	B b(2);
	try
	{
		b = a;
		cout << "Continue" << endl;
	}
	catch (B)
	{
		cout << "catch(B)" << endl;
		exit(1);
	}
	catch (A)
	{
		cout << "catch(A)" << endl;
		exit(2);
	}
	cout << "End" << endl;
	return 0;
}