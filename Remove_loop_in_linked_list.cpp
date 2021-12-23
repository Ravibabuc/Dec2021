ListNode* Head=A;
    ListNode* Slow =A;
    ListNode* Fast =A;
    Slow=Slow->next;
    Fast=Fast->next->next;
    while(Fast && Fast -> next)
    {
        if (Slow == Fast)
            break;
        Slow=Slow->next;
        Fast=Fast->next->next;
    }
    
   //  cout<<" Fast00-> next "<<Fast<<endl;
   // cout<<"Fast000 data   "<<Fast->val<<endl;
    if(Slow == Fast)
    {
        
        Slow= Head;
        if(Slow == Fast)
        {
            //cout<<" Fast11-> next "<<Fast<<endl;
           // cout<<"Fast11 data   "<<Fast->val<<endl;
            
            while(Fast-> next != Slow)  Fast=Fast->next;
            
        }
        else
        {
            while(Fast-> next != Slow->next) 
            {
            //    cout<<" Fast2-> next "<<Fast<<endl;
            //    cout<<"Fast2 data   "<<Fast->val<<endl;
                Fast=Fast->next;
                Slow=Slow->next;
            }
        }
    }
 //   cout<<" Fast-> next "<<Fast<<endl;
  // cout<<"Fast data   "<<Fast->val<<endl;
    Fast-> next = NULL;
    return Head;
