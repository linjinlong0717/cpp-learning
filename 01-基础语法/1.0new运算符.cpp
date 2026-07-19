new操作符
一、C++中利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
语法：new数据类型
利用new创建的数据，会返回该数据对应的类型的指针

二、代码演示：
1.new的基本语法
int* func()
{
	int* p = new int(10);
	return p;
}
void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;//都是输出10
	delete p;   //变成“悬挂指针”
	  //cout<<*p<<endl;  内存已经被释放，再次访问就是非法操作，会报错

	p = nullptr;  // 养成好习惯！防止后续误用导致程序崩溃
}
void test02() //在堆区利用new开辟数组
{
	int* arr = new int[10]; //10代表数组有10个元素
	int* arr2 = new int[10]();  // 分配10个int，并初始化为0（值初始化）
	int* arr3 = new int[10] {1, 2};	//1, 2, 0, 0, ...（前两个指定，后面自动补 0）//这种写法正是C++11标准引入的新特性
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr; //释放堆区数组
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

三、C语言动态内存管理malloc/calloc/realloc  //要加#include<stdlib.h> 头文件
1.malloc（最常用）-- 分配原始内存
函数原型：void * malloc(size_t size);
作用：在堆上申请 size 个字节的连续内存空间
返回值：成功返回指向这块内存的指针（void* ），失败返回 NULL
特点：不会初始化内存，里面存的是垃圾值（上次使用留下的数据）
//eg: int* p = (int*)malloc(10*sizeof(int));

2.calloc(带初始化的malloc) -- 分配并清零
//eg:int* p = (int*)calloc(10,sizeof(int));

3.realloc(伸缩内存) -- 扩大或缩小已有空间
//eg: 
int main()
{
	//申请 100 个int
	int* p = (int*)malloc(100 * sizeof(int));
	if (NULL==p) return -1;         //注意：NULL 写在左边要是少写一个=，可以报错

	//缩容到 10 个int
	int* tmp = (int*)realloc(p, 10 * sizeof(int));
	if (NULL==tmp)
	{
		printf("缩容失败\n");
		free(p);
		p = NULL;
		return -1;  //一般return非零代表失败
	}
	p = tmp;
	printf("缩容成功，现在只能安全使用 p[0] ~ p[9]\n");
	free(p);
	p = NULL;
	return 0;
}


四、
当你写下 new MyClass() 时，编译器干了两件事：

1.分配内存：底层调用 operator new（可以理解为对 malloc 的封装）。
2.构造对象：在分配好的内存上调用 MyClass 的构造函数。

同理，delete p 也干两件事：

1.析构对象：调用 p 指向对象的析构函数。
2.释放内存：底层调用 operator delete（对 free 的封装）

五、new / delete 与 malloc / free 的五大核心区别
1. 本质不同
new / delete：是 C++ 关键字（运算符），编译器直接支持。
malloc / free：是 C 标准库函数，必须包含 <stdlib.h> 头文件才能调用。

2. 内存大小计算
new / delete：自动计算内存大小。例如 new int[10]，编译器已知类型大小，无需手动参与。
malloc / free：必须手动计算字节数。必须写成 malloc(sizeof(int) * 10)，容易算错导致溢出。

3. 返回值与类型安全
new / delete：直接返回对应类型的指针（如 int* ），无需强制转换，类型安全。
malloc / free：返回 void* 万能指针，必须强制转换成目标类型（如(int*)），容易出错。

4. 初始化和构造（最核心区别）
new / delete：分配内存后会自动调用构造函数（初始化对象），delete 前会自动调用析构函数。
malloc / free：仅分配原始内存，不会执行构造函数，也不会执行析构函数（对C++类对象是致命缺陷）。

5. 失败处理机制
new / delete：分配失败时抛出异常（std::bad_alloc），通常不需要手动判空。
malloc / free：分配失败时返回 NULL，必须手动检查 if (p == NULL)，否则引发崩溃。

追加第6点（工程避坑必看）：
数组释放：new[] 必须搭配 delete[] 释放整个数组，否则内存泄漏；malloc 分配的内存直接用 free，无数组释放概念。