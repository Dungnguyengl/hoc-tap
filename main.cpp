#include <iostream>
#include <iomanip>
#include <fstream>

struct subject
{
    int nSTT = 0;
    std::string stSUBJECT;
    int nso_tiet = 0;
};

class General
{
private:
    std::ofstream outfile;
    std::ifstream infile;

    void readfile();
    void writefile();

protected:
    subject SJ[21];
    int nSOMON;

public:
    General(void);
    ~General(void);
    void displaymenu();
    void add_subject();
    void delete_subject();
    void up_date_subject();
    void show_subject();
    void to_dispose_subject();
    void show_schedule();
    void export_to_file();
};

General::General()
{
    infile.open("monhoc.bat");
    readfile();
    infile.close();
}

General::~General()
{
    outfile.open("monhoc.bat");
    writefile();
    outfile.close();
}

void General::displaymenu()
{
    std::cout << "=====================MENU========================" << std::endl;
    std::cout << "1. Them mon hoc!" << std::endl;
    std::cout << "2. Xoa mon hoc!" << std::endl;
    std::cout << "3. Cap nhat mon hoc!" << std::endl;
    std::cout << "4. Xem toan bo mon hoc!" << std::endl;
    std::cout << "5. Sap xep TKB!" << std::endl;
    std::cout << "6. Xuat TKB!" << std::endl;
    std::cout << "7. Xuat TKB ra file .txt!" << std::endl;
    std::cout << std::endl;
}

void General::readfile()
{
    infile >> nSOMON;
    for (int i = 0; i < nSOMON; i++)
    {
        infile >> SJ[i].nSTT;
        infile >> SJ[i].stSUBJECT;
        infile >> SJ[i].nso_tiet;
    }
}

void General::writefile()
{
    outfile << nSOMON << std::endl;
    for (int i = 0; i < nSOMON; i++)
    {
        outfile << SJ[i].nSTT << " ";
        outfile << SJ[i].stSUBJECT << " ";
        outfile << SJ[i].nso_tiet << std::endl;
    }
}

void General::add_subject()
{
    std::cout << "=================================================" << std::endl;
    std::cout << "Nhap mon can them: ";
    std::cin >> SJ[nSOMON].stSUBJECT;
    std::cout << "\nNhap so tiet: ";
    std::cin >> SJ[nSOMON].nso_tiet;
    SJ[nSOMON].nSTT = nSOMON + 1;
    nSOMON++;
}

void General::delete_subject()
{
    int i;
    show_subject();
    std::cout << "=================================================" << std::endl;
    std::cout << "Chon mon ban muon xoa: (theo STT)";
    std::cin >> i;
    i--;

    SJ[i].nSTT = 0;
    SJ[i].stSUBJECT = "";
    SJ[i].nso_tiet = 0;

    while (i < nSOMON)
    {
        SJ[i] = SJ[i + 1];
        SJ[i].nSTT--;
        i++;
    }

    nSOMON--;

    std::cout << "DA XOA MON HOC!" << std::endl;
}

void General::up_date_subject()
{
    int i, cache;
    show_subject();
    std::cout << "=================================================" << std::endl;
    std::cout << "chon mon muon cap nhat" << std::endl;
    std::cin >> i;
again:
    std::cout << "\nNhap thong tin ban muon thay doi:" << std::endl;
    std::cout << "1. Ten mon hoc!" << std::endl;
    std::cout << "2. So tiet hoc!" << std::endl;
    std::cin >> cache;
    switch (cache)
    {
    case 1:
    {
        std::cout << "Nhap ten mon hoc moi: ";
        std::cin >> SJ[i - 1].stSUBJECT;
    }
    break;

    case 2:
    {
        std::cout << "Nhap so tiet hoc moi: ";
        std::cin >> SJ[i - 1].nso_tiet;
    }
    break;

    default:
    {
        std::cout << "Ban da nhap sai!" << std::endl;
        goto again;
    }
    break;
    }
}

void General::show_subject()
{
    std::cout << "=================================================" << std::endl;
    std::cout << std::setw(3) << "STT"
              << "|" << std::setw(10) << "MON HOC"
              << "|" << std::setw(8) << "SO TIET"
              << "|" << std::endl;
    for (int i = 0; i < nSOMON; i++)
    {
        std::cout << std::setw(3) << SJ[i].nSTT
                  << "|" << std::setw(10) << SJ[i].stSUBJECT
                  << "|" << std::setw(8) << SJ[i].nso_tiet
                  << "|" << std::endl;
    }
}

int main()
{
    char check;
    int i;
    General general;
    do
    {
        general.displaymenu();
        std::cout << "nhap 1-7:";
        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            general.add_subject();
        }
        break;
        case 2:
        {
            general.delete_subject();
        }
        break;
        case 3:
        {
            general.up_date_subject();
        }
        break;
        case 4:
        {
            general.show_subject();
        }
        break;
        default:
            std::cout << "Nhap sai!" << std::endl;
            break;
        }
        std::cout << "ban co muon tiep tuc: (y/n)";
        std::cin >> check;
    } while (check == 'y' || check == 'Y');

    return 0;
}