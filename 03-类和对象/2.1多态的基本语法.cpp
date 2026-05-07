多态
一、
多态是C++面向对象三大特性之一
//多态分为两类
·静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
·动态多态：派生类和虚函数实现运行时多态
//静态多态和多态多态区别：
·静态多态的函数地址早绑定 - 编译阶段确定函数地址
·动态多态的函数地址晚绑定 - 运行阶段确定函数地址

二、代码演示：
//动物类
class Animal
{
public:
	//虚函数
	virtual void Speak()
	{
		cout << "动物在叫" << endl;
	}
};
//猫类
class Cat:public Animal
{
public:
	//重写  函数返回值类型 函数名 参数列表 完全相同
	virtual void Speak()  //这里的virtual可以不写
	{
		cout << "小猫在叫" << endl;
	}
};
//狗类
class Dog :public Animal
{
public:
	void Speak()
	{
		cout << "小狗在叫" << endl;
	}
};
//执行说话的函数

//动态多态满足条件：
//1.有继承关系
//2.子类重写父类的虚函数

//动态多态使用：
//父类的指针或者引用 指向子类对象
void doSpeak(Animal &animal) //Animal &animal=cat;//在C++中允许父子之间的类型转换
{
	animal.Speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
}
int main()
{
	test01();
	return 0;
}