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

    node *prev,*next;
};

node *baru,*head = NULL,*tail = NULL,*hapus,*temp,*temp2;



void buatBaru(){
	baru = new node;
	cout << "Masukan Data karyawan." <<endl;
	cout << "======================" <<endl;
	cout << "Id karyawan\t: ";cin >> baru->idKaryawan;
	cout << "Nama karyawan\t: ";cin >> baru->namaKaryawan;
	cout << "Alamat karyawan\t: ";cin >> baru->alamatKaryawan;
	cout << "Username\t: ";cin >> baru->usernameKaryawan;
	cout << "Password\t: ";cin >> baru->passwordKaryawan;
	baru->prev=NULL;
	baru->next=NULL;
} 

void tampil(){ 
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

void tambahDepan(){
	buatBaru();
	if (head==NULL)
	{
		head=baru;
		tail=baru;
	}else{
		tail->next=baru;
		baru->prev=tail;
		tail=baru;
	}
	tampil();
}

void hapusTertentu()
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


int main()
{
	int pil;
	do{
	cout << "1. Masukan Data."<<endl;
	cout << "2. Hapus Data."<<endl;
	cout << "3. Tampil Data."<<endl;
	cout << "pilih[1,2,3] : ";
	cin >> pil;
	switch(pil){
		case 1:
		tambahDepan();
		break;
		case 2:
		hapusTertentu();
		tampil();
		case 3:
		tampil();
		break;
	}
}while(pil!=4);
	cin.get();
	return 0;
}