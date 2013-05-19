#include <iostream>
using namespace std;
class Database{
public:
        virtual void connect()=0;
        virtual void query()=0;
};
class Access:public Database{
public:
        void connect(){cout<<"Access::Connected"<<endl;}
        void query(){cout<<"Access::Query"<<endl;}
        virtual ~Access(){}
};
class SQLServer:public Database{
public:
        void connect(){cout<<"SQLServer::Connected"<<endl;}
        void query(){cout<<"SQLServer::Query"<<endl;}
        virtual ~SQLServer(){}
};
class Oracle:public Database{
public:
        void connect(){cout<<"Oracle::Connected"<<endl;}
        void query(){cout<<"Oracle::Query"<<endl;}
        virtual ~Oracle(){}
};
class Program{
public:
        void visit(Database* p)
                {
                        p->connect();
                        p->query();
                }
};


int main()
{
        Program exec;
        Access access;
        SQLServer sql;
        Oracle oracle;
        exec.visit(&access);
        exec.visit(&sql);
        exec.visit(&oracle);
        
        return 0;    
}
