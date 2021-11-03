#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "quanLyMayBay.h"
using namespace std;
const int MAX_NAME_MB = 40;
const int MAX_MA_HIEU_MB = 15;
struct MayBay
{
    string maHieu, loaiMayBay;
    int soDay, soGhe;
    MayBay *next;
};
// struct listMB
// {
//     int n;
//     MayBay *nodes[MAXMB];
// };
// typedef struct listMB LISTMB;
//Declaration of Head MayBay
struct MayBay *head = NULL;

void quanLyMayBay::menuMayBay()
{
    cout << "1. Them may bay" << endl
         << "2.Xoa may bay" << endl;
}
void quanLyMayBay::themMayBay()
{
    char maHieu[MAX_MA_HIEU_MB], loai[MAX_NAME_MB], tt;
    int soDay, soGhe;
    while (1)
    {
        cout << "Nhap ma hieu may bay" << endl;
        cin >> maHieu;
        cin.ignore();
        cout << "Nhap ma loai may bay" << endl;
        cin.getline(loai, MAX_NAME_MB);
        cout << "Nhap so day" << endl;
        cin >> soDay;
        cout << "Nhap so ghe" << endl;
        cin >> soGhe;
        addNode(maHieu, loai, soDay, soGhe);
        printf("\n\n\nBan co muon tiep tuc khong (c/k) \n\n");
        tt = getch();
        if (tt == 'k' || tt == 'K')
            break;
    }
}

void quanLyMayBay::addNode(string maHieu, string loaiMayBay, int soDay, int soGhe)
{
    struct MayBay *newMayBay = new MayBay;
    fstream MayBayFile;
    MayBayFile.open("mayBay.txt", ios::app);

    if (MayBayFile)
    {
        newMayBay->maHieu = maHieu;
        newMayBay->loaiMayBay = loaiMayBay;
        newMayBay->soDay = soDay;
        newMayBay->soGhe = soGhe;
        MayBayFile << newMayBay->maHieu << "\n"
                   << newMayBay->loaiMayBay << "\n"
                   << newMayBay->soDay << "\n"
                   << newMayBay->soGhe;
        MayBayFile << "\n\n";
    }
    newMayBay->next = head;
    head = newMayBay;
    MayBayFile.close();
}

// void quanLyMayBay::docFile()
// {
//     fstream docFile;
//     docFile.open("mayBay.txt", ios::out);
//     docFile >> "mayBay.txt";
// }
//Traversing/displaying entered nodes
void quanLyMayBay::show()
{
    if (head == NULL)
    {
        return;
    }
    struct MayBay *temp = head;
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
void quanLyMayBay::xoaMayBay()
{
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    cout << 1;
}
