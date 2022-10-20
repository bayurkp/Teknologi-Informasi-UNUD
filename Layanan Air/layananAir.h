#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ADM_RT 10000.00 //Biaya administrasi untuk kelompok rumah tangga
#define ADM_U 12500.00 //Biaya administrasi untuk kelompok usaha
#define BPM_RT 5000.00 //Biaya pemeliharaan meteran untuk kelompok rumah tangga
#define BPM_U 7500.00 //Biaya pemeliharaan meteran untuk usaha
#define JATUH_TEMPO 25 //Jatuh tempo tanggal 25 setiap bulannya
#define DENDA 25000.00 //Diberikan denda sebesar Rp 25.000 jika lewat jatuh tempo
#define BOLD "\e[1m"
#define BOLD_END "\e[m"

//deklarasi prosedur dan fungsi
float cekInput();
void intro(),
    menuKelompok(),
    menuRumahTangga(),
    menuUsaha(),
     d1(),  d2(),  d3(),  d4(), d5(),
    d11(), d12(), d13(), d14(),
    d21(), d22(), d23(), d24(),
    d31(), d32(), d33(), d34(),
    d41(), d42(), d43(), d44(),
    d51(), d52(), d53(), d54(),

     e1(),  e2(),  e3(), 
    e11(), e12(), e13(), e14(),
    e21(), e22(), e23(), e24(),
    e31(), e32(), e33(), e34(),
    ulangProgram();

//validasi input
float cekInput() {
    char input[100];
    int a = 0,
        negatif = 0,
        koma = 0,
        belakang = 0,
        deret = 0,
        depan = 0,
        salah = 0;
    float nolKoma = 1,
        nilaiInput;

    scanf("%[^\n]", input);
    getchar();

    if(input[a] == '\0') {
        salah=1;
    }
    while (input[a] != '\0') {
        if (input[a] == '-') {
            negatif++;
            if (a > 0 || negatif == 2) {
                salah = 1;
                input[a] = '\0';
            }
            if (!(input[a+1] >= '0' && input[a+1] <= '9')) {
                salah = 1;
                input[a] = '\0';
            }
            a++;
        } else if(input[a] == '.'){
            koma++;
            if (input[0] == '.' || input[a+1] == '\0' || koma > 1) {
                salah = 1;
                input[a]='\0';
            }
            a++;
        } else if (input[a] >= '0' && input[a] <= '9'){
            if (koma == 1){
                belakang = (belakang * 10) + (input[a] - 48);
                deret++;
                a++;
            } else {
                depan = (depan * 10) + (input[a] - 48);
                a++;
            }
        } else {
            salah = 1;
            input[a] = '\0';
        }
    }
    if (koma == 1) {
        for(int i = 0; i < deret; i++){
            nolKoma = nolKoma / 10;
        }
        nilaiInput = belakang * nolKoma + depan;
    } else {
        nilaiInput = depan;
    }
    if (negatif == 1) {
        nilaiInput = nilaiInput - (nilaiInput * 2);
    }
    if (salah == 1) {
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        printf("|| ");
        return cekInput();
    } else {
        return nilaiInput;
    }
}

void ulangProgram()
{
    int pilihan, menu;
    printf("\n\n|| ================================================== ||\n");
    printf("||    Apakah Anda ingin menjalankan program lagi?     ||\n");
    printf("|| ================================================== ||\n");
    printf("|| [1] Ya, saya ingin menjalankan program lagi.       ||\n");
    printf("|| [2] Tidak, saya ingin keluar dari program.         ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda : ");
    pilihan = cekInput();
    switch (pilihan) {
    case 1:
        system("clear");
        intro();
    case 2:
        system("clear");
        break;
    default :
        printf("|| ================================================== ||\n");
        printf("||        Maaf, input Anda salah. Mohon ulangi!       ||\n");
        printf("|| ================================================== ||\n\n");
        ulangProgram();
    }
}

//intro
void intro()
{
    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||        \"Air Jernih, Bersih, dan Penuh Kasih\"       ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Halo, perkenalkan saya Saber yang akan menjadi     ||\n");
    printf("|| pemandu untuk mengoperasikan program ini.          ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Oleh :                                             ||\n");
    printf("|| Ni Putu Andri Krisnantari                          ||\n");
    printf("|| Bayu Rizky Kurnia Pratama                          ||\n");
    printf("|| ================================================== ||\n");
    printf("||            Tekan enter untuk melanjutkan!          ||\n");
    printf("|| ================================================== ||");
    getchar();
    system("clear");
    menuKelompok();
}

//input pilihan kelompok

void menuKelompok() //menu usaha
{
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ KELOMPOK ~                    ||\n");
    printf("||             Kelompok fasilitas air Anda.           ||\n");
    printf("|| ================================================== ||\n");
    printf("|| [1] RT, saya adalah kelompok rumah tangga          ||\n");
    printf("|| [2] Usaha, saya adalah kelompok usaha              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    
    switch (kode)
    {
        case 1:
            menuRumahTangga();
            break;
        case 2:
            //menuUsaha();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            menuKelompok();
            break;
    }
}

void menuRumahTangga()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                 ~ RUMAH TANGGA ~                   ||\n");
    printf("||   Lebar jalan termasuk got dan berm serta persil   ||\n");
    printf("||                 dari rumah Anda.                   ||\n");
    printf("|| ================================================== ||\n");
    printf("|| [1] Lebar jalan 0 meter - 3,99 meter               ||\n");
    printf("|| [2] Lebar jalan 4 meter - 6,99 meter               ||\n");
    printf("|| [3] Lebar jalan 7 meter - 10 meter                 ||\n");
    printf("|| [4] Lebar jalan 10 meter keatas                    ||\n");
    printf("|| [5] Rumah sekaligus toko atau kios                 ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    
    switch (kode)
    {
        case 1:
            d1();
            break;
        case 2:
            d2();
            break;
        case 3:
            d3();
            break;
        case 4:
            d4();
            break;
        case 5:
            d5();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            menuRumahTangga();
            break;
    }
}

void menuUsaha()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                 ~ RUMAH TANGGA ~                   ||\n");
    printf("||   Lebar jalan termasuk got dan berm serta persil   ||\n");
    printf("||                 dari rumah Anda.                   ||\n");
    printf("|| ================================================== ||\n");
    printf("|| [1] Lebar jalan 0 meter - 6,99 meter               ||\n");
    printf("|| [2] Lebar jalan 7 meter - 10 meter                 ||\n");
    printf("|| [3] Lebar jalan 10 meter keatas                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    
    switch (kode)
    {
        case 1:
            e1();
            break;
        case 2:
            e2();
            break;
        case 3:
            e3();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            menuUsaha();
            break;
    }
}

void d1() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            d11();
            break;
        case 2:
            d12();
            break;
        case 3:
            d13();
            break;
        case 4:
            d14();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            d1();
            break;
    }
}

void d2() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            d21();
            break;
        case 2:
            d22();
            break;
        case 3:
            d23();
            break;
        case 4:
            d24();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            d2();
            break;
    }
}

void d3() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            d31();
            break;
        case 2:
            d32();
            break;
        case 3:
            d33();
            break;
        case 4:
            d34();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            d3();
            break;
    }
}

void d4() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            d41();
            break;
        case 2:
            d42();
            break;
        case 3:
            d43();
            break;
        case 4:
            d44();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            d4();
            break;
    }
}

void d5() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            d51();
            break;
        case 2:
            d52();
            break;
        case 3:
            d53();
            break;
        case 4:
            d54();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            d5();
            break;
    }
}

void d11()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 17800;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 2060 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 5880 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d11();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D1 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d12()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 20600;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 2340 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 5940 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d12();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D1 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d13()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 63400;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9200 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 9600 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d13();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D1 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d14()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 64200;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9350 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 9650 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d14();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D1 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d21()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 23400;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 2620 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6000 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d21();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D2 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d22()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 26200;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 2900 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6060 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d22();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D2 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d23()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 64900;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9500 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 9800 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d23();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D2 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d24()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 65700;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9650 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 9950 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d24();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D2 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d31()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 29000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 3180 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6120 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d31();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D3 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d32()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 31800;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 3460 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6180 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d32();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D3 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d33()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 66400;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9800 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10100 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d33();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D3 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d34()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 67200;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9950 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10250 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d34();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D3 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d41()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 34600;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 3740 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6240 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d41();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D4 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d42()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 37400;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 4020 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 6300 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d42();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D4 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d43()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 67900;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10100 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10400 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d43();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D4 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d44()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 68700;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10250 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10550 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d44();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D4 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d51()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 69400;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10400 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10700 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d51();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D5 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d52()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 70200;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10550 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10850 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d52();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D5 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d53()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 70900;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10700 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 11000 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d53();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D5 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void d54()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 71700;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10850 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 11150 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        d54();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : D5 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_RT);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_RT);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_RT + denda + ADM_RT));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e1() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            e11();
            break;
        case 2:
            e12();
            break;
        case 3:
            e13();
            break;
        case 4:
            e14();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            e1();
            break;
    }
}

void e2() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            e21();
            break;
        case 2:
            e22();
            break;
        case 3:
            e23();
            break;
        case 4:
            e24();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            e2();
            break;
    }
}

void e3() 
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    ~ LISTRIK ~                     ||\n");
    printf("||        Fasilitas listrik yang Anda gunakan.        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  450 Volt Ampere (Watt)                       ||\n");
    printf("||  [2]  900 Volt Ampere (Watt)                       ||\n");
    printf("||  [3] 1300 Volt Ampere (Watt)                       ||\n");
    printf("||  [4] 1300 Volt Ampere (Watt) keatas                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Mohon masukkan kode angka pada [] : ");
    int kode = cekInput();
    switch (kode)
    {
        case 1:
            e31();
            break;
        case 2:
            e32();
            break;
        case 3:
            e33();
            break;
        case 4:
            e34();
            break;
        default:
            system("clear");
            printf("|| ================================================== ||\n");
            printf("||           Ada yang salah. Mohon ulangi!            ||\n");
            printf("|| ================================================== ||\n");
            e3();
            break;
    }
}

void e11()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 92000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 9850 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 10950 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e11();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E1 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e12()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 95000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10150 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 11250 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e12();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E1 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e13()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 98000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10450 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 11550 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e13();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E1 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e14()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 101000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 10750 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 11850 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e14();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E1 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e21()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 104000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 11050 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 12150 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e21();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E2 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e22()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 104000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 11050 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 12150 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e22();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E2 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e23()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 110000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 11650 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 13150 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e23();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E2 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e24()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 113000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 11950 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 13950 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e24();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E2 -4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e31()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 116000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 12250 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 14750 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e31();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E3 - 1\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e32()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 119000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 12550 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 15050 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e32();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E3 - 2\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e33()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 122000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 12850 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 15850 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e33();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E3 - 3\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void e34()
{
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                  ~ REGISTRASI ~                    ||\n");
    printf("||              Registrasikan data Anda.              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("|| Pemakaian sampai bulan lalu (m3) : ");
    float pemakaianBulanLalu = cekInput();
    printf("|| Pemakaian sampai bulan ini  (m3) : ");
    float pemakaianBulanIni = cekInput();
    system("clear");

    float selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
    float biayaPemakaian;
    if (selisihPemakaian > 0 && selisihPemakaian <= 10) biayaPemakaian = 125000;
    else if (selisihPemakaian > 10 && selisihPemakaian <= 20) biayaPemakaian = 13150 * selisihPemakaian;
    else if (selisihPemakaian > 20) biayaPemakaian = 16650 * selisihPemakaian;
    else 
    {
        system("clear");
        printf("|| ================================================== ||\n");
        printf("||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("|| ================================================== ||\n");
        e34();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    float denda;
    if ((tm.tm_mday - JATUH_TEMPO) <= 0) denda = 0;
    else denda = DENDA;

    printf("\n\n|| ================================================== ||\n");
    printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("|| ================================================== ||\n");
    printf("||                    Rekapitulasi                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Nama        : %s\n", nama);
    printf("|| Kelompok    : Rumah Tangga\n");
    printf("|| Golongan    : E3 - 4\n");
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", BPM_U);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", ADM_U);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
}
