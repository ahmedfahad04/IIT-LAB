#include <iostream>
#include<fstream>
using namespace std;


int main()
{
    fstream f;
    f.open("Demo.txt");
    string str = "হ।"; 
    string substr = "৷";
    str.replace(1,3,"###");
    f << str;
    return 0;
}