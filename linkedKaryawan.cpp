#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct node
{
	int idKaryawan;
    string namaKaryawan;
    string alamatKaryawan;
    string usernameKaryawan;
    string passwordKaryawan;
    char jenkelKaryawan;

    node *next;
};

node *baru,*head = NULL,*tail = NULL,*hapus,*temp;



void buatBaru(){
	baru = new node;
	cout << "Masukan Data karyawan." <<endl;
	cout << "======================" <<endl;
	cout << "Id karyawan\t: ";cin >> baru->idKaryawan;
	cout << "Nama karyawan\t: ";cin >> baru->namaKaryawan;
	cout << "Alamat karyawan\t: ";cin >> baru->alamatKaryawan;
	cout << "Username\t: ";cin >> baru->usernameKaryawan;
	cout << "Password\t: ";cin >> baru->passwordKaryawan; 
	baru->next=NULL; 
} 

void tampilData(){ 
	cout << "\nDaftar karyawan."<<endl;
	cout << "================"<<endl;
	if (head==NULL)
	{
		cout << "Data kosong." <<endl;
	}else{
		temp = head; 
		while(temp!=NULL){
			cout << "Id karyawan\t: " << temp->idKaryawan <<endl;
			cout << "Nama karyawan\t: " << temp->namaKaryawan <<endl;
			cout << "Alamat karyawan\t:" << temp->alamatKaryawan <<endl;
			cout << "Username\t: " << temp->usernameKaryawan <<endl;
			cout << "Password\t: " << temp->passwordKaryawan <<endl;
			cout << "\n";
			temp=temp->next; 
		}
	}
	getch();
}

void tambahData(){
	buatBaru();
	if (head==NULL)
	{
		head=baru;
		tail=baru;
	}else{
		tail->next=baru; 
		tail=baru;
	}
	tampilData();
}

void hapusData()
{
    int jumDat,delPos,poshapus;
    node *hapus,*temp;
    if(head != NULL){
        cout << "Akan dihapus pada data ke : ";
        cin >> delPos;
        jumDat=1;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            jumDat++;
        }
        if((delPos<1)||(delPos>jumDat)){
            cout << "Belum ada data yang masuk";
        }else{
        temp=head;
        poshapus=1;
        while(poshapus<(delPos-1)){
            temp=temp->next;
            poshapus++;
        }
        hapus=temp->next;
        temp->next=hapus->next;
        delete hapus;
        }
    }else{
        cout<<"Data masih kosong";
    }
}

void cariData(){
	temp = head;
	int cariId;
	cout << "\nId yang dicari\t: ";
	cin >> cariId;
	int find = false;
	if (head != NULL)
	{
		while(temp!=NULL)
		{
			temp->idKaryawan;
			if (cariId == temp->idKaryawan)
			{
				cout << "\nData ditemukan" <<endl;
				cout << "Id karyawan\t: " << temp->idKaryawan <<endl;
				cout << "Nama karyawan\t: " << temp->namaKaryawan <<endl;
				cout << "Alamat karyawan\t:" << temp->alamatKaryawan <<endl;
				cout << "Username\t: " << temp->usernameKaryawan <<endl;
				cout << "Password\t: " << temp->passwordKaryawan <<endl;
				cout << "\n";
				find = true;
			}
			temp=temp->next;
		}
		if (find==false)
		{
			cout << "\nData tidak ditemukan";
		}
	}
	else{
		cout << "\nData masih kosong";
	}
}

void loginKaryawan(){
	temp = head;
	string user,pass;
	cout << "Username : ";cin >> user;
	cout << "Password : ";cin >> pass;
	bool find = false;
	if (head != NULL)
	{
		temp->usernameKaryawan;
		temp->passwordKaryawan;
		while(temp!=NULL)
		{
			if (user == temp->usernameKaryawan && pass == temp->passwordKaryawan)
			{
				cout << "berhasil login.";
				find = true;
			}
			temp=temp->next;
		}
		if (find == false)
		{
			cout << "\nPassword/Username salah.\n";
		}
	}else{
		cout << "\nbelum ada data masuk.\n";
	}
}

int main()
{
	int pil;
	do{
	cout << "\n1. Masukan Data."<<endl;
	cout << "2. Hapus Data."<<endl;
	cout << "3. Tampil Data."<<endl;
	cout << "4. Cari Data." <<endl;
	cout << "5. Login Karyawan." <<endl;
	cout << "pilih[1,2,3,4,5] : ";
	cin >> pil;
	switch(pil){
		case 1:
		tambahData();
		break;
		case 2:
		hapusData();
		tampilData();
		case 3:
		tampilData();
		break;
		case 4:
		cariData();
		cin.get();
		break;
		case 5:
		loginKaryawan();
		break;
	}
}while(pil!=6);
	cin.get();
	return 0;
}
