引用
一、作用：给 变量 起别名

二、语法：数据类型& 别名 = 原名;

三、代码演示：
int a = 10;
int& b = a;
cout << "a = " << a << endl;  
cout << "b = " << b << endl;
//输出的a和b都为10
b = 100;
cout << "a = " << a << endl;
cout << "b = " << b << endl;
//输出的a和b都为100

四、引用的注意事项
·引用必须初始化
eg : int& b; //错误，必须要初始化
int& b = a;

·引用在初始化后，不可以改变
int a = 10;
int& b = a;
int c = 20;
b = c;  //赋值操作，而不是更改引用
cout << "a = " << a << endl;
cout << "b = " << b << endl;
cout << "c = " << c << endl;
输出a、b和c都为20