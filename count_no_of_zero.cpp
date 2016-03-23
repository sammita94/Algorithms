// C++ program to count number from 1 to n with
// 0 as a digit.
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of integers having zero upto given digits
int zeroUpto(int digits)
{
    // Refer below article for details
    // http://www.geeksforgeeks.org/count-positive-integers-0-digit/
    int first  =  (pow(10,digits)-1)/9;
    int second = (pow(9,digits)-1)/8;
    return 9 * (first - second);
}
 
// utility function to convert character representation
// to integer
int toInt(char c)
{
    return int(c)-48;
}
 
// counts numbers having zero as digits upto a given
// number 'num'
int countZero(string num)
{
    // k denoted the number of digits in the number
    int k = num.length();
 
    // Calculating the total number having zeros,
    // which upto k-1 digits
    int total = zeroUpto(k-1);
 
    // Now let us calculate the numbers which don't have
    // any zeros. In that k digits upto the given number
    int non_zero = 0;
    for (int i=0; i<num.length(); i++)
    {
        // If the number itself contains a zero then
        // decrement the counter
        if (num[i] == '0')
        {
            non_zero--;
            break;
        }
 
        // Adding the number of non zero numbers that
        // can be formed
        non_zero += (toInt(num[i])-1) * (pow(9,k-1-i));
    }
 
    int no = 0, remaining = 0;
 
    // Calculate the number and the remaining after
    // ignoring the most significant digit
    for (int i=0; i<num.length(); i++)
    {
        no = no*10 + (toInt(num[i]));
        if (i != 0)
            remaining = remaining*10 + toInt(num[i]);
    }
 
    // Final answer is calculated
    int ans = zeroUpto(k-1) + (remaining-non_zero);
    return ans;
}
 
// Driver program to test the above functions
int main()
{
    string num = "107";
    cout << "Count of numbers from 1" << " to "
        << num << " is " << countZero(num) << endl;
 
    num = "1264";
    cout << "Count of numbers from 1" << " to "
        << num << " is " <<countZero(num) << endl;
 
    return 0;
}
