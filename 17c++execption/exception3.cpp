/*自定义异常体系
 *异常中最重要的是类型
 *异常函数里面往往是空白
 */
#include <iostream>
using namespace std;

class BankException{
public:
        virtual const char* what()const throw()
                {
                        return "银行项目总异常";
                }
};
/*业务异常/商业异常*/
class BusinessException:public BankException{
        
};
/*系统异常*/
class SystemException:public BankException{
        
};
/*登录异常*/
class LoginException:public BusinessException{
        
};
/*转帐异常*/
class TransferException:public BusinessException{
        
};

/*数据库访问异常*/
class SQLException:public SystemException{
        
};
/*输入输出异常*/
class IOException:public SystemException{
        
};
/*文件未找到异常*/
class FileNotFoundException:public IOException{
        
};

void transfer()throw(TransferException)
{
                
}


int main()
{
        try{
                transfer();
        }catch(TransferException& e){
                /*异常的捕获顺序，应当先细后粗*/
        }catch(BusinessException& e){   
                /*父类异常可以捕获所有子类的异常*/
        }
        
        return 0;    
}
