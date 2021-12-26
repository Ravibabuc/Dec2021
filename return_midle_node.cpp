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

 int solve(ListNode* A) {

    ListNode *Head =A;
    ListNode *Slow =A;
    ListNode *Fast =A;
    ListNode *Node2;
    ListNode *Node1;
    ListNode *Prev;


 //   Slow = Slow->next;
   // Fast = Fast->next->next;

    while(Fast != NULL && Fast->next != NULL)
    {


        Fast = Fast->next->next;
        Prev =Slow;
        Slow = Slow->next;
       // cout<<"Fast "<<Fast<<endl;
     //  cout<<"Fast->val "<<Fast->val<<endl;

       // cout<<"Slow "<<Slow<<endl;
       // cout<<"Slow->val "<<Slow->val<<endl;
    }
    if( Fast == NULL)
    {
       // cout <<" fast "<<Slow->val;
        return Slow->val;
    }
    else if (Fast-> next == NULL) 
    {
        //cout <<" fast "<<Slow->val;
        return Slow->val;
    }
    
    return 0;
        
}

ListNode *insert(ListNode* Head, vector<int>& A)
{
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

ListNode* reverse(ListNode* A, int B, int C)
{
    ListNode *curr1= A;
    ListNode *curr;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *join = NULL;
    ListNode *newHead = NULL;
    ListNode *tail = NULL;
    ListNode *ptr1;
    ListNode *ptr2;
    int cnt=0;
    
    if(A == NULL || A ->next == NULL) 
        return A;
    while(curr1 != NULL)
    {
        cnt ++;
        
        
        if(cnt ==B)
        {
            ptr1=curr1;
        }
        if(cnt ==C)
        {
            ptr2=curr1->next;
        }
        curr1 = curr1->next;
    }
    cout<<" ptr1 "<<ptr1<<endl;
    cout<<" ptr1 "<<ptr1->val<<endl;


    curr =ptr1;
    while(curr != ptr2)
    {
       
      
        next =curr -> next;
        curr->next =prev;
        prev= curr;
        curr = next;
        
        cout<<" curr "<<curr<<endl;
        cout<<" curr "<<curr->val<<endl;
    }
    
    join=A;
    while(join->next != ptr1)
   {
        
       cout<<" joinxx "<<join<<endl;
       cout<<" joinxx "<<join->val<<endl;
       join= join->next;
   }

     join->next = prev;
   // ptr1 = prev;
   
   // ptr1->next =ptr2;
//    cout<<" ptr2 "<<ptr2<<endl;
   //    cout<<" ptr2 "<<ptr2->val<<endl;
    while(join != NULL)
   {
        
       cout<<" joinyy "<<join->next<<endl;
       cout<<" joinyy "<<join->val<<endl;
     
       if(join->next ==NULL)
       {
        join -> next = ptr2;
        break;
       }
        
          join= join->next;
   }
   if(join == NULL)
   {
     //  cout<<"hello"<<endl;
       join =ptr2;
       cout<<" joinzz "<<join->next<<endl;
       cout<<" joinzz "<<join->val<<endl;
        cout<<" ptr2 "<<ptr2<<endl;
       cout<<" ptr2 "<<ptr2->val<<endl;
      cout<<" ptr2 "<<ptr2->next<<endl;
        
   }
     return A;
}




int main()
{
    //vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector <int> A = {1, 2, 3, 4,5,6};
    int B =2;
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

    int cnt=0;
    cnt = solve(Head);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {


        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
        cnt ++;
        if(cnt == 10) break;
    }
    
    

    return 0;
}
