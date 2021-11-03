#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "MayBay.h"
#include "menu.h"
using namespace std;
const int MAX_NAME_MB = 40;
const int MAX_MA_HIEU_MB = 15;

MayBay::MayBay(string maHieu, string loaiMayBay, int soDay, int soGhe) : maHieu(maHieu), loaiMayBay(loaiMayBay), soDay(soDay), soGhe(soGhe)
{
    MayBay *head = NULL;
}

void MayBay::menuMayBay()
{
    int option;
    system("cls");

    cout << "====== Lua chon =====" << endl;
    cout << "1. Them may bay" << endl
         << "2. Xoa may bay" << endl
         << "3. In danh sach may bay" << endl
         << "4. Back" << endl;
    cout << "===================" << endl;

    cin >> option;
    switch (option)
    {
    case 1:
        themMayBay();
        break;
    case 2:
        xoaMayBay();
        break;
    case 3:
        show();
        break;
    case 4:
    {
        Menu menu;
        menu.HienThiMenu();
    }
    default:
        cout << "Vui long nhap dung" << endl;
        break;
    }
}
void MayBay::themMayBay()
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
        {
            Menu menu;
            menu.HienThiMenu();
        }
    }
}

void MayBay::addNode(string maHieu, string loaiMayBay, int soDay, int soGhe)
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
        MayBayFile << "\n0\n";
    }
    newMayBay->next = head;
    head = newMayBay;
    MayBayFile.close();
}

// void MayBay::docFile()
// {
//     fstream docFile;
//     docFile.open("mayBay.txt", ios::out);
//     docFile >> "mayBay.txt";
// }
//Traversing/displaying entered nodes
void MayBay::show()
{
    if (head == NULL)
    {
        return;
        cout << "head la null";
    }
    struct MayBay *temp = head;
    while (temp != NULL)
    {
        cout << temp->maHieu << " ";
        cout << temp->loaiMayBay << " ";
        cout << temp->soDay * temp->soGhe << " ";
        temp = temp->next;
        cout << "hello";
    }
    cout << endl;
}

//Deleting node from start
void MayBay::xoaMayBay()
{
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    cout << 1;
}
void MayBay::docFile()
{
    fstream docFile;
    docFile.open("mayBay.txt", ios::in);
    {
        string line;
        while (getline(docFile, line))
        {
            cout << line << '\t';
            if (line == "")
            {
                cout << endl;
            }
        }
    }
}