// C++ program to check if a number is power of
// another number
#include <bits/stdc++.h>
using namespace std;
 
/* Removes recurring digits in num[]  */
bool isPower(int x, long int y)
{
   // The only power of 1 is 1 itself
   if (x == 1)
     return (y == 1);
 
   // Repeatedly comput power of x
   long int pow = 1;
   while (pow < y)
      pow *= x;
 
   // Check if power of x becomes y
   return (pow == y);
}
 
/* Driver program to test above function */
int main()
{
   cout << isPower(10, 1) << endl;
   cout << isPower(1, 20) << endl;
   cout << isPower(2, 128) << endl;
   cout << isPower(2, 30) << endl;
   return 0;
}