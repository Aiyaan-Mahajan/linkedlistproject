#include<iostream>
using namespace std;
class Node{
public:
int value;
Node*next;
Node(int value){
this->value=value;
this->next = nullptr;
}
};
class linkedlist{
private:
int length;
Node * head;
Node * tail;
public:
linkedlist(int value){
Node * newnode = new Node(value);
head = newnode;
tail = newnode;
length =1;
}
void printlist(){
Node *temp=head;
while(temp!=nullptr){
cout<<temp->value<<endl;
temp=temp->next;
}
}

~linkedlist(){
Node*temp=head;
while(head!=nullptr)
{
    head=head->next;
    delete temp;
    temp=head;
}
}
void gethead(){
    cout<<"Head : "<<head->value<<endl;
}
void gettail(){
    cout<<"Tail : "<<tail->value<<endl;
}
void getlength(){
    cout<<"Length : "<<length<<endl;
}
void append(int value){
       Node * newnode = new Node(value);
    if(length==0){ 
        head=newnode;
        tail=newnode;
    }

   else{
    tail->next=newnode;
    tail = newnode;
   }
   length++;
}
void deletelast(){
    if(length ==0)return ;
    Node * temp=head;
    if(length==1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node*pre =head;
        while(temp->next!=nullptr){
           pre = temp;
           temp =temp->next;

        }
        tail =pre;
        tail->next =nullptr;
    }
    delete temp;
    length--;
}

void prepend(int value){
    Node * newnode = new Node(value);
if(length==0){
   head=newnode;
   tail=newnode;
}

else{
newnode->next=head;
head=newnode;
}
length++;
}

void deletefirst(){
if(length==0) return ;
Node*temp = head;
if(length==1){
    head = nullptr;
    tail = nullptr;
}
else{
head=head->next;
delete temp;
}
length--;
}
Node*get(int index){
    if(index<0 || index>=length){
      return nullptr;
    }
    else{
        Node*temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp;
    }
}

bool set(int index,int value){
Node * temp =get(index);
if(temp!=nullptr){
    temp->value=value;
    return true;
}
return false;
}

bool insert(int index,int value){
    if(index<0 || index > length){
        return false;
    }
    if(index ==0){
        prepend(value);
        return true;
    }
    if(index == length){
        append(value);
        return true;
    }
    else{
        Node * newnode= new Node(value);
        Node * temp = get(index-1);
        newnode->next=temp->next;
        temp->next = newnode;
           length++;
           return true;
    }
 
}

void deletenode(int index){
    if(index<0 || index>=length){return ;}
    if(index==0){return deletefirst();}
    if(index == length-1){return deletelast(); }
    else{
        Node * prev = get(index-1);
        Node * temp = prev->next;
        prev->next=temp->next;
        delete temp;
        length--;
    }
}

void reverse(){
Node * temp =head;
head =tail;
tail =temp;
Node * after = temp->next;
Node * before =nullptr;
for(int i =0;i<length;i++){
    after = temp->next;
    temp->next=before;
    before=temp;
    temp=after;
}
}


};

int main(){
linkedlist*mylinkedlist = new linkedlist(4);
mylinkedlist->append(7);
mylinkedlist->prepend(3);
mylinkedlist->printlist();
mylinkedlist->insert(1,12);
cout<<endl;
mylinkedlist->printlist();
// mylinkedlist->getlength();

// cout<<"value at 1 index is "<<mylinkedlist->get(1)->value<<endl;

// mylinkedlist->set(0,1);
// mylinkedlist->set(1,2);
// mylinkedlist->set(2,3);

// // mylinkedlist->deletelast();
// // mylinkedlist->deletefirst();
// // mylinkedlist->getlength();
// mylinkedlist->printlist();
cout<<endl;
mylinkedlist->reverse();
mylinkedlist->printlist();

}