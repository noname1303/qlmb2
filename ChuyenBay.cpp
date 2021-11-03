#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "ChuyenBay.h"
const int MAX_NOIKH_KT_CB = 40;
//#include"quanLyMayBay.h"
using namespace std;

ChuyenBay::ChuyenBay(string maHieu, string loaiMayBay, int soDay, int soGhe, string ngay, string gio, string noiKH, string noiKT) : maHieu(maHieu), loaiMayBay(loaiMayBay), soDay(soDay), soGhe(soGhe), ngay(ngay), gio(gio), noiKH(noiKH), noiKT(noiKT)
{
    ChuyenBay *head = NULL;
}

void ChuyenBay::menuCB()
{
    cout << "Vui long lua chon" << endl;
    cout << "1.Them chuyen bay" << endl
         << "2.Xoa chuyen bay" << endl;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        themCB();
        break;
    }
}
void ChuyenBay::themCB()
{
    char noiKH[MAX_NOIKH_KT_CB], noiKT[MAX_NOIKH_KT_CB], gio[MAX_NOIKH_KT_CB], tt;
    string ngay;
    int songay, soGhe;
    while (1)
    {
        cout << "Nhap noi khoi hanh" << endl;
        cin.ignore();
        cin.getline(noiKH, MAX_NOIKH_KT_CB);
        cout << "Nhap noi den" << endl;
        cin.ignore();
        cin.getline(noiKT, MAX_NOIKH_KT_CB);
        cout << "Nhap ngay" << endl;
        cin >> ngay;
        cout << "Nhap thoi gian khoi hanh " << endl;
        cin >> gio;
        insertCB(noiKH, noiKT, ngay, gio);
        printf("\n\n\nBan co muon tiep tuc khong (c/k) \n\n");
        tt = getch();
        if (tt == 'k' || tt == 'K')
            break;
    }
}

void ChuyenBay::insertCB(string noiKH, string noiKT, string ngay, string gio)
{
    struct ChuyenBay *newChuyenBay = new ChuyenBay;
    fstream ChuyenBayFile;
    ChuyenBayFile.open("chuyenBay.txt", ios::app);

    if (ChuyenBayFile)
    {
        newChuyenBay->noiKH = noiKH;
        newChuyenBay->noiKT = noiKT;
        newChuyenBay->ngay = ngay;
        newChuyenBay->gio = gio;
        ChuyenBayFile << newChuyenBay->noiKH << "\n"
                      << newChuyenBay->noiKT << "\n"
                      << newChuyenBay->ngay << "\n"
                      << newChuyenBay->gio;
        ChuyenBayFile << "\n\n";
    }
    newChuyenBay->nxt = head;
    head = newChuyenBay;
    ChuyenBayFile.close();
}
