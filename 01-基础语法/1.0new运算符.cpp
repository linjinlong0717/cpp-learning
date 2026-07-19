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
	delete p;
	//cout<<*p<<endl;  内存已经被释放，再次访问就是非法操作，会报错
}
int test02() //在堆区利用new开辟数组
{
	int* arr = new int[10]; //10代表数组有10个元素
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