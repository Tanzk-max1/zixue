//
// Created by 15525 on 2024/6/2.
//

//#include "Screen.h"
#include <iostream>
#include <string>
//class Screen {
//public:
//  using pos = std::string::size_type;
//
//  Screen() = default;
//  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
//
//  char get() const { return contents[cursor]; }
//  char get(pos r, pos c) const { return contents[r * width + c]; }
//
//  std::string getContents() const { return contents; } // 公有成员函数返回 contents
//
//private:
//  pos cursor = 0;
//  pos height = 0;
//  pos width = 0;
//  std::string contents;
//};
//
//int main() {
//  Screen screen1(5,10);  // 创建一个高度为5，宽度为10的屏幕对象
//
//  // 输出屏幕的高度和宽度
//  std::cout << "Screen Height: " << screen1.getContents().length() << std::endl;
//  std::cout << "Screen Width: " << screen1.getContents() << std::endl;
//
//  // 输出 contents 的长度和内容
//  std::cout << "Contents Length: " << screen1.contents.length() << std::endl;
//  std::cout << "Contents: '" << screen1.contents << "'" << std::endl;
//
//  return 0;
//}