////
//// Created by 15525 on 2024/5/30.
////
//
//#include "avg_price.h"
//#include "Sales_data.h"
//int main()
//{
//  Sales_data total;         // variable to hold the running sum
//  if (read(cin, total))  {  // read the first transaction
//    Sales_data trans;     // variable to hold data for the next transaction
//    while(read(cin, trans)) {      // read the remaining transactions
//      if (total.isbn() == trans.isbn())   // check the isbns
//        total.combine(trans);  // update the running total
//      else {
//        print(cout, total) << endl;  // print the results
//        total = trans;               // process the next book
//      }
//    }
//    print(cout, total) << endl;          // print the last transaction
//  } else {                                 // there was no input
//    cerr << "No data?!" << endl;         // notify the user
//  }
//}