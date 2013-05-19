#include <iostream>
using namespace std;

class Arts{
protected:
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
        virtual ~Painting(){}
        
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
        
        return 0;    
}
