#include <iostream>
#include <string>
#include <vector>
using namespace std;

class buku {
public:
	string nama;
	vector<class pengarang*> daftar_pengarang;
	buku(string pNama) :nama(pNama) {}
	void tambahpengarang(class pengarang*);
	void cetakpengarang();
};

void buku::tambahpengarang(class pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void buku::cetakpengarang() {
	cout << "Daftar pengarang pada penerbit \" " << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

class pengarang {
public:
	string nama;
	vector<class buku*> daftar_buku;
	vector<class penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {	}
	void tambahbuku(class buku*);
	void cetakbuku();
	void tambahpenerbit(class penerbit*);
	void cetakpenerbit();
};

void pengarang::tambahbuku(class buku* pBuku){
	daftar_buku.push_back(pBuku);
}

void pengarang::cetakbuku() {
	cout << "Daftar buku yang dikarang \" " << this->nama << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahpenerbit(class penerbit* pPenerbit){
	daftar_penerbit.push_back(pPenerbit);
}

void pengarang::cetakpenerbit() {
	cout << "Daftar penerbit yang diikuti \" " << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

class penerbit {
public:
	string nama;
	vector<class pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {}
	void tambahpengarang(class pengarang*);
	void cetakpengarang();
};

void penerbit::tambahpengarang(class pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakpengarang() {
	cout << "Daftar pengarang pada penerbit \" " << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Asroni");
	pengarang* varPengarang4 = new pengarang("Giga");
	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemrograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	varPenerbit1->tambahpengarang(varPengarang1); //Gama Press
	varPenerbit1->tambahpengarang(varPengarang2);
	varPenerbit1->tambahpengarang(varPengarang4);
	varPenerbit2->tambahpengarang(varPengarang3); //Intan Pariwara
	varPenerbit2->tambahpengarang(varPengarang4);

	varPengarang4->tambahpenerbit(varPenerbit1); //Giga
	varPengarang4->tambahpenerbit(varPenerbit2);

	varPengarang1->tambahbuku(varBuku1); //Joko
	varPengarang1->tambahbuku(varBuku2);

	varPengarang2->tambahbuku(varBuku3); //Lia

	varPengarang3->tambahbuku(varBuku4); //Asroni

	varPengarang4->tambahbuku(varBuku5); //Giga
	varPengarang4->tambahbuku(varBuku6);

	varPenerbit1->cetakpengarang();
	varPenerbit2->cetakpengarang();
	varPengarang4->cetakpenerbit();
	varPengarang1->cetakbuku();
	varPengarang2->cetakbuku();
	varPengarang3->cetakbuku();
	varPengarang4->cetakbuku();

	return 0;
}