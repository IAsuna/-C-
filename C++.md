# C++

## PS

```c++
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
//用于对c++输出和c语言的同步，可以降低c++自生的输出语句的时间
```



## 引用

通过取别名的方式来使得参数获得其他名字

```c++
int num = 0;
int& dd = num;
```



## 命名空间

通过namespace进行创建，里面可以留存需要使用的数据，方法，甚至命名空间，只需在使用时通过

using namespace +命名空间名调用即可

命名空间也可以取别名

```c++
namespace SixStarCPP2203Cpp_01_07
{
	int num;
}
namespace A = SixStarCPP2203Cpp_01_07
```



## New与delete

New用于申请内存，申请的内存需要通过指针保存，类似Java的实例化类

```c++
//1申请单个内存
int* p1 = new int;
*p1 = 0;

//2 申请单个内存且初始化
int* p2 = new int (99);
cout<<"*p2 = "<<*p2<< endl;

//3批量申请（连续的内存）
int* p3 = new int [10];
for (size_t i = 0; i< 10; i++)
{
	p3[i] = i;
	cout << "p3["<< i<<"] =" << p3[i] << endl;
}
//delete用于释放内存
delete p1;
delete p2;
delete[] p3;
```

Delete用于释放内存 通过方括号释放一连串内存

## 构造函数

函数默认会有一个构造，名字与类相同，

无法直接调用，只有在实例化类事可以调用一个构造函数

```c++
MyClass obj_0;
MyClass obj_1(1,2);
```

当需要对数据进行初始化时，即原数据被const修饰为常量时，则通过成员初始化列表

```c++
public:
	const int id;
	const int num;
	const int val.
public;
	MyClass(int i, int n) :id(i), num(n), val(0)
	{
		// id = n;
	}
```

 

## 析构函数

在对线生命周期结束后进行清理，系统可以自动调用

函数名与类名相同，但需要添加**~**没有返回值和参数也可以自己调用

和构造函数一样，实例化类的时候回各自调用一次

Ps并非调用析构函数才导致生命周期结束，而是生命周期结束才调用的析构函数，任何函数都有且只有一个析构函数。

```c++
~MyClass()
{

}
```



## 拷贝构造函数

用于复制过程 第一个参数是本类对象的引用，

默认的拷贝构造函数

```c++
MyClass(const Myclas& obj){}
```

同样可以重载

const可有可无，只是为了防止被修改 

调用时机：

1. 使用一个对象去初始化另一个对象
2. 使用一个对象去构造一个对象。
3. 函数的参数是一个类
4. 函数的返回值是一个类

Ps指针不可以通过将一个指针直接付给另一个指针的方式来赋值来直接指向

需要通过，

```c++
for(size _t i = 0; i< 10;i++)
{
	p[i] = obj,p[i];
	*(p+i) = *(obj,p -i)
}
```

来就开辟一块新的内存再将内容复制过去。

 

拷贝分为浅拷贝和深拷贝

浅拷贝：无脑复制（默认方式）

深拷贝：根据自身需求选择复制  



## this指针

是系统自动生成的

不是对像的一部分，作用域是类的内部

类普通函数访问类的成员时，this指针总是指向调用者对象

用法

```c++
publIc:
void setNum(int num)
{
	//num = num;
	this->num = num;
}
int getNum()
```

和java的this类似。不过这里是指针，只能通过箭头进行使用

本质上是this指向了一个类，可以通过*直接获得其内部的类然后使用点方法调用其他成员（拥有指针的一切特性）。

 

## static成员

static只需在声明时在类的内部加，外部初始化无需再加

通过static声明静态成员，

静态数据：生存周期长于任何类，无法在类的内部初始化，可以通过类名直接调用

```c++
//类名直接调用
staic int num;
inat ClassNeme :: num =0;
//调用
ClassName :: num;
```

 静态函数，不属于任何对象，仅属于类 内部不能访问普通成员包括人this指针

```c++
static void testFunc_1();
{
	cout << "ClassName::testFunc_1()"<<endl;
}
```

 

访问方式

```c++
obj_2.testFunc_1();
ClassName* p = &obj_1;
p->testFunc_2();
ClassName::testFunc_1();
ClassName: :testFunc 2();
```

Ps：静态函数无法调用普通变量

（因为静态函数【变量】的生成早于类和对象，会导致静态函数在调用普通成员时普通成员没有生成）【本质是生命周期问题】

单列模式，将所有的构造，拷贝函数设为私有，然后设定一个静态的当前类类型的指针，然后通过一个静态类来访问指针，用new开辟空间，在主函数中通过类指针访问，即可实现单列模式



## const成员

常量数据成员

定义

!

```c++
const int val;
```

必须用成员初始化列表初始化

常量成员函数

定义

```C++
void test_Func_20() const
{
    cout << "test_Func_2()"<< endl;
    cout << "val = "<<val<< endl;
    cout << "nm = "<<num<< endl;

```

内部声明外部定义，const都不可丢掉

```c++
void test_Func_2() const;

void ClassName::test_Func_2() const
{}
```

 

因为const是整个函数的一部分

常量函数不能对当前类内的数据进行修改（但是静态成员可以修改，也可以通过this指针指向）

 

```c++
const ClassName obj_5(3,4);
obj_5.n = 0;
```

常对像，无法修改内部数据，（可修改静态），且不可调用普通成员函数（静态成员函数可以）【静态可以调用的本质原因是，静态成员不属于某个对象，之属于类本身，const修饰后即将这个对象设定为常量，所以对象内部不可修改，同时为了防止通过成员函数间接修改普通成员变量，所以const修饰的常对象不可以调用普通成员函数】

## 友元关系（两者之间的关系）

用于打破封装（但不要过度使用）

Ps（你把对方当做友元，对方不一定认为你是，拥有友元关系即可使用友源单位的东西）

（单方向。不继承。不传递）

友元函数

创建

```c++
class A
{
	int num;
	friend void test_Func_1(A obj);

};
void test_Func_1(A obj)
{
	obj.num = 0;
}
```

函数text_Func_1为了使用A类的num，从而A类把函数视为友源，所以可以正常调用num

友元类（可以创建友元对象）

```c++
class A
{
	int num;
	friend class B;

};

class B
{
public:
	void testFunc(A obj)
	{
		obj.num
	}

};
```

 

## 继承与派生

语法

```c++
//单继承
class 父类名
{
}；
class 子类名 : 继承权限 父类名
{
}；

//多继承
class 父类名
{
}；
class 父类名
{
}；
class 子类名 : 继承权限 父类名，继承权限 父类名
{
}；

```

两个继承中间用逗号隔开

继承权限

公有继承 public

私有继承 private

保护继承 protected

Ps继承是子类继承父类全部的成员，

|           | 继承权限 | 公有继承 public | 私有继承 private | 保护继承 protected |
| --------- | -------- | --------------- | ---------------- | ------------------ |
| 声明权限  |          |                 |                  |                    |
| public    |          | public          | private          | protected          |
| private   |          | 无法访问        | 无法访问         | 无法访问           |
| protected |          | protected       | private          | protected          |

## 父与子

当子类继承来自父类的同名变量时，会自动用自己的同名变量覆盖，当需要使用是，可以通过类名加作用域符来调用

```c++
obj_son.Father :: num
```

若继承自父类的变量有相同的父类变量，则无法直接调用，需要通过类名加作用域符来指明调用的是那个变量

子类的对象可以当做父类对象，反之不行。

子类对象可以给父类对象赋值，反之不行

父类指针可以指向子类对象，但反之不行、

本质是因为子类比父类更多，子类给父类赋值可以全部赋值，而反过来无法全部赋值，在指针上，因为子类内容过多，指正读取时会读取的更多，当子类指针读取父类是会导致指针异常读取。

```c++
#include <iostream>

using namespace std;

class Father
{
public:
	Father();
	~Father();

private:

};

class Son :public Father
{
public:
	Son();
	~Son();

private:

};

int main()
{
	Father obj_fat;
	Son obj_son;
	
	obj_fat = obj_son;
	//obj_son = obj_fat;不行
	Father* P_fat;
	Son* p_son;

	P_fat = &obj_son;

	//p_son = &obj_fat;不行 
	
	return 0;
}
/*子类构造析构*/
Son::Son()
{
}

Son::~Son()
{
}
/*父类构造析构*/
Father::Father()
{
}

Father::~Father()
{
}
```

派生类构造与析构函数的顺序
在子类函数中将数据传给父类函数，通过成员初始化列表的形式调用父类带参构造函数，父类带参构造函数也必须使用成员初始化列表

```c++
Son::Son(int n):Father(n)
{
	val = 0;
	cout << "我是子类的构造" << endl;
}
```

## 菱形继承

### 虚继承 	

关键字：virtual 

virtual 继承方式  类名  写在父类的继承上

占用4字节	

### 联编

动态联编 条件 ：1动态联编的行为定义为类的虚函数 2要有继承关系

静态联编

## 多态

## 虚函数

  在声明函数是加上virtual关键字 则声明了虚函数 virtual 返回值类型 函数名 （参数表）

虚函数表：存储虚函数

当虚函数在子类存在同名函数是，不会被隐藏，而是直接将父类函数重写

继承不会继承父类的虚函数表

虚函数可以帮助实现多态
当使用父类类型指针指向子类对象或者指向子类类型的内存空间时，调用被子类复写的虚函数不会访问父类的同名虚函数，当释放内存时，如果父类不是虚析构函数则会释放父类，若是，则会释放指针指向类型的析构函数

## 纯虚函数

特殊的虚函数，适用虚函数的全部性质，只是没有函数体

```c++
///纯虚函数的声明
virtual void text () = 0;
//virtual[虚函数声明关键字] 返回值类型 函数明 （） = 0； 
/*纯虚函数的函数体的实现放在子类中*/
//析构函数声明纯虚函数是依然要实现
```

## 抽象类

有一个或一个以上的纯虚函数则称为抽象类

抽象类不能实例化对象，但可以定义指针

如果子类继承抽象类未完全实例化所有纯虚函数，则子类依旧是抽象类，拥有抽象类的所有特征

## final关键字

也可以说是权限掠夺者

修饰函数则禁止重写

修饰类则禁止继承

```c++
//函数使用方法 在函数声明时使用
void test() final;
///类
class 类名 final
{}	
//当final修饰纯虚函数时将永远无法重写，会导致继承后的类都是抽象类
```

## 运算符重载

### 1重载的概念

```c++
//定义方式
//返回值类型 函数名（）{}
//函数名：operator运算符名称
#include<iostream>
using namespace std;

class MyClass
{

public:
	double m_real;
	double m_imag;
public:
	
	MyClass(double m_real = 0,double m_imag = 0);
	~MyClass();
	void shou();
	//MyClass operator+(const MyClass obj_c);
	
	MyClass operator+(const MyClass& obj_c) const
    {
		return  MyClass(this->m_real + obj_c.m_real, this->m_imag + obj_c.m_imag);
	}	
};

MyClass::MyClass(double m_real, double m_imag):m_real(m_real),m_imag(m_imag)
{
}


MyClass::~MyClass()
{
}
 /*MyClass MyClass:: operator+(const MyClass obj_c)
{
	MyClass obj;
	obj.m_real = this->m_real + obj_c.m_real;
	obj.m_imag = this->m_imag + obj_c.m_imag;
	return obj;
}*/
void MyClass::shou() 
{
	cout << "（" << m_real << "+" << m_imag << "i)" << endl;
}
int main()
{
	MyClass obj_1(1,2);
	MyClass obj_2(3, 2);
	MyClass obj_3;
	obj_3 = obj_1 + obj_2;
	obj_3.shou();
}
//加法重载
```

类的四个默认函数

构造，析构，拷贝，赋值

当用一个类给另一个类初始化的时候是调用拷贝

其他情况都是赋值函数

### 2重载规则和规范

并不是所有的运算符都可以重载，

可重载的运算符

| 双目算数运算符 |              +、-、*、/、%               |
| :------------: | :--------------------------------------: |
|   关系运算符   |          ==、\|=、<、>、<=、>=           |
|   逻辑运算符   |               \|\| 、&& ！               |
|   单目运算符   |    +(正)、-(负)、*(指针)、&(取地址)、    |
|    自增自减    |                  ++、--                  |
|    位运算符    |           \|、&、~、^、<<、>>            |
|   赋值运算符   |   =、+=、*=、%=、&=、\|=、^=、<<=、>>=   |
| 空间申请与释放 |       new、delete、new[]、delete[]       |
|   其他运算符   | （）函数调用、->成员访问、，逗号、[]下标 |

不可重载

.点、

.* ->成员指针访问运算符 

：：域运算符

 sizeof长度运算符

？：条件运算符

#预处理运算符

ps:重载不会改变原符号的优先级，结核性和运算符用法，运算符重载不能有默认的参数、

运算符重载可以作为类的成员函数也可以作为全局函数，在作为类的成员函数时，会被this指针占据一个参数位，全局函数则不会占用

箭头，->下标[  ]赋值=函数调用()这些运算符只能以成员函数的方式调用

### 输入输出运算符的重载

1建议作为友元函数重载

2、istream输入

3、ostream输出

```c++
#include<iostream>

using namespace std;

class MyClass
{
public:
	
	MyClass(double i = 0.0,double r = 0.0);
	friend istream& operator>>(istream& in, MyClass& obj);
	friend ostream& operator<<(ostream& out, MyClass& obj);
private:
	double m_i;
	double m_r;
};

istream& operator>>(istream& in, MyClass& obj)
{
	in >> obj.m_i>>obj.m_r;
	return in;
}

ostream& operator<<(ostream& out, MyClass& obj)
{
	out << "(" << obj.m_i <<"+" << obj.m_r<<"i)";
	return out;
}
MyClass::MyClass(double i,double r):m_i(i),m_r(r)
{
}

int main()
{
	MyClass m;
	cin >> m;
	cout << m <<endl;
}

```

## 模板类

```c++
template <typename Type>
Type add(Type a,Type b)
{
	return 0;    
}

//调用方式
add<数据类型，数据类型>(a,b);

```

## 模板的重载

```c++
class MyData
{
public :
	MyData(int n = 0):num(n){}
	int  num;
	int val;
}
template<typname T>
bool func (T& a,T& b)
{
	if(a == b)
	{
	return true;
	}
	return false;
}

template<> bool func<MyData>(MyData &a,MyData& b)
{
	if(a,num == b.num)
	{
		return 0;
	}
	return false;
}
```

## 类模板

### 1类模板是什么

模板类定义时并非是完整类，需要传入数据类型才行

类模板参数列表可以制定类型，函数模板在使用时会自动使用匹配的通常函数，除非模板函数更合适

类模板不能和函数模板一样使用自动推导

模板可以自定义特化

函数模板可以发生重载

```c++
template <类型参数列表>
class 模板类名
{
	成员;
};


类型参数列表：<class T1,...>
成员： T1 name ...
    
```



 类模板的和子类模板的定义和实现必须在一个文件里面。	

```c++
模板类友元的声明
friend void show_2 <> ();
//注意类名后的<>用于说明的模板类的友元
//实现函数的时候不需要<>
//不建议在模板类里使用友元，使用时应当在类内实现，当在类外实现是，类内声明友元需要<>标识，同时在文件开头声明函数和类
```

## C++异常处理

```c++
throw  抛出异常
try	尝试异常代码	
catch	解决异常

try
{
    直接或者间接有throw
}
catch(接受异常)
{
    处理
}
```

## 文件流

```c++
#include<fstream>
//
fstream obj;
//打开文件
obj.poen();
//关闭文件
obj.close;
//检测文件时是否打开
obj.is_open();
//是否到达文件尾
obj.eof();
```

```c++
//模式标志
//追加模式
ios:app  
//打开后定位到尾部
ios::ate
//打开文件用于读取 
ios::in
//打开文件用于写入
ios::out
//如果文件已经存在，其内容将在打开文件之前被阶段，即吧文件长度设为0；
ios::trunc
```

```c++
//写入一个字符
obj.open("文件路径",ios::out);
obj.put('需要写入的字符');
char ch = '字符';
obj,put(ch);
obj.close();
```

## c++11

```c++
//c++风格
int a(5);
auto b(5);
int* p(nullprt);
//根据a的类型定义一个喝a类型一致的变量b；
decltype(a)b;
//给a去别名m
decltype((a))m = a;	
```

```c++
//新的for循环
string str("abcderg");
//遍历容器使用;
//序列for循环/范围for
for(auto ch : str)
{
	cout<<ch<<" ";    
}
```

```c++
//类型去别名
//c写法
typedef inta INT;
typedef void(*pFun);
//c++写法
using Int = int;
using PFUN = void(*)();
```

```c++
default 在类中的用法
    class CA
    {
		public:
        CA();
    }
//声明默认构造函数
CA::CA() = default;
```

```c++
//final
用在类上让类不能继承，用在函数上让函数无法重写
```

## STL

### 1.STL的基本概念

面向对象，封装继承多态的本质是提高代码复用

STL（Standard Template Library）标准模版库

广义上分为：**容器**，**算法**和**迭代器**

**容器**和**算法**之间通过**迭代器**进行无缝链接

STL几乎全部采用了模版类或者模版函数

### 2.STL的六大组件

- 容器：各种数据结构，用于存放数据
- 算法：各种常用算法，
- 迭代器：扮演了容器和算法之间的胶合剂
- 仿函数：行为类似函数，可作为算法的某种策略
- 适配器：一种用来修饰容器或者仿函数或迭代器的接口的东西
- 空间配置器：负责空间的配置和管理

### 2.1容器，算法，迭代器

容器

- 序列式容器：强调值的排序，每个元素有固定的位置
- 关联式容器：二叉树结构，各元素之间没有严格上的物理上的顺序结构

算法（Algorithms）

- 质变算法：会更改区间内的元素
- 非质变算法：不会改变区间内的元素

迭代器：提供一种方法，使算法可以去访问容器中的元素。

**每个容器都有自己的迭代器**

迭代器种类，输入，输出，前向，双向和随机访问

其中最多的为双向和随机访问

### 3.vector（数组）

容器：vector

算法for_each

迭代器：vector<int>::iterator

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void MyPrint(int val)
{
	cout << val << endl;
}

void test()
{
	//创建了一个int类型的容器	
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//迭代器遍历
	vector<int>::iterator itBegin = v.begin(); //起始迭代器，指向容器中的第一个元素
	vector<int>::iterator itEnd = v.end();   //结束迭代器，指向容器中最后一个元素的下一个位置

	//第一种遍历
	while ( itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//第二种方式
	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *itBegin << endl;
	}



	//第三种利用stl中的遍历算法
	for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
	test();
	return 0;
}
```

### 3.1vector存放自定义数据类型

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



class MyClass
{
public:

	string name;
	int age;


	MyClass(string,int);
	~MyClass();

private:

};

MyClass::MyClass(string name,int age)
{
	this->name = name;
	this->age = age;
}

MyClass::~MyClass()
{
}

void test()
{
	vector<MyClass> myclass;

	MyClass my1("王强1",1);
	MyClass my2("王强2",2);
	MyClass my3("王强3",3);
	MyClass my4("王强4",4);
	MyClass my5("王强5",5);

	myclass.push_back(my1);
	myclass.push_back(my2);
	myclass.push_back(my3);
	myclass.push_back(my4);
	myclass.push_back(my5);

	for (vector<MyClass> ::iterator it = myclass.begin(); it != myclass.end(); it++)
		cout << "姓名:" << (*it).name << "年龄" << (*it).age << endl;
}

int main()
{
	test();
	return 0;
}
```



### 3.2容器嵌套

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;




void test()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}
		cout << endl;
	}
}

int main()
{
	test();
	return 0;
}
```

## 4.string 基本概念

string的本质是一个类

char*是一个指针

string是一个类，类内封装了char**，管理这个字符串，是一个char*形的容器

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;




void test()
{
	string str;
	str = "李涛";
	str += "爱玩游戏";
	string str2;

	//函数赋值
	str2.assign("LOL");
	//函数拼接
	str.append(str2);
	cout << str << endl;
    
    string str6 = "王强";
string str7 = "爱玩原神";
str6.append(str7, 0, 4);
cout << str6 << endl;
}

int main()
{
	test();
	return 0;
}
```

### 4.1string的查找

```c++
void test()
{
	string str = "acdbadcbac";
	string str_User;
	/*cin >> str_User;
	int pos = str.find(str_User);			//find从左往右查找 rfind从右往左查找
	if (pos == -1)
	{
		cout << "字符段不存在" << endl; 
	}

	int pos2 = str.rfind(str_User);
	cout << pos2 << endl;*/

	str.replace(0, 3, "aaaaa"); //替换从某个位置的，几个字符，为该字符。且字符替换无视原字符串长短
	cout << str << endl;

}

```

### 4.2字符串的比较

```c++
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1 = "王强";
	string str2 = "李涛";

	if (str1.compare(str2) == 0)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}
```

主要用于判断相等，单纯的大小比较毫无意义

### 4.4string的存取

```c++
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1 = "abcdefghijklmn";
	for (size_t i = 0; i < str1.length(); i++)
	{
		cout << str1[i];
	}
	cout << endl;
	for (size_t i = 0; i < str1.length(); i++)
	{
		cout << str1.at(i);
	}
	cout << endl;
}
```

### 4.5string的插入和删除

```c++
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1 = "abc";
	
	str1.insert(1, "王强"); //在指定位置前插入

	str1.insert(0,3, 'e'); //在指定位置前插入，多少个，某字符
	cout << str1 << endl;

	str1.erase(0,4);		//从指定位置起，删除n个
	cout << str1 << endl;
	cout << endl;
}
```

### 4.6 string子串

```c++
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str1 = "abcdefg";
	string st = str1.substr(2, 3);
	
	cout << st << endl;
	cout << endl;
}
```

## 5，vector

和数组很相似，被称为**单端数组**

可以动态扩展

动态扩展：并非在原空间之后进行扩展，而是开辟一个更大的新空间将源数据拷贝过去，再释放原空间

```c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printfVe(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void fg() 
{
	cout << "-------------------------------" << endl;
}

int main()
{
	vector<int> v1;
	for (int i = 0; i <= 10; i++)
	{
		v1.push_back(i);
	}

	printfVe(v1);
	fg();

	vector<int> v2(v1.begin() + 2, v1.end());
	printfVe(v2);
	fg();

	vector<int> v3(10, 100);
	printfVe(v3);
	fg();

	vector<int> v4(v3);
	printfVe(v4);
	fg();
}
```

赋值

```c++

	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printfVe(v1);
	fg();

	vector<int> v2 = v1;
	printfVe(v2);
	fg();

	vector<int> v3;
	v3.assign(v1.begin() + 2, v1.end());
	printfVe(v3);
	fg();
```

vector的容量和大小

```c++
vector<int> v1;
for (int i = 0; i < 10; i++)
{
	v1.push_back(i);
}

if (v1.empty())
	cout << "容器为空" << endl;
else
	cout << "容器不为空--" << "容器大小为" << v1.capacity() << "--容器长度为：" << v1.size()<<endl;
printfVe(v1);
fg();
v1.resize(20);  //重新分配容器大小
cout << v1.capacity()<< endl;
printfVe(v1);
fg();
```

vector的插入和删除

```c++
vector<int> v1;

for (int i = 0; i < 10; i++)
{
	v1.push_back(i);
}

printfVe(v1);
fg();

//尾部插入
v1.push_back(15);
printfVe(v1);
fg();

//尾部删除
v1.pop_back();
v1.pop_back();
printfVe(v1);
fg();

//迭代器指向插入
v1.insert(v1.begin()+3, 99);
printfVe(v1);
fg();
//重载版本
v1.insert(v1.begin(), 2, 100);
printfVe(v1);
fg();

//删除
v1.erase(v1.begin());
printfVe(v1);
fg();

//删除重载
v1.erase(v1.begin() + 2, v1.end() - 2);
printfVe(v1);
fg();

//清空
v1.clear();
printfVe(v1);
fg();
```

vector的查找

```c++
vector<int> v1;

for (int i = 0; i < 10; i++)
{
	v1.push_back(i);
}

printfVe(v1);
fg();
//at取固定位置数
print(v1.at(2));
//【】取固定位置数
print(v1[2]);
//取首
print(v1.front());
//取尾
print(v1.back());

```

互换容器

```c++
v1.swap(v2);//交换两个容器的大小和内容

//容器收缩

vector<int> (v).swap(v);
```

vector 的预留空间

```c++
reserve（int val）//预留val个大小的空间，且不会初始化也无法访问
```

## 6.deque容器

双端数组，可以头插

工作原理：内部有一个中控器，维护每段缓冲区内的数据，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得在使用deque时像一片连续的空间

因此访问数据的速度会没有vector快

```c++
#include<iostream>
#include<deque>
#include<string>
#include<iomanip>

using namespace std;

void printDeq(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	deque<int> de;
	for (int i = 0; i < 10; i++)
	{
		de.push_front(i);
	}
	
	printDeq(de);

	deque<int>de1(de.begin(), de.end());
	printDeq(de1);

	deque<int>de2(10, 100);
	printDeq(de2);

	deque<int>de3(de2);
	printDeq(de3);

}
```

赋值和

vector一样

比大小

```c++
#include<iostream>
#include<deque>
#include<string>
#include<iomanip>

using namespace std;

void printDeq(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void text1()
{
	deque<int> de;
	for (int i = 0; i < 10; i++)
	{
		de.push_front(i);
	}

	if (de.empty())
		cout << "空" << endl;
	else
	{
		cout << "不为空" <<de.size()<< endl;
		printDeq(de);
	}

	de.resize(15,9);
	printDeq(de);

	de.resize(3);
	printDeq(de);

}
int main()
{
	text1();
}
	
```

插入和删除

```c++
#include<iostream>
#include<deque>
#include<string>
#include<iomanip>

using namespace std;

void printDeq(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
}

void text1()
{
	deque<int> de;
	for (int i = 0; i < 10; i++)
	{
		de.push_front(i);
	}

	de.push_back(100);
	de.push_front(100);
	printDeq(de);
	de.pop_front();
	de.pop_back();
	printDeq(de);

	de.insert(de.begin()+3, 1000);
	de.insert(de.begin() + 5, 3, 10000);
	printDeq(de);

	de.erase(de.begin() + 2, de.end() - 3);
	printDeq(de);
	
	de.clear();
	if (de.empty())
		cout << "清空完毕" << endl;
	else
		cout << "删除失败" << endl;


	

}
int main()
{
	text1();
}
	
```

存取

```c++
at()
[]
front()//返回首元素
back()//返回尾元素
```

排序

```c++
#include<iostream>
#include<deque>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;

void printDeq(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
}

void text1()
{
	deque<int> de;
	for (int i = 0; i < 10; i++)
	{
		de.push_front(i);
	}
	de.push_back(13);
	de.push_back(100);
	de.push_back(21);
	de.push_front(11);
	printDeq(de);
	sort(de.begin(), de.end()); //默认升序
	printDeq(de);


	

}
int main()
{
	text1();
}
	
```

### 6.1打分系统

```c++
#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<iomanip>
#include<ctime>
#include<algorithm>

using namespace std;


class Person
{ 
public:
	string m_Name;
	int m_Score;
	Person(string,int);

private:

};

Person::Person(string name,int score)
{
	this->m_Name = name;
	this->m_Score = score;
}

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int sc = 0;

		Person p(name, sc);
		v.push_back(p);

	}
}

void setSC(vector<Person>& v)
{
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int sc = rand() % 41 + 60;
			d.push_back(sc);
		}


		sort(d.begin(), d.end());
		
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int> ::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		int avg = sum / d.size();

		i->m_Score = avg;
	}
}

void shouSc(vector<Person>& v)
{
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "选手" << i->m_Name << "平均分" << i->m_Score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建选手
	vector<Person> v;
	createPerson(v);
	//选手打分
	setSC(v);
	//显示得分
	shouSc(v);
	system("pause");
	return 0;
}
	
```



## 7.stack栈容器，

先进后出，进出口为栈顶，反之为栈底

栈不允许遍历，因为在访问后面元素使需要拿出前面的元素，



```c++
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		cout << "栈顶元素：" << s.top()<< endl;
		s.pop();
	}

	cout << "栈的长度为：" << s.size() << endl;
	return 0;
}
```

## 8.queue容器

先进先出，类似队列，先进先出，队尾进，队头出。

只有队头和队尾可以被外界访问，因此也不允许遍历

```c++
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "队的最后一个元素是：" << q.back() << "  队的第一个元素是：" << q.front() << endl;

	while (!q.empty())
	{
		cout << "当前的队首元素为：" << q.front() << endl;
		q.pop();
	}

	cout << "队的长度：" << q.size();
}
```

## 9.List链表容器

- 优点：可以对任意的位置进行快速的添加或者删除元素
- 缺点：遍历速度慢占用空间比数组大

### 9.1List构造函数

与其他相同

### 9.2赋值

```
L3.assugn(begin(),end());
L1.swqp(L2);
//交换两个List容器
```

### 9.3反转和排序

```c++
reverse()//反转
L1.sort()
//不支持随机访问的容器不能使用普通的sort，必须要容容器自带的sort算法
//默认从小到大
//降序则需要自己提供给sort算法一个仿函数或者是一个判断函数
bool mv(int a, int b)
{
	return a > b;
}
int main()
{
	list<int> L;
	L.push_back(30);
	L.push_back(20);
	L.push_back(40);
	L.push_back(10);

	L.sort(mv);

	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << endl;
	}
}
```

## 10自定义排序规则

```c++
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class Person
{
public:
	Person(string, int, double);

	string name;
	int age;
	double hight;

};

Person::Person(string name,int age,double hight)
{
	this->name = name;
	this->age = age;
	this->hight = hight;
}



void Print(const list<Person> L)
{
	for ( list<Person>:: const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名:" << it->name << " 年龄:" << it->age << " 身高:" << it->hight << endl;
	}
}

bool mv(Person &a,Person& b)
{
	if (a.age == b.age)
	{
		return a.hight < b.hight;
	}
	else
	{
		return a.age < b.age;
	}
}

int main()
{
	list<Person> L;
	Person p1("刘备",35,175);
	Person p2("曹操",45,180);
	Person p3("孙权",40,170);
	Person p4("赵云",25,190);
	Person p5("张飞",35,160);
	Person p6("关羽",35,200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	Print(L);
	cout << "--------------排序后-------------" << endl;
	L.sort(mv);
	Print(L);
}
```

## 11set/multiset容器

特点：所有元素在插入时会自动排序；是一个关联性容器，底层逻辑为二叉树

区别

- set内不允许有完全相同的元素
- multiset中允许有完全相同的数据

创建方式相同，但set中只有insert这一种插入方式

### 11.1set的查找和统计

```c++
s.find(key);//若找到则返回元素位置迭代器，找不到则返回尾指针。
s.count(key)//遍历个数；

#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
using namespace std;



int main()
{
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	set<int>::iterator pow = s.find(30);

	if (pow != s.end())
		cout << "找到" << *pow << endl;
	else
		cout << "未找到" << endl;

	int num = s.count(30);
	cout << num << endl;
}
```

```c++
//查询插入是否成功

int main()
{
	set<int> s;
	pair<set<int>::iterator,bool> ret = s.insert(10);
	if (ret.second)
		cout << "成功" << endl;
	else
		cout << "失败" << endl;
	ret = s.insert(10);
	if (ret.second)
		cout << "成功" << endl;
	else
		cout << "失败" << endl;
```

### 11.2pair的使用

pair  对组，成对出现的一组数据，可以利用对组来返回一组数据

```c++
int main()
{
	pair<string, int>p("理塘", 10);
	cout << "地点：" << p.first << "速度" << p.second << endl;

	pair<int, int>p2 = make_pair(100, 60);
	cout << "第一科：" << p.first << "第二课" << p.second << endl;
}
```

### 11.3set的容器排序改变

```c++
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
using namespace std;

void prints(const set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
}

class MyClass
{
public:
	bool  operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};


int main()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);

	prints(s1);

	set<int,MyClass> s2;

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);

	for (set<int,MyClass>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << endl;
	}
}
```

## 12.map容器

高性能高效率

map中的元素都是pair 第一个为key值，第二个为value值，关联容器，二叉树实现map不允许重发但multi可以有重复的key值，value两者无要求/默认按key排序

```
map<int,int> m;
m.insert(pair<int,int>(1,10));//m.insert({1,10});
```



## 13.函数对象

### 13.1函数对象的概念-仿函数

重载函数调用操作符的类 本质是类，并不是函数

- 可以像普通函数一样调用
- 超出普通函数概念，可以有自己的状态
- 可以作为参数传递

### 13.2谓词

返回bool类型变量的函数叫做谓词

### 13.3内建函数

```c++
#include<functional>
```

- 算术仿函数
  - 四则运算，取反为一元运算，其他的为二元
- 关系
- 逻辑

## STL常用算法

算法主要有<algorithm><functional><numeric>组成

其中第一个是STL最大的算法头文件，包含比较，交换，查找，遍历，复制，修改

第三个体积很小，只包括在序列上面进行的简单运算，

第二个是包括了一些模板类，用于声明函数对象

### 1.1for_each容器遍历

```c++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print1(int val)
{
    cout<<val<<endl;
}

int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    
    for_each(v.begin(),v.end(),print1);
}

```

### 1.2transform搬运容器

```c++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print1(int val)
{
    cout<<val<<endl;
}

class Transform
{
    public:
    	int operator()(int v)
        {
            return v;
        }
}

int main()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    
    vector<int>v2;
    
    v2.resize(v.size);//目标容器必须提前开辟空间
    
   transform(v.begin(),v.end(),v2.begin(),Transform());
   for_each（v2.begin(),v2.end(),print1）;
}

```

### 1.3查找find

```c++
find//查找
find_if//按条件查找
adjacent_find//查找相邻重复元素
binary_search//二分查找 无序序列不可用，返回值为真或假
count//统计元素个数
count_if//按条件统计元素个数
```

### 1.4排序算法

```c++
sort//排序
random_shuffle//洗牌
merge//容器元素合并，并存储到其他容器
reverse//反转
```

### 1.5常用拷贝和替换算法

```c++
copy//容器内指定元素拷贝到另一个容器
replace//将容器内指定范围的旧元素修改为新元素
replace_if//容器内指定范围满足条件的元素替换为新元素
swap//互换两个容器的元素
```

### 1.6常用算术生成算法

头文件#include<numeric>

```c++
accumulate//计算容器元素总和
fill//向容器中添加容器
```

### 1.7常用集合算法

```c++
set_intersection//求两个容器的交集
set_union//求两个容器的并集  需要是有序集合
set_difference//求两个容器的差集
```



# C++新特性

## 1.lambda表达式	

定义

```c++
/*[捕获列表](可选参数列表) 可选限定符 可选异常说明符->ret{函数主体}*/
捕获列表：可以调用当前函数内所需要的变量，用逗号分隔 // 作用域：定义lambda的函数体和全局变量 捕获方式分为值捕获和引用捕获，注意，不可以捕获局部变量
    其中[=]为捕获所有可以捕获的值 包括this [&]则是对所有可以捕获的值进行引用捕获，[this]是捕获this指针
可选参数列表；可以选择的参数，语法与普通函数一样
可选限定符：可以在函数内改变按值捕获的变量或者调用非const的成员函数
可选异常说明符：指明是否会抛出异常
ret：可选返回值类型
//无状态lambda转换
    隐式指针转换为函数指针
    void f(void (*)()){};
//示例
int x=5;
auto f = [x](int y)->int{return x*y};
f(8);


//广义捕获
int x  = 1;
auto f = [r = x+1]{return r;};
//泛型捕获 通过auto完成
auto f = [auto x]{return x;};

//[*this]
将this做拷贝引用
//模版
    auto f = []<typename T>(vector<t> vector){};
//无状态 lambda可构造和可赋值
```

