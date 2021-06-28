#include <iostream>
#include <cstdlib>
#define MAX 10 //besar data queue
using namespace std;

//Deklarasi struct antrian
struct Queue {
	int front, rear, data[MAX];
}Q;

//cek apakah antrian penuh
bool isFull() {
	return Q.rear == MAX;
}

//cek apakah antrian kosong
bool isEmpty() {
	return Q.rear == 0;
}

//Hapus tampilan Layar
void cls() {
  cout << "Press any key to clear the screen.\n";
  system("clear");
}
//menampilkan semua data Queue
void tampil() {
  if (isEmpty()) {
    cout << "Data kosong"<<endl;
	} 
  else { 
  cout << "Berikut Data pada Queue :\n";
  	for (int i = 0; i < Q.rear; i++)
			cout << "Data ke-" << i+1 << " : " 
           << Q.data[i] << endl;
  }
}

//Menampilkan Queue
void printQueue() {
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
}

//manambahkan data ke antrian
void enqueue() {
	if (isFull())
	{
		cout << "Antrian penuh!"<<endl;
	}
	else {
		int data;
		//menambahkan data ke antrian
		cout << "Masukkan Data : ";cin >> data;
		Q.data[Q.rear] = data;
		//menempatkan tail pada elemen data terakhir yang ditambahkan
		Q.rear++;
		cout << "Data ditambahkan\n";
		printQueue();
	}
}

// mengambil data dari antrian
void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian masih kosong"<<endl;
	}
	else{
		cout << "Mengambil data \"" << Q.data[Q.front] << "\"..." << endl;
		//menggeser antrian data ke head
		for (int i = Q.front; i < Q.rear; i++)
			Q.data[i] = Q.data[i + 1];
		//menempatkan tail pada data terakhir yang digeser
		Q.rear--;
		printQueue();
	}
}

//menampilkan semua data Queue
void hitung() {
  double kecil=Q.data[0], besar=Q.data[0], total=0, rata=0;
   if (isEmpty()) {
    cout << "Data kosong"<<endl;
	} 
  else { 
  cout << "Berikut Data pada Queue :\n";
    for (int i = 0; i < Q.rear; i++) {
      cout << "Data ke-" << i+1 << " : " 
           << Q.data[i] << endl;
      if (Q.data[i] < kecil) {
        kecil = Q.data[i];
      }
      else if (Q.data[i] > besar) {
        besar = Q.data[i];
      }
      total = total + Q.data[i];
    }
    rata = total/2;
    cout << "Jumlah Total Data : " << total
         << "\nRata-rata Data : " << rata
         << "\nData terkecil : " << kecil
         << "\nData terbesar : " << besar;
  }
}
int main() 
{
	int choose;
	do
	{
		//Tampilan menu
		cout << "\n-------------------\n"
			<< "   Menu Pilihan\n"
      << "Dibuat oleh ArizkiNewbie\n"
			<< "-------------------\n"
			<< " [1] Tambah Data \n"
			<< " [2] Hapus Data\n"
      << " [3] Tampilkan Data\n"
      << " [4] Hitung Data (Total, Average, Terbesar, Terkecil)\n"
      << " [5] Hapus tampilan Layar (clear)\n"
			<< " [6] Keluar \n"
			<< "-------------------\n"
			<< "Masukkan pilihan : "; cin >> choose;
      cout << endl;
    
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
    case 3:
			tampil();
			break;
    case 4:
			hitung();
			break;
    case 5:
			cls();
			break;
		default:
      if (choose != 6)
			cout << "Pilihan tidak tersedia\n";
			break;
		}
	} while (choose !=6);
	return 0;
}