
#include <iostream>
using namespace std;
 
//Declaration of Node 
struct Node{
    string maHieu,loaiMayBay;
    int soDong,soCot;
    Node *next;
};
 
//Declaration of Head node
struct Node *head=NULL;
 
//Inserting node at start
void node_insertion(string maHieu,string loaiMayBay, int soDong, int soCot)
{
    struct Node *newNode=new Node;
    newNode->maHieu=maHieu;
    newNode->loaiMayBay=loaiMayBay;
    newNode->soDong=soDong;
    newNode->soCot=soCot;
    newNode->next=head;
    head=newNode;
}
 
//Traversing/displaying entered nodes
void show()
{
    if(head==NULL)
{
        cout<<" Linked List is empty!"<<endl;
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL)
{
        cout<<temp->maHieu<<" ";
        cout<<temp->sdt<<" ";
        cout<<temp->soDong<<" ";
        cout<<temp->soCot<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
 
//Deleting node from start
void del_Item()
{
    if(head==NULL){
        cout<<"Linked List is empty!"<<endl;
        return;
    }
    cout<<head->hoTen<<" is removed."<<endl;
    cout<<head->sdt<<" is removed."<<endl;
    head=head->next;
}
int main()
{
     
    show();
    string maHieu, loai;
    int soDong,soCot;
    cout<<"Nhap hoten va sdt"<<endl;
    cin>>hoTen;cin>>sdt;
    node_insertion(hoTen,sdt);
    show();
    return 0;
}