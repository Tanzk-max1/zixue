//
// Created by 15525 on 2024/5/11.
//
//#include "Chapter6.h"
#include <iostream>
#include "fact.h"
int fact(int val)
{
  if (val == 1)
    return 1;
  return val * fact(val - 1);
}
int func()
{
  int n, ret = 1;
  std::cout << "input a number: ";
  std::cin >> n;
  while (n > 1) ret *= n--;
  return ret;
}