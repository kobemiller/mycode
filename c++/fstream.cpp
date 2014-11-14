#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string s, line;
    std::ifstream in("jinzhi.cpp");
    in >> s;                        //in 每次读取一个单词，即遇到空格结束 
    std::cout << s << std::endl;
    getline(in, line);              //getline每次读取一行
    std::cout << line << std::endl;

    return 0;
}
