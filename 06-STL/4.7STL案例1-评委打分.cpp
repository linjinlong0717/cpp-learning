案例描述：
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，去平均分

实现步骤：
1.创建五名选手，放到vector中
2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评委打分存到deque容器中
3.sort算法对deque容器中的分数排序，去除最高和最低分
4.deque容器遍历一遍，累加总分
5.获取平均分

代码演示：
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>
#include<string>
//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;  //姓名
	int m_Score;    //平均分
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);

		//将创建的person对象 放入到容器中
		v.push_back(p);
	}
}

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//int score = rand() % 41 + 60; //也可以用 随机数 生成60`100
			int score = 0;
			cin >> score;
			d.push_back(score);
		}

		cout << "选手:" << it->m_Name << "打分：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl; 

		//排序
		sort(d.begin(), d.end());

		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;  //累加每个评委的评分
		}

		int avg = sum / d.size();

		//将平均分 赋值给选手身上
		it->m_Score = avg;
	}
}

void showScore(vector<Person>& p)
{
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 平均分：" << it->m_Score << endl;
	}
}

int main()
{
	//1.创建5名选手
	vector<Person>v;   ///存放选手容器
	createPerson(v);

	//测试
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "分数：" << (*it).m_Score << endl;
	}

	//2.给5名选手打分
	setScore(v);

	//3.显示最后得分
	showScore(v);

	return 0;
}