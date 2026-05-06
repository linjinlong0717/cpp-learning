菱形继承
一、概念：
两个派生类继承同一个基类
又有某个类同时继承这两个派生类
这种继承被称为菱形继承，或者钻石继承
//例：动物类 羊类 驼类 羊驼类

二、代码演示：
//动物类
class Animal
{
public:
	int m_Age;
};
//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字 virtual 变为虚继承
//Animal类称为 虚基类
//羊类
class Sheep :virtual public Animal{};
//驼类
class Tuo :virtual public Animal{};
//羊驼类
class SheepTuo :public Sheep, public Tuo{};

void test01()
{
	SheepTuo st;
	//st.m_Age = 18; 不明确，报错
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承时，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;

	//这份数据我们知道 只有一份就可以，菱形继承导致数据有两份，资源浪费
	//虚继承可以解决菱形继承问题
}
int main()
{
	test01();
	return 0;
}