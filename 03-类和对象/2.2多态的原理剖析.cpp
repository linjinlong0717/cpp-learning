多态的原理剖析
一、代码演示：
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
	//重写                    //当子类重写父类的虚函数
	virtual void Speak()      //子类中的虚函数表 内部 会替换成 子类的虚函数地址
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
void test01()
{
	cout << "size of Animal = " << sizeof(Animal) << endl;   //若Animal类中不加virtual 输出1；加virtual 输出4(本质是一个虚函数指针，指向虚函数表，表内记录虚函数地址)；
	Cat cat;
	Animal& animal = cat;  //利用父类指针 实现多态
	animal.Speak();        //动态多态的函数地址晚绑定 - 运行阶段确定函数地址
}
int main()
{
	test01();
	return 0;
}