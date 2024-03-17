#include <stdio.h>

int main(){
    //menentukan tipe data
    int pilihan, desimal, biner, oktal, hasil, i;

    //tampilkan pilihan konversi yang diinginkan
    printf("Silakan pilih janis konversi\n");
    printf("-----------------------------\n");
    printf("1. Konversi desimal ke biner\n");
    printf("2. Konversi biner ke desimal\n");
    printf("3. Konversi desimal ke octal\n");
    printf("4. Konversi octal ke desimal\n");
    printf("-----------------------------\n");

    //input pilihan yang ingin dikonversi
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);
    
    //operasi konversi sesuai pilihan
    switch(pilihan){

        //konversi desimal ke biner
        case 1:
            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal);
            printf("Biner dari %d adalah = ", desimal);
            for (i = 7; i >= 0; i--) {
                hasil = (desimal >> i) & 1;
                printf("%d", hasil);
            }           
            break;

        //konversi biner ke desimal
        case 2:  
            printf("Masukkan bilangan biner: ");
            scanf("%d", &biner);
            int pangkat = 1, digit;
            hasil = 0;         
            while (biner > 0) {
                digit = biner % 10;
                hasil += digit * pangkat;
                biner /= 10;
                pangkat *= 2;
            }
            printf("Desimalnya = %d\n", hasil);
            break;

        //konversi dari Desimal ke Octal
        case 3:
            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal); 
            printf("Bilangan %d = %o octal\n", desimal, desimal);
            break;

         //konversi dari Octal ke Desimal
        case 4:
            printf("Masukkan bilangan oktal: ");
            scanf("%o", &oktal); 
            printf("Octal %o = %d dalam desimal\n", oktal, oktal);
            break;

        //pilihan tidak valid
        default:
            printf("Pilihan tidak tersedia.\n");
    }

    return 0;
}