Tugas 1. 
Konversi bilangan desimal, biner, dan oktal dengan memanfaatkan operasi switch-case.

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

Kode program diatas akan mencetak output ke layar dengan menggunakan fungsi printf(). Output yang dicetak berupa opsi yang ditujukan bagi pengguna untuk memilih jenis konversi yang diinginkan.

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

Operasi switch case dilibatkan dalam program ini. Setelah user memasukkan pilihan melalui keyboard maka setiap pilihan yang dipilih akan dieksekusi di dalam badan switch. Apabila user menginput pilihan 1 maka kode diatas akan dieksekusi. Kode diatas diawali dengan fungsi printf dan scanf yang akan meminta user memasukkan bilangan desimal. Kemudian setiap angka yang dimasukkan akan dikonversi ke dalam biner. Operasi diatas menggunakan perulangan for dan operator bitwise didalamnya. for( i=7; i>=0; i--) berfungsi untuk menentukan jumlah digit yang akan di hasilkan yaitu sebanyak 8 digit. Pada operasi (desimal >> i), akan menggeser digit bilangan desimal dalam biner ke kanan sebanyak i kali, lalu dioperasikan lagi dengan &1 untuk mendapatkan nilai bit paling kanan. Kemudian berlanjut hingga nilai i=0, dan hasil akhir akan dicetak. Break digunakan untuk menghentikan operasi tersebut.

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

Ketika user menginput opsi kedua maka kode program diatas yang akan dieksekusi. Kode diatas meminta inputan bilangan biner. Kemudian dieksekusi dalam badan while. Loop berawal selama angka lebih dari 0, desimal awal akan diatur menjadi 0. Setiap loop, hasil dari biner % 10 akan dikali dengan pangkat. Kemudian untuk loop selanjutnya juga demikian namun pangkatnya diperbarui dengan dikalikan 2, dan hasil dari setiap loop dijumlahkan. Setelah semua operasi loop selesai, maka hasil akhirnya akan dicetak ke layar. Break digunakan untuk menghentikan operasi ketika biner < 0.

        //konversi dari Desimal ke Octal
        case 3:
            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal); 
            printf("Bilangan %d = %o octal\n", desimal, desimal);
            break;
            
Jika user memilih opsi ketiga maka kode program diatas yang akan dieksekusi. Kode diatas meminta inputan user berupa bilangan desimal yang akan disimpan dalam variabel desimal. Kemudian akan di print ke layar dengan menggunakan identifier %o yang digunakan untuk menampilkan output ke layar berupa bilangan oktal. Perintah break dilakukan untuk menghentikan program.

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

Jika user memilih opsi keempat, maka kode diatas yang akan dieksekusi. Kode diatas meminta user untuk menginput bilangan oktal yang akan disimpan dalam variabel oktal dengan menggunakan indentifier %o. Kemudian hasil konversi akan dicetak ke layar dalam bentuk desimal dengan menggunakan indentifier %d. Break digunakan untuk menghentikan program. Kemudian, apabila user memasukkan opsi diluar 1-4, maka akan keluar dari badan switch dan akan masuk ke dalam default yang akan menampilkan output berupa pilihan yang tidak falid. Return 0 pada akhir program bermakna akhir dari program dan selesai dengan sukses. 


Tugas 2
Mengecek inputan user merupakan tahun kabisat atau bukan.

    #include<stdio.h>

    int main(){
        //menentukan tipe data
        int tahun;
        char huruf[5];

Pada awal program dimulai dengan header <stdio.h> untuk dapat menggunakan fungsi input dan output. Kemudian dilanjutkan dengan penentuan tipe data yang ingin digunakan dalam program yaitu tipe data integer untuk tahun yang berupa bilangan bulat, dan tipe data char untuk huruf yang berisi karakter. Pada variabel huruf terdapat [5] yang merupakan array yang berfunsi untuk menyimpan hanya 5 karakter.

    //input tahun
    while (1) {
        printf("Masukkan tahun (terdiri dari 4 digit): ");
        scanf("%s", &huruf);

Kode diatas menggunakan loop while yang berfungsi untuk terus meminta user menginput tahun dengan benar yaitu tahun dengan 4 digit. Lalu scanf() digunakan untuk menerima inputan dari keyboard dan akan disimpan dalam variabel huruf.

        //cek inputan berupa bilangan atau bukan
        if (sscanf(huruf, "%d", &tahun) != 1){
            printf("-----------------------------------------------------\n");
            printf("Inputan harus berupa angka yang terdiri dari 4 digit!\n");
            
            //membersihkan input yang telah disimpan sebelumnya
            while (getchar() != '\n');
            continue;
        }

Setelah memasukkan inputan, maka program akan masuk ke dalam if untuk mengecek apakah inputan berupa huruf atau bilangan. Fungsi sscanf berfungsi untuk merubah nilai yang terkandung dalam variabel huruf ke dalam bentuk integer, apabila terpenuhi maka akan menghasilkan nilai 1 dan akan melewati badan if tersebut dan lanjut mengeksekusi badan program selanjutnya. Apabila tidak terpenuhi (bernilai 0) maka akan masuk ke dalam badan if untuk mengeksekusi program didalamnya berupa output yang menyatakan untuk kembali memasukkan nilai yang valid berupa angka 4 digit. Karena if masih termasuk ke dalam badan while maka program akan tetap berulang dengan meminta user untuk menginput tahun 4 digit, while(getchar()) != 'n' berfungsi untuk membersihkan inputan yang sebelumnya disimpan dalam variabel huruf. Continue berfungsi untuk melewatkan semua iterasi dalam badan while yang berada dibawahnya sehingga program akan kembali berulang.
    
        //cek apakah tahun terdiri dari 4 digit
        if (tahun < 1000 || tahun > 9999){
            printf("---------------------------------------------------------\n");
            printf("Tahun harus terdiri dari 4 digit (berkisar antara 1000 - 9999).\n");
            continue;
        } 

        break;
    }

Setelah mengecek inputan berupa huruf atau bilangan, program akan mengecek kembali apakah inputan berupa bilangan 4 digit atau tidak. Apabila inputan berupa 4 digit maka program akan melewatkan badan if dan mengeksekusi break sehingga loop terhenti dan melanjutkan ke program berikutnya. Apabila inputan kurang atau lebih dari 4 digit maka badan if akan dieksekusi yaitu berupa output yang menyatakan agar user kembali memasukkan nilai yang benar. Continue berfungsi untuk melewati kode program yang berada di bawahnya yaitu break, sehingga break tidak dieksekusi dan program akan kembali berulang.

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

Setelah melalui program untuk mengecek inputan valid atau tidak, kode diatas akan dieksekusi yaitu kode untuk mengecek tahun yang diinput merupakan kabisat atau bukan. Statement dalam badan if merupakan syarat suatu tahun disebut sebagai tahun kabisat, yaitu tahun yang habis dibagi dengan 4 sekaligus tidak habis dibagi dengan 100, dan tahun yang habis dibagi dengan 400. Apabila salah satu syarat terpenuhi (bernilai 1) maka program akan mengeluarkan output bahwa tahun tersebut merupakan tahun kabisat. Sebaliknya, apabila tidak terpenuhi maka badan if tidak akan dieksekusi dan akan masuk ke dalam else yang akan mengeluarkan output berupa tahun tersebut bukanlah tahun kabisat. Pada akhir dari program terdapat return 0 yang menandakan program telah berhasil sukses.
