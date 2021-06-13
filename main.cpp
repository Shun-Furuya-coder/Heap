/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By: Shun Furuya
  IDE: Xcode
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include "Customer.h"
#include "Heap.h"

using namespace std;

   /* Write your code here */
int compareMin(Customer &, Customer &);
int compareMax(Customer &, Customer &);

int main()
{
    string inputFileName;
    cout << "Input file name: ";
    getline(cin, inputFileName);
    
    ifstream inFile(inputFileName);
    if (!inFile) {
         cout << "Error opening the input file: \"" << inputFileName << "\"" << endl;
         exit(EXIT_FAILURE);
    }
    
   /* Write your code here */
    Heap<Customer> heap;
    string line;
    int seq = 0;
    
    int count = 0;
    cout << " ==== =======   =============" << endl
    << " Year Mileage   Name" << endl
    << " ==== =======   =============" << endl;
    
    while (getline(inFile, line))
    {
        char order;
       string name;
       int mileage, year;
    
       stringstream temp(line);
       temp >> order;
        
        if(order == 'A'){
            temp >> year;
            temp >> mileage;
            seq++;
            temp.ignore();
            getline(temp, name);
            Customer aCustomer(year, mileage, seq, name);
            heap.insertHeap(aCustomer, compareMin);
        }
        else if(order == 'S'){
            Customer out;
            heap.deleteHeap(out, compareMin);
            cout << out;
            count++;
        }
    }
    

    inFile.close();
    
   /* Write your code here */
   
    cout << " ==== =======   =============" << endl;
    cout << "Served overbooked customers: " << count << endl << endl;
    
    count = 0;
    
    cout << " ==== =======   =============" << endl
    << " Year Mileage   Name" << endl
    << " ==== =======   =============" << endl;
    
    Customer o;
    
    while(!heap.isEmpty()){
        heap.deleteHeap(o, compareMin);
        cout << o;
        count++;
    }
    
    cout << " ==== =======   =============" << endl;
    cout << "Rejected overbooked customers: " << count << endl;
    
    
    return 0;
}

   /* Write your code here */

/*
  compare two data items: needed to build a min-heap
*/
int compareMin(Customer &x, Customer &y)
{
    if (x < y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}

/*
  compare two data items: needed to build a max-heap
*/
int compareMax(Customer &x, Customer &y)
{
    if (x > y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}

