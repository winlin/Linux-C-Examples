#include<iostream>
using namespace std;
#include "data.h"
#include "logreader.h"

int main(){
  logreader  lr;
  list<logmatchrec> matches;
  lr.readlog(&matches);

}

