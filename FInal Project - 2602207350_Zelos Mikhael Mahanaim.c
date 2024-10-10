//Nama	: Zelos Mikhael Mahanaim
//NIM	: 2602207650
//FINAL PROJECT ALPROG 

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

struct absen { 
	char tgl [100];  //menentukan nilai dari variabel char tgl
	char name [100]; //menentukan nilai dari variabel char name
	char user [100]; //menentukan nilai dari variabel char user
	char tipeal [100]; //menentukan nilai dari variabel char tipeal
	char alasan [100]; //menentukan nilai dari variabel char alasan
	int abs; //menentukan nilai dari variabel integer abs
} absen[100]; 

struct usernm { 
	char username [100]; //menentukan nilai dari variabel char username
	char password [100]; //menentukan nilai dari variabel char password
} usermm[100];

int idx; //global variabel yang nantinya digunakan sebagai indeks dari setiap variabel

void entry() { //fungsi entry untuk menginput data 
	FILE *fp;
	fp = fopen("absen.txt", "a"); //membuka file dan membaca file absen.txt
	
	printf("\nMasukkan tanggal hari ini (dd/mm/yyyy)\t		: "); //display sebagai input tanggal hari ini
	scanf("%s",absen[idx].tgl); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	printf("\nMasukkan nama pengabsen\t				: "); //display sebagai input nama pengabsen
	scanf("%[^\n]",absen[idx].user); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	printf("\nMasukkan nama karyawan\t 				: "); //display sebagai input nama karyawan
	scanf("%[^\n]",absen[idx].name); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	printf("\nMasukkan jumlah absen\t 				: "); //display sebagai input jumlah absen karyawan
	scanf("%d", &absen[idx].abs); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	printf("\nMasukkan Tipe absen (Izin, Sakit, atau Alpha)\t 	: "); //display sebagai input tipe absen karyawan
	scanf("%[^\n]",absen[idx].tipeal); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	printf("\nMasukkan alasan absen karyawan\t			: "); //display sebagai input alasan karyawan mengajukan absen
	scanf("%[^\n]",absen[idx].alasan); getchar(); //memasukkan string yang diakhiri dengan \n ke dalam variabel nama di struct siakad dengan indeks ke idx
	
	fprintf(fp, "Nama Pengabsen : %s\n%s\t\t%s\t\t%d\t\t%s\t\t%s\n", absen[idx].user, absen[idx].tgl, absen[idx].name, absen[idx].abs, absen[idx].tipeal, absen[idx].alasan); //printf masing masing ke dalam file absen dengan masing masing format
	
	idx++; //lalu increment indeksnya idx agar siap untuk menyimpan value dari masing2 variabel berikutnya
	fclose(fp); //tutup file agar tidak terjadi error
}

void login(){ //fungsi login
    	char username[10], password[8];
    	int ulang = 0;
	    for(int j=0; j<3; j++){
	    printf("\t\t\t\t\t_____________________________\n");
        printf("\n");
        printf("\t\t\t\t        ======== LOGIN ADMIN ========\n");
        printf("\t\t\t\t\t_____________________________\n");
        printf("\n");
        printf("\n");
        printf("Username: "); //display sebagai input username
        scanf ( "%s", &username);
        printf("\n");
        printf("Password: "); //display sebagai input password
        fflush(stdin);
            char ch;
        int i=0;
        int x=10;
        int y=8;
        while((ch = (char) _getch()) != '\r'){
    	if (ch == 8){
    		password[i] = '\0';
    		
    		printf(" ");
    		x--;
    		i--;	
    		
		}
	
		else{
			password[i]=ch; 
			
			printf("*"); //sebagai 'sensor' password
			x++;
			i++;
		}
	}
        if ((strcmp(username,"admin")==0)&&(strcmp(password,"admin")==0)) { //untuk string compare 
        	printf("\n\n\n\n\n\n\t\t\t\t\t\tLOGIN SUCCESS!");
        	Sleep(1400); //untuk delay sementara program
        	break;
        } else {
        	ulang++;
        	if(ulang != 3){ //perintah untuk mengulang perintah
            printf("\n\nPASSWORD AND USERNAME INCORRECT"); //display untuk menjelaskan bahwa password dan username salah
            Sleep(500); //untuk delay sementara program
             system ("pause>0"); //untuk pause
        }
            else if(ulang == 3){
            	printf("\n\nSYSTEM DETECT YOU TRIED MANY TIMES TO LOGIN, THE PROGRAM WILL CLOSE IMMEDIATELY\n"); //display untuk menerangkan bahwa sudah mencoba beberapa kali 
            	Sleep(1400); //untuk delay program
            	exit(0); //untuk exit program setelah salah masukkan username dan password
			}
        }
        system("cls"); //untuk mengganti display setelah melakukan interaksi dengan void login
    }
}

void sortAndDisplay() { //sebagai fungsi untuk menyortir dan menampilkan data
	int i, j;
	struct absen temp; //membuat struct absen dengan nama temp
	for (i = 0; i < idx - 1; i++) {
    	for (j = 0; j < idx - i - 1; j++) { //looping untuk mensorting
        	if (strcoll(absen[j].name, absen[j + 1].name) > 0) {  //strcoll untuk membandingkan 2 string nama dengan indeks ke j dan selanjutnya yaitu j + 1 jika benar
            temp = absen[j];// maka value dari variabel temp akan dipindah menjadi value dari variabel absen dengan indeks ke j
            absen[j] = absen[j + 1]; // dan value dari absen dengan indeks ke j akan dipindah menjadi value dari absen dengan indeks selanjutnya yaitu j+1
            absen[j + 1] = temp; //value dari absen dengan indeks j+1 akan dipindah menjadi value dari variabel temp
        	}
    	}
	}
	printf("Pengabsen\t\tTanggal\t\tNama Karyawan\tTipe Absen\tJumlah Absen\t\tAlasan Absen\n"); //display urutan keterangan data
	for (int i = 0; i < idx; i++){ //looping
    	if (strlen(absen[i].name) >= 8) { //jika panjang string name yang ada di absen dengan indeks ke i sama tau lebih dari 8 maka lakukan yang ada di statement if jika tidak lakukan yang ada di statement else
        	printf("%s\t\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", absen[i].user, absen[i].tgl, absen[i].name, absen[i].abs, absen[i].tipeal, absen[i].alasan);
    	} else {
        	printf("%s\t\t\t%s\t%s\t\t\t%d\t\t%s\t\t%s\n", absen[i].user, absen[i].tgl, absen[i].name, absen[i].abs, absen[i].tipeal, absen[i].alasan);
    	}
	}
}

void display() { //fungsi yang berguna untuk menampilkkan data
	FILE *fp;
	fp = fopen("absen.txt", "r"); //untuk membuka dan membaca file
	
	char singleLine [150];
	while(!feof(fp)) { //untuk membaca awal sampai akhir pada data yang ditampilkan
		fgets(singleLine, 150, fp);
		puts(singleLine);
	}
	fclose(fp);	//untuk menutup file
}

void search() { //sebagai fungsi untuk mencari kata di txt file
	char line[2048];
	char prod[100];
	int found = 0;
	
	printf("\nMasukkan Nama Karyawan : "); //untuk display sebagai keterangan memasukkan nama karyawan
	scanf("%s", prod); 
	
	FILE *fp;
	fp = fopen("absen.txt", "r"); //untuk membuka dan membaca file absen
	if (fp == NULL) {
		printf("===!!!DATA ERROR, NAME CAN'T BE FOUND!!!==="); //sebagai display jika data tidak ditemukan
		return;
	}
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (strstr(line, prod) !=NULL) {
			printf("\nTanggal\t\t   Nama Karyawan\tJumlah Absen\tTipe Absen\tAlasan Absen\n"); // sebagai keterangan mengurutkan tanggal, nama karyawan, jumlah absen, tipe absen, alasan absen
			printf("%s", line);
			found = 1;
		}
	}
	if (!found) {
		printf("\n===!!!DATA CAN'T BE FOUND'!!!==="); //sebagai display jika data tidak ditemukan
	}
	fclose(fp); //untuk menutup file
}

int main () {
	int menu;
	int dis;
	char reset;
	
	login();
	system("cls"); ////untuk mengganti display setelah melakukan interaksi dengan void login
	
	do {
		printf("\t\t\t\t\t________________________________________________\n");
		printf("\n");
        printf("\t\t\t\t        ======== LIST ABSENT OF SANSAN EMPLOYEE ========\n");
        printf("\t\t\t\t\t________________________________________________\n");
        printf("\n");
        printf("\n");
        printf("\t === MAIN MENU ===\n");
		printf("\n\n|1 Untuk akses data absen karyawan       |\n\n");
		printf("|2 Untuk menampilkan data absen karyawan |\n\n");
		printf("|3 Untuk mencari data absen karyawan     |\n\n");
		printf("|4 Exit                                  |\n\n");
		printf("\nMasukkan angka pada menu diatas sesuai keperluan	: ");
		
		scanf("%d", &menu); 
		
		if (menu == 1) {
			entry(); //memanggil void entry
			printf("\n\n\t\t\t\t\t\t[Data Karyawan berhasil disimpan!]");
		} else if (menu == 2) {
			printf("\nSilahkan pilih angka 1 untuk menyortir dan menampilkan data para karyawan\n");
			printf("\nSilahkan pilih angka 2 hanya untuk menampilkan data absen karyawan\n");
			printf("\nMasukkan Pilihan Anda : ");
			
			scanf("%d", &dis);
			if (dis == 1) {
				sortAndDisplay(); //memanggil void sortanddisplay
				getchar();
			} else {
				display(); //memanggil void display
				getchar();
			}
		} else if (menu == 3) {
			search(); //memanggil void search
			getchar();
		} else if (menu == 4) {
			break; //untu keluar dari program
		}
		printf("\n\nLanjutkan untuk akses data absen karyawan? (Y/N) : ");
		scanf("%c", &reset);
		getchar();
	} while (reset == 'Y' || reset == 'y');
	printf("\n\n\t\t\t\t__________________________________________________________________\n");
	printf("\n\t\t\t\tTHANKS FOR USING THIS PROGRAM, CLICK ENTER THEN PROGRAM WILL CLOSE");
	printf("\n\t\t\t\t\tIF THERE IS A PROBLEM CALL THIS NUMBER 08181992882");
	printf("\n\t\t\t\t__________________________________________________________________\n");
	return 0; 
}
