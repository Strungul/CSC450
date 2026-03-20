

#include<iostream>
//#include<conio.h>  //  I don't think this is needed.
#include<iomanip>

//Standard namespace declaration  << This wasn't commented
using namespace std;

//Main Function  << This wasn't commented
int main()
{

     double myMoney = 1000.50;  //this should be printed out //++ -> What do you mean this should be printed out?  Now?  Later?

     // set precision of cout to print money values correctly
     cout << fixed;
     cout << setprecision(2);


     //Standard Ouput Statement << This wasn't commented
     cout << "Please be sure to correct all syntax errors in this program"<< endl; // This needed "<<" between cout and the string

     cout << "I have corrected all errors for this program." << endl; // add end quote at end of string

     cout << "The total amount of money available is = $"<< myMoney << endl;  // added money ammount to print here.  I'm guessing this is where it was supposed to print?

     // Wait For Output Screen

     //Main Function return Statement << This wasn't commented
     return 0;
}
