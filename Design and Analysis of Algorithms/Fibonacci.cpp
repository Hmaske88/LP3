#include <iostream>
using namespace std;

class Fib
{
    public:
    void fibIter(int num) 
    {
       int x = 0, y = 1, z = 0;
       for (int i = 0; i < num; i++) 
       {
          cout << x << " ";
          z = x + y;
          x = y;
          y = z;
       }
    }
    
    int fibRec(int num) 
    {
       if((num==1)||(num==0)) 
       {
          return(num);
       }
       else 
       {
          return(fibRec(num-1)+fibRec(num-2));
       }
    }
    
};


int main() 
{
   int num,n;
   Fib obj;
   cout<<"MENU : "<<"\n1.Iteration"<<"\n2.Recursion"<<"\nEnter choice : ";
   cin>>n;
   switch(n)
   {
       case 1:
       {
           cout << "\nEnter the number of terms of series : ";
           cin >> num;
           cout << "\nThe fibonacci series using Iteration is: " ;
           obj.fibIter(num);
       }
       break;
       
       case 2:
       {
           int x , i=0;
           cout << "\nEnter the number of terms of series : ";
           cin >> x;
           cout << "\nFibonnaci Series using Recursion is : ";
           while(i < x) 
           {
              cout << " " << obj.fibRec(i);
              i++;
           }
       }
   }
   
   return 0;
}
