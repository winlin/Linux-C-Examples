#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;

class String{
private:
        char *ptr;
        int length;
        int count; 
public:
        String();
        String(const char* str);
        String(const String& str);
        ~String();
        
        bool insert(const char s);
        
        char& operator[](int n);
        int getLength();
        
        String& operator=(const String& s);
        const String& operator+=(const String& s);
        friend const String operator+(const String& s1,const String& s2);
        
        friend ostream& operator<<(ostream& os,const String& s);
        friend istream& operator>>(istream& is,String& s);
        
        friend bool operator<(const String& s1,const String& s2 );
        friend bool operator<=(const String& s1,const String& s2 );
        friend bool operator>(const String& s1,const String& s2 );
        friend bool operator>=(const String& s1,const String& s2 );
        friend bool operator==(const String& s1,const String& s2 );
        friend bool operator!=(const String& s1,const String& s2 );
};

#endif
