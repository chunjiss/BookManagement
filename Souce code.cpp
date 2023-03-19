#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Csach {
	private :
		string tensach;
		int tongsach , soSachMuon;
	public:
		Csach() {
			
		}
		void nhap();
		void hienthi();
		void setTen(string tensach);
		string getTen();
		void setSoSachMuon(int soSachMuon);
		int getSoSachMuon();
		void setTongSach(int tongsach);
		int getTongSach();
		int getSachCon();
		friend void ghiFile(Csach ds[], int n);
		friend void docFile(Csach ds[]);
		friend int demFile(Csach ds[]);
};
void Csach::nhap() {
	cin.ignore();
	string c;
	cout << "Nhap ten sach: "; getline(cin, c); fflush(stdin);
	setTen(c);
	int a;
	do {
		cout << "Nhap tong so sach '" << tensach << "' : "; cin >> a;
		if (a <= 0) {
			cout << "\nSo sach nhap phai lon > 0 ";
			cout << "Nhap lai: ";
			cin >> a;
		}
		
	} while (a <= 0);
	setTongSach(a);
	int b;
	do
	{
		cout << "Nhap so sach da cho muon: "; cin >> b;
		if (b < 0||b>a) {
			cout << "\nSo sach muon khong duoc < 0 hoac > tong sach";
			cout << "Nhap lai : ";
			cin >> b;
		}
	} while (b<0||b>a);
	setSoSachMuon(b);
	
}	
void Csach::hienthi() {
	cout << tensach << "\t"<<"\t" << tongsach << "\t"<<"\t" << soSachMuon << "\t"<<"\t" << getSachCon() << endl;
}
void Csach::setTen(string tensach) {
	this->tensach = tensach;
}
string Csach::getTen() {
	return tensach;
}
void Csach::setTongSach(int tongsach) {
	this->tongsach = tongsach;
}
int Csach::getTongSach() {
	return tongsach;
}
void Csach::setSoSachMuon(int soSachMuon) {
	this->soSachMuon = soSachMuon;
}
int Csach::getSoSachMuon() {
	return soSachMuon;
}
int Csach::getSachCon() {
	return tongsach - soSachMuon;
}

void ghiFile(Csach ds[], int n) {
	fstream ofs("sach.txt", ios::app);
	for (int i = 0; i < n; i++) {
		ofs << ds[i].getTen() << endl;
		ofs << ds[i].getTongSach() << endl;
		ofs << ds[i].getSoSachMuon() << endl;
		ofs << ds[i].getSachCon() << endl;
	}

	ofs.close();
	cout << "Ghi file thanh cong!";
}

void docFile(Csach ds[]) {
	fstream ifs("sach.txt", ios::in);
	int i = 0;
	while(!ifs.eof()){
		ifs.ignore();
		getline(ifs, ds[i].tensach);fflush(stdin);
		ifs >> ds[i].tongsach;
		ifs >> ds[i].soSachMuon;
		ifs >> ds[i].tongsach;
		i++;
	}
	ifs.close();
	cout << "Doc file thanh cong! \n";

}
int demFile(Csach ds[]) {
	fstream ifs("sach.txt", ios::in);
	int i = 0;
	while (!ifs.eof()) {
		ifs.ignore();
		getline(ifs, ds[i].tensach);fflush(stdin);
		ifs >> ds[i].tongsach;
		ifs >> ds[i].soSachMuon;
		ifs >> ds[i].tongsach;
		i++;
	}
	ifs.close();
	return i-1;
}
bool checkFile() {
	fstream f("sach.txt");
	if (f.fail() == true) return false;
	else return true;
}
Csach ds[100];
Csach ds1[100];

void nhapsach(Csach ds[], int n) {
    cout << endl;
    cout << "Dang nhap sach: \n";
    for (int i = 0; i < n; i++) {
        ds[i].nhap();
    }
}

void timsach(string ten, Csach ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].getTen() == ten) {
            dem++;
            ds[i].hienthi();
        }
    }
    if (dem == 0) cout << "Khong tim thay sach, sach khong ton tai! \n";
}


void sapxeptong(Csach ds[], int n) {
    Csach tg;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getTongSach() > ds[i].getTongSach()) {
                tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
        }
    }
    cout << "Sach sau khi sap xep la\n";
    for (int i = 0; i < n; i++) {
        ds[i].hienthi();
    }
}
void menu() {
    int check = 0, your, n;
    if (checkFile() == true) {
        check = 1;
        docFile(ds);
    }
    if (check == 1) {
        cout << "                         Da co du lieu ton tai  ! Ban co muon nhap them ?\n";
        cout << "                             1. Co               2. Khong                 \n";
        cin >> your;
        if (your == 1) {
             n = demFile(ds);
             int a;
    cout << "Nhap so sach muon them: "; cin >> a;
    for (int i = n; i < a + n; i++) {
        ds[i].nhap();
    }
    	n += a;
        }
        else {
        n = demFile(ds);
    }
    }
    
    else {
        cout << "Nhap so sach can them: ";
        cin >> n;
        nhapsach(ds, n);
    }
    int slection ;

    
    while (true) {
        cout << "                   DUONG THI NGOC HUYEN__________________MSV : 1351020049     \n";
        cout << "                   TRAN DINH KHANH_______________________MSV : 1351020061     \n";
        cout << "                   +----------------------------------------------------+     \n";
        cout << "                   |                GIAO DIEN QUAN LY SACH              |     \n";
        cout << "                   +----------------------------------------------------+     \n";
        cout << "                   |                                                    |     \n";
        cout << "                   |      1. Nhap sach.                                 |     \n";
        cout << "                   |      2. Hien thi danh sach.                        |     \n";
        cout << "                   |      3. Tim sach theo ten.                         |     \n";
        cout << "                   |      4. Sap xep danh sach sach.                    |     \n";
        cout << "                   |      5. Hien thi sach con trong thu vien.          |     \n";
        cout << "                   |      6. Ghi File                                   |     \n";
        cout << "                   |      0. Thoat                                      |     \n";
        cout << "                   |                                                    |     \n";
        cout << "                   +----------------------------------------------------+     \n";
        cout << "                   Nhap lua chon: "; cin >> slection;
        switch (slection)
        {
        case 1:
        {
        	int a;
            for (int i = 0; i < n; i++) {
            	cout << "Nhap so sach muon them: "; cin >> a;
                ds[i].nhap();
            }
            break;
        }
        
        case 2: 
		{
			cout << "Ten Sach " << "\t" << "   Tong Sach" << "\t" << "So Sach Muon" << "\t" << "So Sach Con" << endl;
			for (int i = 0; i < n; i++) {
                ds[i].hienthi();
            }
            break;
		
		}
            
        case 3:
        {
            cin.ignore();
                string ten;
                cout << "Nhap ten Sach can tim : "; getline(cin, ten);fflush(stdin);
            timsach(ten, ds, n);
            break;
        }
            
        case 4:
        {
			sapxeptong(ds, n);
            break;
        }
           
        case 5:
        {
			cout << "Hien thi so sach con trong thu vien: \n";
            for (int i = 0; i < n; i++) {
                if (ds[i].getSachCon() > 0) ds[i].hienthi();
            }
            break;
        }
        case 6:
        {
            ghiFile(ds, n);
            break;
        }
        case 0: {
            exit(0);
        }
        default:
            cout << "Chon lai: ";
            break;
        }

    }
    
}

int main()
{

    menu();

    return 0;
}

