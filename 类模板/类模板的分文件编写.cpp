#include<iostream>
using namespace std;
#include "Person.hpp"

void test01()
{
	Person<string, int> p("Tom", 19);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}