
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coffeeshop {
	char tgl [100];
	char name [100];
	char type [100];
	char user [100];
	char makanminum [100];
	int quantity;
	float cost;
	float total;
} sales[100];

int idx;

void entry() {
	FILE *fp;
	fp = fopen("sales.txt", "a");
	
	printf("\nMasukkan Tanggal Transaksi dengan Format dd/mm/yyyy : ");
	scanf("%s", sales[idx].tgl); getchar();
	
	printf("\nMasukkan Nama Pembeli Coffee Shop : ");
	scanf("%[^\n]", sales[idx].name); getchar();
	
	printf("\nMasukkan Tipe Minuman atau Makanan yang Dipesan : ");
	scanf("%[^\n]", sales[idx].type); getchar();
	
	printf("\nMasukkan Nama Minuman atau Makanan yang Dipesan : ");
	scanf("%[^\n]", sales[idx].user);getchar();
	
	printf("\nMasukkan Jumlah Minuman atau Makanan yang Dipesan : ");
	scanf("%d", &sales[idx].quantity); getchar();
	
	printf("\nMasukkan Harga Minuman atau Makanan yang Dipesan : ");
	scanf("%f", &sales[idx].cost); getchar();
	
	printf("\nMasukkan Total Pembayaran Minuman atau Makanan yang Dipesan : ");
	scanf("%f", &sales[idx].total); getchar();
	
	fprintf(fp, "%s\t%s\t\t%s\t\t%s\t\t%d\t%.0f\t\t%.0f\n", sales[idx].tgl, sales[idx].name, sales[idx].type, sales[idx].user, sales[idx].quantity, sales[idx].cost, sales[idx].total);
	
	idx++;
	fclose(fp);
}

void sortAndDisplay() {
	int i, j;
	struct coffeeshop temp;
	for (i = 0; i < idx - i - 1;j++ ) {
		for (j = 0; j < idx - i - 1; j++) {
			if (strcoll(sales[j].name, sales[j + 1].name) > 0) {
				temp = sales [j];
				sales [j] = sales [j + 1];
				sales [j + 1] = temp;
			}
		}
	}
printf("\nTanggal:\t\tNama Pembeli\tJenis Makanan atau Minuman yang Dipesan\tNama Makanan atau Minuman yang Dipesan\tJumlah Makanan atau Minuman yang Dipesan\tHarga Makanan atau Minuman yang Dipesan\tTotal Harga Makanan atau Minuman yang Dipesan\n");
for (int i = 0; i < idx; i++)
	{
		if (strlen(sales[i].name) >= 9)
		{
			printf("%s\t\t%s\t\t%s\t\t%s\t%d\t\t%.0f\t\t%.0f\n", sales[i].tgl, sales[i].name, sales[i].type, sales[i].user, sales[i].quantity, sales[i].cost, sales[i].total);
		}
		else {
			printf("%s\t\t%s\t\t%s\t\t%s\t%d\t\t%.0f\t\t%.0f\n", sales[i].tgl, sales[i].name, sales[i].type, sales[i].user, sales[i].quantity, sales[i].cost, sales[i].total);
		}
	}
}

void display() {
	printf("\nTanggal:\t\tNama Pembeli\tJenis Makanan atau Minuman yang Dipesan\tNama Makanan atau Minuman yang Dipesan\tJumlah Makanan atau Minuman yang Dipesan\tHarga Makanan atau Minuman yang Dipesan\tTotal Harga Makanan atau Minuman yang Dipesan\n");
	
	for (int i = 0; i < idx; i++)
	{
		if (strlen(sales[i].name) >= 9)
		{
			printf("%s\t\t%s\t\t%s\t\t%s\t%d\t\t%.0f\t\t%.0f\n", sales[i].tgl, sales[i].name, sales[i].type, sales[i].user, sales[i].quantity, sales[i].cost, sales[i].total);
		}
		else {
			printf("%s\t\t%s\t\t%s\t\t%s\t%d\t\t%.0f\t\t%.0f\n", sales[i].tgl, sales[i].name, sales[i].type, sales[i].user, sales[i].quantity, sales[i].cost, sales[i].total);
		}	
	}
}

void search()
{
	char line [2048];
	char prod [100];
	
	printf("\nMasukkan Nama Pembeli : ");
	scanf("%s", prod);
	
	FILE *fp;
	fp = fopen ("sales.txt", "r");
	if (fp == NULL){
		printf("===!!!ERROR OPENING FILE!!!===");
	}
	
	while (fgets(line, sizeof(line),fp)!=NULL) {
		if(strstr(line, prod)!= NULL){
			printf("\nTanggal\t\tNama Pembeli\t\tJenis Makanan atau Minuman yang Dipesan\t\tNama Makanan atau Minuman yang Dipesan\t\tJumlah Makanan atau Minuman yang Dipesan\tHarga Makanan atau Minuman yang Dipesan\tTotal Harga Makanan atau Minuman yang Dipesan\n");
			printf ("%s", line);
		}
		else {
			printf("===!!!Makanan atau Minuman Tidak Ditemukan!!!===");
			break;
		}
	}
	
}

int main(){
    
    int menu;
    char reset;
    int dis;
    
    do{
        printf("============================================\nWelcome to the Coffee Shop Management System\n============================================\n\n");
        printf("[1 untuk memasukkan data]\n\n");
        printf("[2 untuk menampilkan data]\n\n");
        printf("[3 untuk mencari data]\n\n");
        printf("[4 untuk Exit]\n\n");
        printf("\nMasukan Pilihan Anda : ");
        
        scanf("%d", &menu);
        
        if (menu == 1){
            
            entry();
            printf("\n\n[Data sudah tertulis!]");
            
        } else if (menu == 2){
            printf("\nSilahkan pilih angka 1 untuk menyortir dan menampilkan data\n");
            printf("Silahkan pilih angka 2 untuk hanya menampilkan data\n");
            printf("\nMasukan Pilihan Anda: ");
            
            scanf("%d", &dis);
            
            if (dis == 1){
                sortAndDisplay();
            } else{
                display();
            }
        } else if (menu == 3){
            
            search();
            
        }
        else if (menu == 4){
            break;
        }
        
        printf("\n\nWould You like to continue? (Y/N): ");
        scanf("%c", &reset);
        
    } while (reset == 'Y' || reset == 'y');
    
    
    
    return 0;
    
}

