#ifndef DMSDAO_H
#define DMSDAO_H
#include "data.h"
class DMSDAO
{  
public: 
        virtual void  connect(char * user); 
	    virtual void  save(logdata data);
        virtual void  close(); 
		virtual void  commit();
};
#endif
