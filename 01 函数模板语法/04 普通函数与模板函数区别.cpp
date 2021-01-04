//#include<iostream>
//#include<string>
//
//using namespace std;
//
////普通函数与函数模板的区别
////1.普通函数调用可以发生隐式类型转换
////2.函数模板 用自动类型推导，不可以发生隐式类型转换
////3.函数模板 用显示指定类型，可以发生隐式类型转换
//
//int myAdd(int a, int b)
//{
//	return a + b;
//}
//
//template <class T>
//T myAdd2(T a,T b)
//{
//	return a + b;
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c'; //c ~ 99 ASICLL 
//
//	cout << myAdd(a, c) << endl; //109
//	//cout << myAdd2(a, c) << endl; //error
//	cout << myAdd2<int>(a, c) << endl;
//
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}