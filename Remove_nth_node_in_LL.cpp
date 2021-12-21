/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};


ListNode *insert(ListNode* Head, vector<int>& A)
{
    //vector <int> A = {1, 2, 3, 4, 5};
    int n =A.size();
    
    Head= new ListNode();
    Head->val=A[0];
    ListNode  *tmp =NULL;
    Head->next=tmp;
   
  //  cout<<" Head "<<Head<<endl;
  //  cout<<"Head data   "<<Head->val<<endl;
 //   cout<<" Head-> next "<<Head-> next<<endl;
    tmp= new ListNode();
    tmp->val=A[1];
    Head-> next= tmp;
    tmp->next=NULL;
    
   //  cout<<" Head "<<Head<<endl;
   // cout<<"Head data   "<<Head->val<<endl;
  //  cout<<" Head-> next "<<Head-> next<<endl;
    
   for(int i =2;i<n;i++)
    {
        
       ListNode* tmp1= new ListNode();
       tmp1->val=A[i];
       tmp1-> next= NULL;
       tmp->next=tmp1;
       tmp = tmp->next;
      // cout<<" Head-> next "<<Head-> next<<endl;
      // cout<<"Head data   "<<tmp->val<<endl;

    }
    return Head;
}

ListNode* removeNthFromEnd(ListNode* A, int B) 
{
    
    ListNode* tmp=A;
    ListNode* tmp1=A;
    ListNode* tmp2;

    int cnt=0;
    
    
    while(tmp1 != NULL)   
    {
        tmp1 =tmp1->next;
        cnt++;
    }    
    int step=0;
    int mov=cnt-B;
    
    //cout<<"step ="<<step<<endl;
    //cout<<"mov ="<<mov<<endl;
    //cout<<"cnt ="<<cnt<<endl;
    if(B < cnt)
    {
        while(tmp != NULL)   
        {
             step++;
             //  cout<<"step ="<<step<<endl;
    
           if(step==mov)
           {
               
             //  temp = first->next;
            //first->next = first->next->next;
            //free (temp);
            //return head;
            //cout<<" tmp xx "<<tmp<<endl;
            //cout<<" tmp->next xx "<<tmp->next<<endl;
            //cout<<"tmp data xx   "<<tmp->val<<endl;
             tmp2=tmp->next;
             tmp->next=tmp->next->next;
             delete tmp2;
           // cout<<" tmp "<<tmp<<endl;
            //cout<<" tmp->next "<<tmp->next<<endl;
            //cout<<"tmp data   "<<tmp->val<<endl;
            return A;
           }     
          

            //cout<<" tmp->next "<<tmp->next<<endl;
            //cout<<"tmp data   "<<tmp->val<<endl;
            tmp =tmp->next;
        
        }
    }
    else
    {
       // cout<<" tmp xx"<<tmp<<endl;
          // cout<<" tmp->next  x"<<tmp->next<<endl;
        //   cout<<"tmp data  xx "<<tmp->val<<endl;
             tmp2=tmp;
             tmp=tmp->next;
             //tmp->next = tmp->next->next;
             delete tmp2;
          // cout<<" tmp "<<tmp<<endl;
          // cout<<" tmp->next "<<tmp->next<<endl;
          // cout<<"tmp data   "<<tmp->val<<endl;
            return tmp;
    }
   // return A;
}

 
int main()
{
    //vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector <int> A = {1, 2, 3, 4, 5};
    int B =4;
    //list <int>  C;
// int C;
    ListNode* Head;
    Head=insert(Head, A);
    
   // C = removeNthFromEnd(A, B);
   // for (int i =0;i < C.size();i++)
       // cout<<C[i]<<endl;
       
    
   // while(Head != NULL)   
   // {
            

       
    //    cout<<" Head->next "<<Head->next<<endl;
     //  cout<<"Head data   "<<Head->val<<endl;
     //   Head =Head->next;
   // }
       
    Head = removeNthFromEnd(Head, B);
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {
            

       
        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
    }
       
    return 0;
}
