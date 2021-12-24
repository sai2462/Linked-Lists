/*          This is only the main logic not the entire code
struct ListNode {
     int val;
     struct ListNode *next;
};*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp=l3;
    temp->val=0;
    temp->next=NULL;
    int c=0,s;
    while(l1!=NULL && l2!=NULL){
        s=l1->val+l2->val+c;
        struct ListNode* new1=(struct ListNode*)malloc(sizeof(struct ListNode));
        new1->val=s%10;
        temp->next=new1;
        if(s>=10)
            c=s/10;
        else
            c=0;
        l1=l1->next;
        l2=l2->next;
        temp=temp->next;
    }
    if(l1==NULL && l2==NULL){
        if(c!=0){
            struct ListNode* new1=(struct ListNode*)malloc(sizeof(struct ListNode));
            new1->val=c;
            new1->next=NULL;
            temp->next=new1;
            temp=temp->next;
        }
        temp->next=NULL;
    }
    else if(l1!=NULL){
        temp->next=l1;
        if(c!=0){
            s=l1->val+c;
            while(c!=0 && l1!=NULL){
                s=l1->val+c;
                l1->val=s%10;
                if(s>=10){
                    c=s/10;
                }
                else
                    c=0;
                temp=l1;
                l1=l1->next;
            }
            if(c!=0){
                struct ListNode* new1=(struct ListNode*)malloc(sizeof(struct ListNode));
                new1->val=c;
                new1->next=NULL;
                temp->next=new1;
            }
        }
    }
    else if(l2!=NULL){
        temp->next=l2;
        if(c!=0){
            s=l2->val+c;
            while(c!=0 && l2!=NULL){
                s=l2->val+c;
                l2->val=s%10;
                if(s>=10){
                    c=s/10;
                }
                else
                    c=0;
                temp=l2;
                l2=l2->next;
            }
            if(c!=0){
                struct ListNode* new1=(struct ListNode*)malloc(sizeof(struct ListNode));
                new1->val=c;
                new1->next=NULL;
                temp->next=new1;
            }
        }
    }
    return l3->next;
}