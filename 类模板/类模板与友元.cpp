#include<iostream>
#include<string>

using namespace std;

//全局函数 类外实现
//提前让编译器知道person的存在
template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "类外实现------姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//全局函数 类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "类内实现------姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	}

	//加空载参数列表
	friend void printPerson2<>(Person<T1, T2> p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	T1 m_Name;
	T2 m_Age;
};

void test01()
{
	Person<string, int>p1("Tom", 18);
	printPerson(p1);
}

void test02()
{
	Person<string, int>p2("Tom", 18);
	printPerson2(p2);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}