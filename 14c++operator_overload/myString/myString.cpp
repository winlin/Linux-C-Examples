#include <iostream>
#include <cstring>
#include <cstdlib>
#include "myString.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

String::String()
{
        length=20;
        count=0;
        ptr=new(nothrow) char[length+1];
        if(!ptr){
                cerr<<"ERROR:Allocate memory failed"<<endl;
                exit(-1);
        }
}
String::String(const char* str)
{
        int n=strlen(str);
        ptr=new(nothrow) char[n+1];
        if(!ptr){
                cerr<<"ERROR:Allocate memory failed"<<endl;
                exit(-1);
        }
        strcpy(ptr,str);
        count=n;
}
String::String(const String& str)
{
        length=str.length;
        count=str.count;
        ptr=new char[length+1];
        if(!ptr){
                cerr<<"ERROR:Allocate memory failed"<<endl;
                exit(-1);
        }
        strcpy(ptr,str.ptr);
}
String::~String()
{
        delete [] ptr;
}
bool String::insert(const char s)
{
        if(count>=length){
                char *tmp=new(nothrow) char[2*length+1];
                if(!tmp){
                        cerr<<"ERROR:Allocate memory failed"<<endl;
                        exit(-1);
                }
                strcpy(tmp,ptr);
        delete [] ptr;
        ptr=tmp;
        length*=2;
        }
        
        ptr[count]=s;
        ++count;
        return 1;
}
String& String::operator=(const String& s)
{
        if(*this==s)
                return *this;
        
        delete [] ptr;
        
        ptr=new char[s.length+1];
        if(!ptr){
                cerr<<"ERROR:Allocate memory failed"<<endl;
                exit(-1);
        }
        strcpy(ptr,s.ptr);
        length=s.length;
        count=s.count;
        return *this;
}
char& String::operator[](int n)
{
        return ptr[n];
}
int String::getLength()
{
        return count;
}
const String& String::operator+=(const String& s)
{
        for(int i=0;i<s.count;++i)
                this->insert(s.ptr[i]);
        return *this;
}
const String operator+(const String& s1,const String& s2)
{
        int sum_len=strlen(s1.ptr)+strlen(s2.ptr);
        char *tmp=new char[sum_len+1];
        if(!tmp){
                cerr<<"ERROR:Allocate memory failed"<<endl;
                exit(-1);   
        }
        strcpy(tmp,s1.ptr);
        strcat(tmp,s2.ptr);
                
        String ss;
        ss.length=sum_len;
        ss.count=sum_len;
        ss.ptr=tmp;
        return ss;
}
ostream& operator<<(ostream& os,const String& s)
{
        for(int i=0;i<s.count;++i)
                os<<s.ptr[i];
        return os;
}
istream& operator>>(istream& is,String& s)
{
        while(is.peek()!='\n'){
                char ch;
                is>>ch;
                s.insert(ch);
        }
        return is;
}
bool operator<(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)<0)
                return 1;
        else
                return 0;
}
bool operator<=(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)<=0)
                return 1;
        else
                return 0;
}
bool operator>(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)>0)
                return 1;
        else
                return 0;
}
bool operator>=(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)>=0)
                return 1;
        else
                return 0;
}
bool operator==(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)==0)
                return 1;
        else
                return 0;
}
bool operator!=(const String& s1,const String& s2)
{
        if(strcmp(s1.ptr,s2.ptr)!=0)
                return 1;
        else
                return 0;
}


