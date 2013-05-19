#ifndef DMSEXCEPTION_H
#define DMSEXCEPTION_H
#include <stdexcept>
class DMSException:public runtime_error
{
public:
		DMSException():runtime_error("数据采集异常"){}
		DMSException(char *msg):runtime_error(msg){}
};
#endif
