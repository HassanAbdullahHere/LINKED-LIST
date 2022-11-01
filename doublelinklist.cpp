#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int value){
        next=NULL;
        data=value;
        prev=NULL;
    }
};

void insert_at_start(node* &head,int value){

    node* newNode = new node(value);
    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void insert_at_end(node* &head,int value){
    node* newNode = new node(value);
    if(head==NULL){
        head=newNode;
    }else{
    node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    }
}

void insert_at_index(node* &head,int value,int loc){
    node* newNode = new node(value);
    if(head==NULL){
        head=newNode;
    }else if(loc == 1 ){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    else{
        node* ptr = head;
        int count = 0;

        while(ptr != NULL){
            count = count+1;
            if(count == loc){
                (ptr->prev)->next = newNode;
                newNode->prev = ptr->prev;
                newNode->next = ptr;
                ptr->prev = newNode;
                break;
            }
            ptr = ptr->next;
        }
    }
}

void print(node* &node){
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

void changeByConstant(char op,int num,node* &head){
    node* ptr = head;
    while(ptr!=NULL){
        if(op == '+'){
            ptr->data+=num;
            ptr = ptr->next;
        }
        else if(op == '-'){
            ptr->data-=num;
            ptr = ptr->next;
        }else{
        cout<<"invalid operand"<<endl;
        exit(EXIT_FAILURE);
        }
    }
}

void checkEach2(node* &head){
    node* ptr = head;
    node* ptr1 = head->next;
    while(ptr1 != NULL){
        if(ptr->data > ptr1-> data){
            ptr->data = ptr->data - ptr1->data;
        }else{
            ptr1->data = ptr1->data - ptr->data;
        }

        ptr = (ptr->next)->next;
        ptr1 = (ptr1->next)->next;

    }

}

void duplicateORRemove(int loc,node* &head){
    node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        count = count + 1;
        if(count == loc){
            head = ptr;
            break;
        }
        ptr = ptr->next;
    }

    node* ptr1 = head->next;

    while(ptr1 != NULL && ptr1->next != NULL){
     node* temp = new node(ptr1->data);
     (ptr1->next)->prev = temp;
     temp->next = ptr1->next;
     ptr1->next = temp;
     temp->prev = ptr1;
     ptr1 = (ptr1->next)->next;
    }
        node* temp1 = new node(ptr1->data);
        ptr1->next = temp1;
        temp1->prev = ptr1;
        temp1->next = NULL;
}

void split(node* &head,int value,node* &L1,node* &L2){
    while(head != NULL){
        if(head->data < value){
            insert_at_end(L1,head->data);
            head = head->next;
        }else{
            insert_at_end(L2,head->data);
            head = head->next;
        }
    }
}

int main(){
node *head = NULL;
node *L1 = NULL;
node *L2 = NULL;
insert_at_start(head,10);
insert_at_start(head,13);
insert_at_start(head,15);
insert_at_start(head,14);
insert_at_start(head,13);
insert_at_start(head,11);
insert_at_start(head,12);
//duplicateORRemove(4,head);
//print(head);
//split(head,14,L1,L2);
//print(L1);
//cout<<endl;
//print(L2);
}
