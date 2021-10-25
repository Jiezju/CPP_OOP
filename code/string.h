#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:                                 
   String(const char* cstr=0); 
   
   // Big Three	
   String(const String& str); // 拷贝构造                  
   String& operator=(const String& str); // 拷贝赋值        
   ~String(); // 析构  

   // 支持 cout 的用法：c 的字符串转换	
   char* get_c_str() const { return m_data; }
private:
   char* m_data; // 指针，允许动态分配内存，4个字节大小
};

#include <cstring> // c string 库

inline
String::String(const char* cstr = 0)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1]; // 动态分配内存， 1 表示终止符 '\0'
      strcpy(m_data, cstr);
   }
   else {   // 未指定初值
      m_data = new char[1];
      *m_data = '\0';
   }
}

inline
String::~String()
{
   delete[] m_data;
}

inline
String& String::operator=(const String& str)
{
   // 检查是否 自我赋值	
   if (this == &str)
      return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

inline
String::String(const String& str)
{
   if (m_data)
		delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif
