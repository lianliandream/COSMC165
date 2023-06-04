/*********************************************************************
* Name: Lian Wang
* Lab 2a: Making Exact Change Using Functions
* Editor(s) used: JDoodle
* Compiler(s) used: JDoodle
* Description:
*     This program manages courses taken by a student.
**********************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <string>
using std::string;

#include <ctime>
#include <math.h>

// Declaring function prototypes.
void print_id(string);
void welcomeAndtime();
float getChange();
float getBillChange(float,float);
void printBillCount(int,float);

// Global varibles.
const float hundred = 99.9999,
              fifty = 49.9999,
              twenty = 19.9999,
              ten = 9.9999,
              five = 4.9999,
              one = 0.9999,
              fiftyCoin = 0.4999,
              twentyFiveCoin = 0.2499,
              tenCoin = 0.0999,
              fiveCoin = 0.0499,
              oneCoin = 0.0099;             

/*********************************************************************
* Function: Main
**********************************************************************/
int main()
{
  print_id("Lab 2A: Making Exact Change Using Functions");
  welcomeAndtime();
 
  float userChange = getChange(); 
  float newChange = getBillChange(userChange,hundred);
  newChange = getBillChange(newChange,fifty);
  newChange = getBillChange(newChange,twenty);
  newChange = getBillChange(newChange,ten);
  newChange = getBillChange(newChange,five);
  newChange = getBillChange(newChange,one);
  newChange = getBillChange(newChange,fiftyCoin);
  newChange = getBillChange(newChange,twentyFiveCoin);
  newChange = getBillChange(newChange,tenCoin);
  newChange = getBillChange(newChange,fiveCoin);
  newChange = getBillChange(newChange,oneCoin);

  return 0;
}

/*********************************************************************
* Function: welcome message and time message
* Parameters:No parameters
* Return: NONE
**********************************************************************/ 
void welcomeAndtime()
{ // code for function 
  cout << "Welcome To My Change Program" << endl;
  
  time_t  currTime = time(NULL) ;
  cout << "raw currTime: " << currTime << endl;
  cout << "Current date and time is: " << ctime(&currTime) << endl ;
}

/*********************************************************************
* Function: print_id 
* Parameters:string : lab_desc
* Return: NONE
**********************************************************************/
void print_id(string lab_desc) 
{ // code for function 
 cout << "Lian Wang\n";
 cout << lab_desc;
 cout << "Editor(s) used: jdoodle\n";
 cout << "Compiler(s) used: jdoodle\n";
 cout << "File: " << __FILE__ << "\n";
 cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}

/*********************************************************************
* Function: getChange  
* Parameters: none 
* Return: change:left-over amount that should make change for
**********************************************************************/ 
float getChange()
{ // code for function 
  float purchaseAmount, amountTendered, change;
  cout << "Enter the purchase amount and amount tendered :" ;
  cin >> purchaseAmount >> amountTendered;
  change = amountTendered - purchaseAmount;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "Change is " "$" << change << "." << endl;
  
  return change;
 }
 
/*********************************************************************
* Function: getBillChange  
* Parameters: float : newChange ,float : moneyValues 
* Return: leftOver , the amount of money that is going to convert to 
*                    bills and coins
**********************************************************************/ 
float getBillChange(float newChange,float moneyValue)
{ // code for function 
  int temp = 0; 
  float oldChange = newChange;
  float leftOver;
  if(newChange > 0)
  {
    while(newChange >= moneyValue) 
    {
      newChange -= moneyValue; 
      temp++;
    }
  } 
  leftOver = oldChange - (temp * moneyValue);
  
  // call the printBillCount to print the convered bills and coins 
  printBillCount(temp,moneyValue);
  
  return leftOver;
}

/*********************************************************************
* Function: printBillCount  
* Parameters:int : billAmount ,float : moneyValues 
* Return: none 
**********************************************************************/ 
void printBillCount(int billAmount,float moneyValues)
{ // code for function 
  if (billAmount > 0) 
  {
    cout << billAmount << ":" ;
    if(moneyValues < 1 && moneyValues == 0.9999)
    {
      cout << int(ceil(moneyValues*100)) << " cent-coin" ;
    }
    else 
    {
      cout << "$" << ceil(moneyValues) << " bill";
    }
    
  if(billAmount > 1)
  {
    cout << "s";
  }
  cout << endl;
  }  
}