二、友元类
//代码演示：
class Building;
class GoodGuy
{
public:
	GoodGuy();
	void visit();//参观函数 访问Building中的属性
private:
	Building* building;
};
class Building
{
	//GoodGuy类是本类的好朋友，可以访问本类中私有成员
  friend class GoodGuy;
public:
	Building();
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom; //卧室
};
//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGuy::GoodGuy()
{
	//创建建筑物对象
	building = new Building;
}
void GoodGuy::visit()
{ 
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友正在访问：" << building->m_BedRoom << endl;
}
void test01()
{
	GoodGuy gg;
	gg.visit();
}
int main()
{
	test01();
	system("pause");
	return 0;
}