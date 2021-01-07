#include<iostream>
#include<string>
#include "Myarr.hpp"
using namespace std;

void PrintArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int> arr1(5);

	cout << "打印数组arr1：" << endl;
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	PrintArray(arr1);
	
	cout << "数组arr1容量：" << arr1.getCapacity() << endl;
	cout << "数组arr1大小：" << arr1.getSize() << endl;

	//MyArray<int> arr2(arr1);
	MyArray<int> arr2(100);
	arr2 = arr1;
	//尾删：
	arr2.Pop_Back();

	cout << "打印数组arr2：" << endl;
	PrintArray(arr2);

	cout << "数组arr2容量：" << arr2.getCapacity() << endl;
	cout << "数组arr2大小：" << arr2.getSize() << endl;

}

//测试任意数据类型
class Person
{
public:
	Person() {};
	
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << " 年龄："<< arr[i].m_Age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(5);

	Person p1("胖灵", 20);
	Person p2("挂灵", 20);
	Person p3("舔灵", 20);
	Person p4("捧灵", 20);
	Person p5("魔灵", 20);

	//数组插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	cout << "打印数组arr：" << endl;
	printPersonArray(arr);

	cout << "数组arr容量：" << arr.getCapacity() << endl;
	cout << "数组arr大小：" << arr.getSize() << endl;

	//MyArray<Person> arr2(arr);
	MyArray<Person> arr2(100);
	arr2 = arr;

	arr2.Pop_Back();

	cout << "打印数组arr2：" << endl;
	printPersonArray(arr2);

	cout << "数组arr2容量：" << arr2.getCapacity() << endl;
	cout << "数组arr2大小：" << arr2.getSize() << endl;
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}