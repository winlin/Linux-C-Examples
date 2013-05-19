typedef vector<char> Line;
class Document
{
        list<Line> line;
public:
        Document(  ){}
};

istream& operator>>( istream& is,Document& d )
        {
                char h;Line oneline;
                while( is.get( ch ) )
                        {
                                oneline.push_back(ch);
                                if( ch=='\n' )
                                        d.line.push_back( oneline );
                        }
        }

#include <iostream>
using namespace std;
class Student{
  string name;
  int age;
  return 0;
}
