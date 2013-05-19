#include <iostream>
#include "client.h"
using namespace std;

int main()
{
	Client test;
	test.readlog();
	test.showinfo();
	test.sendlog();
	return 0;
}

