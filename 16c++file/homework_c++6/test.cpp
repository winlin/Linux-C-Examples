/*虽然子类中包含了所有父类的成员，但是并不意味着它们就是子类的成员，
 *必须通过父类的构造函数初始化，不能当作自己的成员来进行初始化
 *
 *默认情况下，一个类中含有虚函数的话，应当把其析构函数同样也声明为virtual
 *但是，对于虚基类，我们可以不用为她声明虚析构函数，但是对应的子类必须要写
 *
 *出于简单的目的和安全，自己应该把虚基类的析构函数也声明为虚析构函数！！！
 */
#include <iostream>
using namespace std;

class Arts{
public:
        string author;
        string decade;
public:
        Arts(string author,string decade)
                :author(author),decade(decade){}
        virtual void print()=0;
};

class Painting:public Arts{
private:
        float length;
        float width;
public:
        Painting(string author,string decade,float length,float width)
                :Arts(author,decade),length(length),width(width){}  
        virtual ~Painting(){cout<<"Paintint::~Painting()"<<endl;}   /*子类声明虚析构函数*/
        
        void print()
                {
                        cout<<"The Author:"<<author<<endl
                            <<"The Decade:"<<decade<<endl
                            <<"The Size:length "<<length
                            <<"\twidth "<<width<<endl;
                }
};

class Music:public Arts{
protected:
        float timeSpan;
public:
        Music(string author,string decade,float timeSpan)
                :Arts(author,decade),timeSpan(timeSpan){}
};

class Pop:public Music{
private:
        string singer;
public:
        Pop(string author,string decade,float timeSpan,string singer)
                :Music(author,decade,timeSpan),singer(singer){}
        virtual ~Pop(){}
        
        void print()
                {
                        cout<<"The Author:"<<author<<endl
                            <<"The Decade:"<<decade<<endl
                            <<"The Time Span:"<<timeSpan<<endl
                            <<"The Singer:"<<singer<<endl;
                }
};

class Rock:public Music{
private:
        int playPeoples;
public:
        Rock(string author,string decade,float timeSpan,int playPeoples)
                :Music(author,decade,timeSpan),playPeoples(playPeoples){}
        virtual ~Rock(){}
        
        void print()
                {
                        cout<<"The Author:"<<author<<endl
                            <<"The Decade:"<<decade<<endl
                            <<"The Time Span:"<<timeSpan<<endl
                            <<"The player numbers:"<<playPeoples<<endl;
                }
};
void show(Arts& a)
{
        a.print();
}

int main()
{
        Painting paint("徐悲鸿","50年代",56.77,23.45);
        show(paint);
        Pop pop("刘德华","70年代",6,"刘德华");
        show(pop);
        Rock rock("方文山","80年代",23,37);
        show(rock);
        Arts* pa=new Painting("sdad","sdfas",56.77,23.4);
        show(*pa);
        delete pa;
        return 0;    
}
