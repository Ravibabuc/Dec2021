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

ListNode* deleteDuplicates(ListNode* A) 
{
    ListNode *current= A;
    ListNode *next_next =NULL;
    
  
    
    if(current == NULL ) 
        return current;
   
    
    
   while (current->next != NULL)
    {
      
         
       if( current->val == current->next->val )
       {
           
           // cout<<" current->next "<<current->next<<endl;
           // cout<<" current "<<current<<endl;
           
           next_next = current->next->next;
           free(current->next);
           current->next =next_next;
           
       }
       else
       {
          
          current= current->next;
          
       }

    }
    
     return A;
}

ListNode * removeDuplicates(ListNode* A)
{
    /* Pointer to traverse the linked list */
    ListNode* current = A;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    ListNode* next_next;
     
    /* do nothing if the list is empty */
    if (current == NULL)
    return current;
 
    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (current->val == current->next->val)
        {
            /* The sequence of steps is important*/       
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            current = current->next;
        }
    }
    return A;
}


int main()
{
   //vector<int> A = {1, 2, 3, 4, 5, 6};
  // vector<int> A = {1, 2, 3, 4, 5, 6};
    vector <int> A ={1, 1, 2,2, 3,4};
    int B =2;
    //list <int>  C;
// int C;
    ListNode* Head;
    Head=insert(Head, A);

   // C = removeNthFromEnd(A, B);
   // for (int i =0;i < C.size();i++)
       // cout<<C[i]<<endl;
    ListNode *curr =Head;
    cout<<"list started ----------"<<endl;
    while(curr != NULL )   
   {



       cout<<" Head->next "<<curr->next<<endl;
       cout<<"Head data   "<<curr->val<<endl;
       curr =curr->next;
    }
    cout<<"list end ----------"<<endl;
    int cnt=0;
    Head = deleteDuplicates(Head);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {


        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
        cnt ++;
       // if(cnt == 10) break;
    }
    
    

    return 0;
}
