#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int value){
    data = value;
    next = NULL;
}
};

void insertAtStart(node* &head,int x)
{
    node *temp = new node(x);

    if(head == NULL){
        head = temp;
    }else{
    temp->next = head;
    head = temp;
    }

}
void insertAtEnd(node* &head, int x){
    node *temp = new node(x);
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert(node* &head, int x, int loc){
    node *temp = new node(x);
    int count = 0;
    node *ptr = head;
    if(loc == 0){
        temp->next = head;
        head = temp;
    }
    while(ptr != NULL){
        count = count + 1;
        if(count == loc){
            temp->next = ptr->next;
            ptr->next = temp;
        }
        ptr = ptr->next;
    }

}

void deleteAtStart(node* &head){
if(head == NULL){
    cout<<"No entry found";
}else{
    head = head->next;
}
}

void deleteAtEnd(node* &head){
   if(head == NULL){
    cout<<"No entry found";
}else{
    node *ptr = head;
    while((ptr->next)->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
}
}

void deleteAtLoc(node* &head, int loc){
    int count = 0;
    node *ptr = head;
    node *ptr1 = head->next;
    if(loc == 0){
        head = head->next;
    }
    while(ptr1 != NULL){
        count = count +1 ;
        if(count == loc){
            ptr->next = ptr1->next;
        }
        ptr1 = ptr1->next;
        ptr = ptr->next;
    }
}



void print(node* &head){
    node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;}
}

int main(){
node *head = NULL;
insertAtStart(head,5);
insertAtStart(head,7);
insertAtEnd(head,8);
insert(head,6,3);
//deleteAtStart(head);
//deleteAtEnd(head);
//deleteAtLoc(head,0);

print(head);

return 0;
}
