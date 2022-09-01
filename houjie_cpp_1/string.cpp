//IDE:VS2019 
#include<cstring>	//防止编译器强制要求使用strcpy_s
#include <iostream>
using namespace std;
class String {
public:
	String(const char* str = "") {	//拷贝构造
		if (str) {
			ptr = new char[strlen(str) + 1];
			strcpy(ptr, str);
		}
		else {
			ptr = new char['\0'];
		}
	}

	String(const String& str) {	//拷贝构造
		ptr = new char[strlen(str.ptr) + 1];
		strcpy(ptr, str.ptr);
	}

	String& operator=(const String& str) {
		if (&str == this) {
			return *this;
		}
		delete[] ptr;
		ptr = new char[strlen(str.ptr) + 1];
		strcpy(ptr, str.ptr);
		return *this;
	}

	char* getStr() const {
		return ptr;
	}

	~String() {	//析构函数
		delete[] ptr;
	}
private:
	char* ptr;
};

ostream& operator << (ostream& os, const String& str)
{
	os << str.getStr();
	return os;
}
int main(void) {
	String s1;	//测试默认构造函数
	String s2 = "shkfjkabc";	//测试拷贝构造
	cout << s1 << endl;
	cout << s2 << endl;
	String s3 = s2;	//测试拷贝赋值
	String s4(s3);	//测试拷贝构造
	String s5("123asdas");	//测试拷贝构造
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	String s6;	//测试连续赋值
	String s7 = s6 = "12312asdvxcv";
	cout << s6 << endl << s7;
}
