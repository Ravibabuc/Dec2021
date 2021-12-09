/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
#include<vector>
using namespace std;
void reverse_string(string &A,int st, int n)
{
    
    char temp;

    
    for(int i =st, j= n-1;i<j;i++, j--)
    {
     
            temp= A[i];
            A[i]=A[j];
            A[j] = temp;

    }
    //return A;
         std::cout << " A 0  = "  <<A<< std::endl;

}

string solve(string A) 
{
    int n =A.size();
    
 
    char temp;
    reverse_string( A, 0, n);
       // std::cout << " A 1  = "  <<A<< std::endl;

    for (int i =n-1;i>=0 ;i--)
    {
        if( A[i] == ' ') {
            continue;
        }
        break;
    }

    int start=0;
    for (int i =0;i<n;i++)
    {
       // if(i== 0 && A[i] == ' ') {
          //  continue;
        //}
        if(A[i] == ' ' || i==n-1)
        {
            if(A[i] == ' ')
            {
                reverse_string( A, start, i);
            }
            if(i == n-1)
                reverse_string( A, start, i+1);
         start=i+1;   
        }
       
    }   
    
    
    char *B;
    B =new char[n];
    int j=0;
    for (int i =0;i < n;i++)
    {
       
         
          if(i==0)
          {
           while(1)
           {
            if(A[i] == ' ')
            {
             i++;
            }
            else break;
           }
          }
          
          
        B[j]= A[i]; 
        j++;
        
    }
    B[j] ='\0';
  
    
    return B;
}

int main()
{
    string A = "crulgzfkif gg ombt vemmoxrgf qoddptokkz op xdq hv ";
    string B = solve(A);
    std::cout << B << std::endl;

    return 0;
}
