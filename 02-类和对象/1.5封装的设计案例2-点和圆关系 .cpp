练习案例2：点和圆的关系
一、设计一个圆形类(Circle),和一个点类(Point),计算点和圆的关系
//核心思路：r的平方和点到圆心距离的平方的大小比较

二、代码演示：
#include<iostream>
using namespace std;
class Point
{
private:
	int m_x;
	int m_y;
public:
	void setx(int x)
	{
		m_x = x;
	}
	int getx()
	{
		return m_x;
	}
	void sety(int y)
	{
		m_y = y;
	}
	int gety()
	{
		return m_y;
	}
};
class Circle
{
private:
	Point m_Center;  //在类中可以让另一个类，作为本来中的成员
	int m_R;
public:
	void setr(int r)
	{
		m_R = r;
	}
	int getr()
	{
		return m_R;
	}
	void setCenter(Point p)
	{
		m_Center = p;
	}
	Point getCenter()
	{
		return m_Center;
	}
};
void isinCircle(Point& p, Circle& c)
{
	int d = (p.getx() - c.getCenter().getx()) * (p.getx() - c.getCenter().getx()) + (p.gety() - c.getCenter().gety()) * (p.gety() - c.getCenter().gety());
	int r = c.getr();
	if (d > r * r)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		if (d < r * r)
		{
			cout << "点在圆内" << endl;
		}
		else
		{
			cout << "点在圆上" << endl;
		}
	}
}
int main()
{
	//圆类
	Circle c;
	c.setr(10);

	Point center;
	center.setx(10);
	center.sety(0);

	c.setCenter(center);
	//点类
	Point p;
	p.setx(10);
	p.sety(9);
	isinCircle(p, c);
	system("pause");
	return 0;
}

//进一步优化(分文件编写)：
//创建的.h结尾头文件中放函数声明和变量声明
//创建的.cpp结尾源文件中放函数实现

以案例为例：

创建point.h头文件
#pragma once    //防止头文件重复包含
#include<iostream>
using namespace std;
//点类
class Point
{
public:     
	void setX(int x); //设置x  //注意后面要加上分号
	int getX();       //获取x
	void setY(int y); //设置y
	int gety();       //获取y
private:
	int m_X;
	int m_Y;
};

创建point.cpp源文件
#include "point.h"
//设置x
void Point::setX(int x)   //注意加上作用域(这里是Point::)
{
	m_X = x;
}
//获取x
int Point::getX()
{
	return m_X;
}
//设置y
void Point::setY(int y)   
{
	m_Y = y;
}
int Point::getY()
{
	return m_Y;
}

//圆类也是同理。
最后只要在主调main函数上方加上
#include "point.h"
#include "circle.h"
这两个头文件即可