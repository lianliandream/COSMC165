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
#include <math.h>

// Declaring function prototypes.
void print_id(string);
void welcomeAndtime();
float getChange(float);
void getBillChange(float);
void printMoney(int);

// Global varibles.
int const size = 11;
float moneyValues[size] = {100,50,20,10,5,1,0.5,0.25,0.1,0.05,0.01};
int moneyCounts[size] = {0,0,0,0,0,0,0,0,0,0,0};

/*********************************************************************
* Function: Main
**********************************************************************/
int main()
{
  print_id("Lab 2A: Making Exact Change Using Functions");
  welcomeAndtime();
  float userChange = getChange(userChange);
  getBillChange(userChange);
  printMoney(0);
 
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
* Parameters:float : userInput
* Return: change:left-over amount that should make change for
**********************************************************************/ 
float getChange(float userInput)
{ // code for function 
  float purchaseAmount, amountTendered, change;
  cout << "Enter the purchase amount and amount tendered :" ;
  cin >> purchaseAmount >> amountTendered;
  change = amountTendered - purchaseAmount;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "$" << change << endl;
  return change;
 }
 
/*********************************************************************
* Function: getBillChange  
* Parameters:float :newChange
* Return: none
**********************************************************************/  
void getBillChange(float newChange)
{ // code for function 
 for (int i = 0; i<= size;i++)
 {
  int modResult = floor(newChange / moneyValues[i]);    
  newChange -= modResult * moneyValues[i];
  if (modResult > 0)
  {
    moneyCounts[i] += modResult;
  }
 }
} 

/*********************************************************************
* Function: printMoney  
* Parameters:int : i 
* Return: none
**********************************************************************/  
void printMoney(int i)
{ // code for function 
  for (int i = 0; i < size;i++)
  {
    if (moneyCounts[i] > 0)
    {
      cout << moneyCounts[i] << ": ";
      if(moneyValues[i] < 1)
      {
        cout << int(moneyValues[i]*100) << " cent-coin";
      }
      else
      {
        cout << "$" << int(moneyValues[i]) << " bill";
      }
      if(moneyCounts[i] > 1)
      {
        cout << "s";  
      }
        cout << endl;  
      }
   }
}


