
#include <iostream>
using namespace std;
 
//Declaration of Node 
struct Node{
    string maHieu,loaiMayBay;
    int soDay,soGhe;
    Node *next;
};
 
//Declaration of Head node
struct Node *head=NULL;
 
//Inserting node at start
void node_insertion(string maHieu,string loaiMayBay, int soDay, int soGhe)
{
    struct Node *newNode=new Node;
    newNode->maHieu=maHieu;
    newNode->loaiMayBay=loaiMayBay;
    newNode->soDay=soDay;
    newNode->soGhe=soGhe;
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
        cout<<temp->loaiMayBay<<" ";
        cout<<temp->soDay*temp->soGhe<<" ";
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
    // cout<<head->hoTen<<" is removed."<<endl;
    // cout<<head->sdt<<" is removed."<<endl;
    head=head->next;
}
int main()
{
     
    show();
    string maHieu, loai;
    int soDay,soGhe;
    cout<<"Nhap ma hieu may bay"<<endl;
    cin>>maHieu;
    cout<<"Nhap ma loai may bay"<<endl;
    cin>>loai;
    cout<<"Nhap so day"<<endl;
    cin>>soDay;
    cout<<"Nhap so ghe"<<endl;
    cin>>soGhe;
    node_insertion(maHieu,loai,soDay,soGhe);
    show();
    return 0;
}