#include<stdio.h>

int main(){
    //menentukan tipe data
    int tahun;
    char huruf[5];

    //input tahun
    while (1) {
        printf("Masukkan tahun (terdiri dari 4 digit): ");
        scanf("%s", &huruf);

        //cek inputan berupa bilangan atau bukan
        if (sscanf(huruf, "%d", &tahun) != 1){
            printf("-----------------------------------------------------\n");
            printf("Inputan harus berupa angka yang terdiri dari 4 digit!\n");
            
            //membersihkan input yang telah disimpan sebelumnya
            while (getchar() != '\n');
            continue;
        }
    
        //cek apakah tahun terdiri dari 4 digit
        if (tahun < 1000 || tahun > 9999){
            printf("---------------------------------------------------------\n");
            printf("Tahun harus terdiri dari 4 digit (berkisar antara 1000 - 9999).\n");
            continue;
        } 

        break;
    }

    //menentukan tahun kabisat atau bukan
    if ((tahun % 4 == 0) && (tahun % 100 != 0) || (tahun % 400 == 0)){
        printf("----------------------------------\n");
        printf("Tahun %d merupakan tahun kabisat", tahun);
    }
    else {
        printf("----------------------------------------\n");
        printf("Tahun %d bukan merupakan tahun kabisat", tahun);
    }

    return 0;

}