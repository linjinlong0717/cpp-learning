一、成员属性设置为私有
1.优点1:将所有成员属性设置为私有，可以自己控制读写权限
  优点2 : 对于写权限，我们可以检测数据的有效性
	//优点2：可以在写的成员函数里面，利用if来检测数据的有效性(例如：年龄在0-100之间，否则return;)
2.代码演示：
class Person
{
public :
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}
	//获取年龄
	int getAge()
	{
		return m_Age;
	}
	//设置偶像
	void setIdol(string idol)
	{
		m_Idol = idol;
	}
private:
	string m_Name; //姓名 可读可写
	int m_Age=18;  //年龄 只读
	string m_Idol; //偶像 只写
};
int main()
{
	Person p;
	p.setName("张三");  //姓名设置
	cout << "姓名：" << p.getName() << endl; //获取姓名

	cout << "年龄： " << p.getAge() << endl;  //由于年龄只有读的操作，所以不能赋值
	
	p.setIdol("小明");//只写,读不到
	system("pause");
	return 0;
}