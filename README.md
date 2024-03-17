Tugas 1. Konversi bilangan

#include<stdio.h>

int main(){
    //menentukan tipe data
    int pilihan, desimal, biner, oktal, hasil, i;

Pada awal program dimulai dengan header <stdio.h> untuk dapat menggunakan fungsi input output. Lalu dilanjutkan dengan menentukan tipe data yang ingin dipakai dalam program yaitu tipe integer untuk semua variabel yang telibat antara lain pilihan, desimal, biner, oktal, hasil, dan variabel i. 

    //tampilkan pilihan konversi yang diinginkan
    printf("Silakan pilih janis konversi\n");
    printf("-----------------------------\n");
    printf("1. Konversi desimal ke biner\n");
    printf("2. Konversi biner ke desimal\n");
    printf("3. Konversi desimal ke octal\n");
    printf("4. Konversi octal ke desimal\n");
    printf("-----------------------------\n");

Kode program diatas akan mencetak output ke layar dengan menggunakan fungsi printf(). Output yang dicetak berupa opsi yang  ditujukan bagi pengguna untuk memilih jenis konversi yang diinginkan.

    //input pilihan yang ingin dikonversi
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

Fungsi scanf() adalah untuk menerima inputan dari keyboard, %d bertujuan untuk menerima inputan berupa integer dan akan disimpan pada variabel pilihan. Tanda & diawal variabel pilihan berfungsi sebagai alamat memori dari variabel tersebut.
    
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

Operasi switch case dilibatkan dalam program ini. Setelah user memasukkan pilihan melalui keyboard maka setiap pilihan yang dipilih akan dieksekusi di dalam badan switch. Apabila user menginput pilihan 1 maka kode diatas akan dieksekusi. Kode diatas diawali dengan fungsi printf dan scanf yang akan meminta user memasukkan bilangan desimal. Kemudian setiap angka yang dimasukkan akan dikonversi ke dalam biner. Operasi diatas menggunakan perulangan for dan operator bitwise didalamnya. for( i=7; i>=0; i--) berfungsi untuk menentukan jumlah digit yang akan di hasilkan yaitu sebanyak 8 digit. Pada operasi (desimal >> i), akan menggeser digit desimal dalam biner ke kanan sebanyak i kali, lalu dioperasikan lagi dengan &1 untuk mendapatkan nilai bit paling kanan. Kemudian berlanjut hingga nilai i=0, break digunakan untuk menghentikan operasi tersebut.

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

Ketika user menginput opsi kedua maka kode program diatas yang akan dieksekusi. Kode diatas meminta inputan bilangan biner. Kemudian dieksekusi dalam badan while. Loop berawal selama angka lebih dari 0, desimal awal akan diatur menjadi 0. Setiap loop, hasil dari biner % 10 akan dikali dengan pangkat. Kemudian untul loop selanjutnya juga demikian namun pangkatnya diperbarui dengan dikalikan 2. Setelah semua operasi loop selesai, maka hasil akhirnya akan dicetak ke layar. Break digunakan untuk menghentikan operasi.

        //konversi dari Desimal ke Octal
        case 3:
            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal); 
            printf("Bilangan %d = %o octal\n", desimal, desimal);
            break;
            
Jika user memilih opsi ketiga maka kode program diatas yang akan dieksekusi. Kode diatas meminta inputan user berupa bilangan desimal yang akan disimpan dalam variabel desimal. Kemudian akan di print ke layar dengan menggunakan identifier %o yang digunakan untuk menampilkan output ke layar berupa bilangan oktal. Perintah breal dilakukan untuk menghentikan program.

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

Jika user memilih opsi keempat, maka kode diatas yang akan dieksekusi. Kode diatas meminta user untuk menginput bilangan oktal yang akan disimpan dalam variabel oktal dengan menggunakan indentifier %o. Kemudian hasil konversi akan dicetak ke layar dalam bentuk desimal dengan menggunakan indentifier %d. Break digunakan untuk menghentikan program.
Kemudian, apabila user memasukkan opsi diluar 1-4, maka akan keluar dari badan switch dan akan masuk ke dalam default yang akan menampilkan output berupa pilihan yang tidak falid.
