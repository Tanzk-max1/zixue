//
// Created by 15525 on 2024/5/30.
//

#ifndef ZIXUECPP_SALES_DATA_H
#define ZIXUECPP_SALES_DATA_H
#include <iostream>
#include <string>
using namespace std;
struct Sales_data;
istream & read(istream,Sales_data&);
struct Sales_data {
  Sales_data() = default;
  Sales_data(const string &s) : bookNo(s){}
  Sales_data(const string &s ,unsigned n,double p) : bookNo(s),units_sold(n),revenus(n*p){}
  Sales_data(istream &is){ read(is,*this);};
  string isbn() const{return bookNo;};
  Sales_data& combine(const Sales_data&);

  string bookNo;
  unsigned units_sold = 0;
  double revenus = 0.0;

};
istream& read(std::istream& is, Sales_data& item)//输入到is，然后输出到item中
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenus = price * item.units_sold;
  return is;
}
ostream & print(ostream& os ,const Sales_data&item)//输出到os，os被用于将item对象的数据输出到输出流中
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenus;
    return os;
}
Sales_data add(const Sales_data &lhs , const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
//Sales_data::Sales_data(std::istream &is)
//{
//  read(is,*this);
//
//}
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
  units_sold += rhs.units_sold;
  revenus += rhs.revenus;
  return *this;
}


#endif // ZIXUECPP_SALES_DATA_H
