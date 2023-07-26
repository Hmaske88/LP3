#include <iostream>
using namespace std;
void fibIter(int num) {
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < num; i++) {
      cout << x << " ";
      z = x + y;
      x = y;
      y = z;
   }
}

int fibRec(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fibRec(x-1)+fibRec(x-2));
   }
}

int main() {
   int num;
   cout << "Enter the number of terms of series : ";
   cin >> num;
   cout << "\nThe fibonacci series using Iteration is: " ;
   fibIter(num);
   
   int x , i=0;
   cout << "\n\nEnter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series using Recursion is : ";
   while(i < x) {
      cout << " " << fibRec(i);
      i++;
   }
   
   return 0;
}
