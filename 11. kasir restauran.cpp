//Nama anggota kelompok:
// Bagus Budi Satoto   (21.11.4076)
// Chessa Aninditya Anugrah Putranto   (21.11.4098)
// Tegar Tri Putrawana    (21.11.4111)
// Shera Alice Ayutri     (21.11.4085)
// Mohammad Rangga Pangestu   (21.11.4052)

#include <iostream>  //header file
using namespace std; // mengatur code ke dalam grup logis agar baris tidak perlu ditambahkan std

int pilihan, totalPaket, banyak, hasil = 0; 		// deklarasi variabel integer
char menu[20], harga, pilihanPaket, yesNo, jawab; // deklarasi var character
string nama;  								 // deklarasi var string
int diskon = 10;                            // deklarasi var integer
int x = 0;			

/**
 ** Membuat deklarasi fungsi tanpa kode program didalamnya.
 ** Bisa dikatakan sebagai kontrak
 */
bool ulang();
bool paketAyam();
bool paketNasgor();
bool paketIkbar();
void pembayaran();

int main()
{
    /**
     * Deklarasi array dari total pesanan dengan tipe data int.
     * Minimal size harus 1 makanya x+1
     */
    int totalSeluruhPesanan[x + 1];
awal:
	system ("color f1");
						cout<<"====================================== DMR =============================="<<endl;
		cout<<"============================ Demen Makan Resto =========================="<<endl;
		cout<<"==================== Cabang Yogyakarta || Jagonya Ayam ! ================"<<endl;
		cout<<endl;
		cout<<"Masukkan Nama Anda : " ; 
		getline(cin,nama);  // agar dapat menerima inputan spasi
		
    do
    {
    	system ("color f1");
		cout<<"Pilihan menu yang tersedia---"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"|	[1] Ayam goreng                				         |"   <<endl;
		cout<<"|	[2] Nasi goreng                          		  	 |"   <<endl;
		cout<<"|	[3] Masakan ikan		                            	 |"   <<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout << "Masukan Menu Yang Di Pilih : ";
        cin >> pilihan;
           cout
            << "==================================================================="
            << endl
            << endl;
            
        switch (pilihan)
        {
        case 1: // Ayam goreng
            cout << "List Paket Ayam Goreng" << endl;
            cout << "A. Ayam Goreng Sambal Bawang : Rp.13.000,00" << endl;
            cout << "B. Ayam Goreng Kremes        : Rp.15.000,00" << endl;
            cout << "C. Ayam Goreng Extra         : Rp.20.000,00" << endl;

            cout << "Masukkan Pilihan Paket : ";
            cin >> pilihanPaket;

            /**
             * Fungsi untuk menentukan harga ayam
             */
            if (paketAyam())
            {
                cout << "Berapa Banyak Pesanan? ";
                cin >> banyak;

                /**
                 * Tambahkan harga paket * banyak kedalam array total pesanan
                 */
                totalSeluruhPesanan[x] = totalPaket * banyak;
                x++; // tambah 1 supaya di looping berikutnya size array bertambah

                cout << "Apakah Ada Pesanan Lainnya (Y/N)?";
                cin >> yesNo;
            }
            else
            {
                if (ulang())
                {
                    goto awal;
                    break;
                }

                yesNo = 'n';
            }
            break;
        case 2: // nasi goreng
            cout << "List Paket Nasi Goreng" << endl;
            cout << "A. Nasi Goreng Spesial : Rp.15.000,00" << endl;
            cout << "B. Nasi Goreng Bakso   : Rp.13.000,00" << endl;
            cout << "C. Nasi Goreng Jumbo   : Rp.17.000,00" << endl;

            cout << "Masukkan Pilihan Paket : ";
            cin >> pilihanPaket;
            ;

            /**
             * Fungsi untuk menentukan harga nasi goreng
             */
            if (paketNasgor())
            {
                cout << "Berapa Banyak Pesanan? ";
                cin >> banyak;

                /**
                 * Tambahkan harga paket * banyak kedalam array total pesanan
                 */
                totalSeluruhPesanan[x] = totalPaket * banyak;
                x++; // tambah 1 supaya di looping berikutnya size array bertambah

                cout << "Apakah Ada Pesanan Lainnya (Y/N)?";
                cin >> yesNo;
            }
            else
            {
                if (ulang())
                {
                    goto awal;
                    break;
                }

                yesNo = 'n';
            }
            break;
        case 3: // masakan ikan
            cout << "List Paket Masakan Ikan" << endl;
            cout << "A. Ikan Bakar Madu Pedas : Rp.17.000,00" << endl;
            cout << "B. Ikan Bakar Spesial    : Rp.18.000,00" << endl;
            cout << "C. Ikan Bakar Pedas      : Rp.15.000,00" << endl;

            cout << "Masukkan Pilihan Paket : ";
            cin >> pilihanPaket;

            /**
             * Fungsi untuk menentukan harga ikan bakar
             */
            if (paketIkbar())
            {
                cout << "Berapa Banyak Pesanan? ";
                cin >> banyak;

                /**
                 * Tambahkan harga paket * banyak kedalam array total pesanan
                 */
                totalSeluruhPesanan[x] = totalPaket * banyak;
                x++; // tambah 1 supaya di looping berikutnya size array bertambah

                cout << "Apakah Ada Pesanan Lainnya (Y/N)?";
                cin >> yesNo;
            }
            else
            {
                if (ulang())
                {
                    goto awal;
                    break;
                }

                yesNo = 'n';
            }

            break;

        default: // apabila pilihan tidak tersedia
            cout << "Pilihan tidak tersedia!";

            cout << "\nKembali ke awal?";
            cin >> jawab;
            if (jawab == 'y' || jawab == 'Y')
            {
                system("CLS"); // membersihkan tampilan
                goto awal;
            }
            else
            {
                cout << "Terima Kasih!";
            }
        }

    } while (yesNo == 'Y' || yesNo == 'y');

    cout << endl;

    if (yesNo == 'n' || yesNo == 'N')
    {
        /**
         * Menghitung total harga pesanan
         */
        for (int i = 0; i < x; i++)
        {
            hasil = hasil + totalSeluruhPesanan[i]; // jumlahkan hasil pesanan
        }
        pembayaran();
    }
}

void pembayaran()
{

		cout << "-------------------------------------------------------" << endl;
		cout << "|  	          Demen Makan Resto                      |" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "\tNama Pemesan          : "	<< nama     <<endl;
    	cout << "\tTotal Pesanan         : " << hasil << endl;
    	cout << "\tDiskon 10% 	      : " << hasil / diskon << endl;
    	cout << "\tTotal Pembayaran      : Rp " << hasil - (hasil / diskon) << endl;
    	cout << endl;
    	cout << "		Terima kasih telah Memesan Makanan di DMR"<<endl;	
		cout << "			Selamat Menikmati"<<endl;
		}
bool paketIkbar()
{
    if (pilihanPaket == 'A' || pilihanPaket == 'a')
    {
        totalPaket = 17000;
        return true;
    }
    else if (pilihanPaket == 'B' || pilihanPaket == 'b')
    {
        totalPaket = 18000;
        return true;
    }
    else if (pilihanPaket == 'C' || pilihanPaket == 'c')
    {
        totalPaket = 15000;
        return true;
    }
    else
    {
        cout << "Paket Tidak Tersedia" << endl;
        return false;
    }
}

bool paketNasgor()
{
    if (pilihanPaket == 'A' || pilihanPaket == 'a')
    {
        totalPaket = 15000;
        return true;
    }
    else if (pilihanPaket == 'B' || pilihanPaket == 'b')
    {
        totalPaket = 13000;
        return true;
    }
    else if (pilihanPaket == 'C' || pilihanPaket == 'c')
    {
        totalPaket = 17000;
        return true;
    }
    else
    {
        cout << "Paket Tidak Tersedia" << endl;
        return false;
    }
}

bool paketAyam()
{
    if (pilihanPaket == 'A' || pilihanPaket == 'a')
    {
        totalPaket = 13000;
        return true;
    }
    else if (pilihanPaket == 'B' || pilihanPaket == 'b')
    {
        totalPaket = 15000;
        return true;
    }
    else if (pilihanPaket == 'C' || pilihanPaket == 'c')
    {
        totalPaket = 20000;
        return true;
    }
    else
    {
        cout << "Paket Tidak Tersedia" << endl;
        return false;
    }
}

bool ulang()
{
    string diulang;
    cout << endl
         << "INGIN MENGULANGI LAGI ? " << endl;
    cout << "YES/NO : ";
    cin >> diulang;

    if (diulang == "yes" or diulang == "YES")
    {
        return true;
    }
    else if (diulang == "no" or diulang == "NO")
    {
        return false;
    }
    else
    {
        cout << "Pilihan salah silahkan pilih opsi yang lain" << endl;
        return ulang();
    }
}
