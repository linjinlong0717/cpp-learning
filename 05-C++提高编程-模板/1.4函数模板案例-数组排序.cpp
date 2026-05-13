函数模板案例
一、案例描述：
·利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
·排序规则 从大到小，排序算法为 选择排序
·分别利用char数组和int数组进行测试

二、代码演示：
//交换函数模板
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;  //认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值 比 遍历出的数值 要小，说明 j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i元素
			mySwap(arr[max], arr[i]);
		}
	}
}

//提供打印数组模板
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char)-1; //sizeof 会把char数组最后的'\0'算进去
	mySort(charArr, num);
	printArray(charArr, num);
}
void test02()
{
	//测试int数组
	int intArr[] = { 7,5,1,3,9,2,4,6,8};
	int num = sizeof(intArr) / sizeof(int);  //int数组后面不需要-1
	mySort(intArr, num);
	printArray(intArr, num);
}

int main() 
{
	test01();
	test02();
	return 0;
}