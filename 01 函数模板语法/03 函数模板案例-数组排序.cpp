#include<iostream>
#include<string>

using namespace std;

//实现通用对数组类型排序的函数
//规则 从大到小
//算法 选择排序
//测试  char数组  int数组

//交换
template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template <class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //认定最大值的下标
		for (int j = i + 1; j < len - 1; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j; //更新最大值下标
			}
		}
		if (max != i)
		{
			//交换 max和i
			mySwap(arr[max], arr[i]);
		}

	}
}

//打印
template <class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char charArr[] = "adfcebg";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, sizeof(charArr));
	myPrint(charArr, sizeof(charArr));
}

void test02()
{
	int intArr[] = { 5,6,7,4,32,2 };
	int num2 = sizeof(intArr) / sizeof(int);
	mySort(intArr, num2);
	myPrint(intArr, num2);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}