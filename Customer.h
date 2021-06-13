/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by: Shun Furuya
  IDE: Xcode
  *~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
 
#include <string>

using std::string;
using std::ostream;

class Customer;

ostream &operator << (ostream &, const Customer &);

class Customer
{
private:
    int year;
    int mileage;
    int seq;
    string name;
    
public:
   /* Write your code here */
    Customer();
    Customer(int, int, int, string);
    
    //setters
    void setYear(int y){ year = y;}
    void setMileage(int m){ mileage = m;}
    void setSeq(int s){ seq = s;}
    void setName(int n){ name = n;}
    
    //getters
    int getYear() const {return year;}
    int getMileage() const {return mileage;}
    int getSeq() const {return seq;}
    string getName() const {return name;}
    
    int getSerialNum();

    bool operator < (Customer &);
    bool operator > (Customer &);
    bool operator == (Customer &);
    
    friend ostream &operator << (ostream &, const Customer &);
};
#endif
