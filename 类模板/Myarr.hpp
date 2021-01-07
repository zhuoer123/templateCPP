#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		/*cout << "有参构造的调用" << endl;*/
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造函数
	MyArray(const MyArray& arr)
	{
		/*cout << "拷贝构造的调用" << endl;*/
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//this->pAddress = arr.pAddress;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		//将arr中的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否已满
		if (this->m_Capacity == this->m_Size)
		{
			cout << "容量已满" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val; //数组末尾插入数据
		this->m_Size++; //更新大小
	}

	//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		
		this->m_Size--; //逻辑尾删
	}

	//通过下标访问数组中元素
	T operator[](int index)
	{
		return this->pAddress[index];
	}

	//获取容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取大小
	int getSize()
	{
		return this->m_Size;
	}

	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		/*cout << "operator=的调用" << endl;*/
		//先判断原来堆区是否有数据，有则释放
		if (this->pAddress != NULL)
		{
			delete[] pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	~MyArray()
	{
		/*cout << "析构的调用" << endl;*/
		if (pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
		}
	}


private:
	T* pAddress; //指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小

};