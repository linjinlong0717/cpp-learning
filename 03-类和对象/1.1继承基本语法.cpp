//继承的好处：可以减少重复的代码
一、基础语法：
class A :public B
{

};
//A类称为子类 或 派生类
B类称为父类 或 基类

派生类中的成员，包含两大部分：
一类是从基类继承过来的，一类是自己增加的成员
从基类继承过来的表现其共性，而新增的成员体现了其个性

二、代码演示：
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
};
//C++页面
class CPP : public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};
void test01()
{
	cout << "C++下载视频页面如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
}
int main()
{
	test01();
	return 0;
}