/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by: Shun Furuya
IDE: Xcode
*~**/
#include <iostream>
#include <iomanip>
#include <string>
#include "Customer.h"

using namespace std;

/* Write your code here */
Customer::Customer(){
    year = -1;
    mileage = -1;
    seq = -1;
    name = "";
}

Customer::Customer(int y, int m, int s, string n){
    year = y;
    mileage = m;
    seq = s;
    name = n;
}

int Customer::getSerialNum()
{
    int serialNum;
       
    serialNum = (mileage / 1000 + year - seq) * 100 + (100 - seq);
       
    return serialNum;
}

bool Customer::operator < (Customer &right)
{
    bool status = false;
    
    if(getSerialNum() < right.getSerialNum()){
        status = true;
    }
    return status;
}

bool Customer::operator > (Customer &right)
{
    bool status = false;
    
    if(getSerialNum() > right.getSerialNum()){
        status = true;
    }
    return status;
}

bool Customer::operator == (Customer &right)
{
    bool status = false;
    
    if(getSerialNum() == right.getSerialNum()){
        status = true;
    }
    return status;
}

ostream &operator << (ostream &strm, const Customer &obj)
{
    cout << left;
    cout << " " << setw(2);
    cout << " " << setw(2) << obj.year;
    cout << " " << setw(9) << obj.mileage;
    cout << " " << obj.name;
    cout << right;
    cout << left << endl;
    
    return strm;
}
