#include"logreader.h"
int main()
{
	list<logmatchrec> matches;
	logreader lr;
	lr.readlog(&matches);
}
