#include <iostream>
#include <string>
using namespace std;

class Person
        {
        private:
                string name;
                short int age;
                bool sex;   //male 1;female 0 
                Person* partner;
        public:
                Person(  ):name( "" ),age( 0 ),sex( 1 ),partner( NULL ){}
                Person( string iname,int iage,bool isex,Person* other=NULL);
                
                void  Marry( Person* other );
                void  Divorce(  );
                
        protected:
               bool  CanMarry( Person* other );         
        };

bool Person::CanMarry( Person* other )
        {
                if( sex==other->sex )
                {cout<<"同性不可结婚"<<endl;return 0;}
                else if( (other->sex&&other->age<22)||( !other->sex&&other->age<20 ) )
                {cout<<other->name<<"未到法定年龄"<<endl;return 0;}
                else if( ( sex&&age<22) || (!sex&&age<20) )
                        {cout<<name<<"未到法定年龄"<<endl;return 0;}
                else if( partner )
                {cout<<name<<"已婚"<<endl;return 0;}
                
                return 1;
        }

Person::Person( string iname,int iage,bool isex,Person* other )
{
        name=iname;age=iage;sex=isex;partner=NULL;
        if( other )
                {
                        if( CanMarry( other ) )
                                {
                                        Marry( other );
                                }
                }
}

void Person::Marry(Person* other  )
{
        if( !other )
                return;
        if( CanMarry( other ) )
        {partner=other;cout<<"恭喜"<<name<<"&&"<<other->name<<"新婚"<<endl;}
}

void Person::Divorce(  )
                        {
                                cout<<"WARNING：你确定离婚?(y/n )"<<endl;
                                char c;cin>>c;
                                if( c=='y' ) partner=NULL;
                                else return;
                                cout<<"你已经离婚"<<endl;
                        }
              
int main(  )
        {
                Person per1( "liu",23,1 );
                Person per2( "yang",22,0 );
                Person per3( "ming",23,0 );
                Person per4( "wang",18,1 );
                per1.Marry( &per2 );
                per1.Marry( &per3 );
                per1.Marry( &per4 );
                per1.Divorce(  )  ;
                Person per5( "hang",24,1,&per3 );
                
                return 0;  
        }
