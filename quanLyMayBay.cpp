#include "quanLyMayBay.h"
#include <iostream>
using namespace std;
quanLyMayBay::quanLyMayBay(){};
struct Node
{
    string maHieu, loaiMayBay;
    int soDay, soGhe;
    Node *next;
};

//Declaration of Head node
struct Node *head = NULL;
void quanLyMayBay::node_insertion(string maHieu, string loaiMayBay, int soDay, int soGhe)
{
    struct Node *newNode = new Node;
    newNode->maHieu = maHieu;
    newNode->loaiMayBay = loaiMayBay;
    newNode->soDay = soDay;
    newNode->soGhe = soGhe;
    newNode->next = head;
    head = newNode;
}

//Traversing/displaying entered nodes
void quanLyMayBay::show()
{
    if (head == NULL)
    {
        cout << " Linked List is empty!" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->maHieu << " ";
        cout << temp->loaiMayBay << " ";
        cout << temp->soDay * temp->soGhe << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Deleting node from start
void quanLyMayBay::del_Item()
{
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    cout << 1;
}
