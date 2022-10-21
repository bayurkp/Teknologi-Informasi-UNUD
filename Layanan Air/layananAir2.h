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
    menuListrik(),

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
    registrasi(char *nama, float *selisihPemakaian, float *biayaPemakaian, float biayaKurang10, float biayaLebih10, float biayaLebih20),
    rekapitulasi(char nama[], char kelompok[], char golongan[], float selisihPemakaian, float biayaPemakaian, float bpm , float adm),
    pesanError(),
    ulangProgram();

//pesan error
void pesanError() {
    system("clear");
    printf("|| ================================================== ||\n");
    printf("||           Ada yang salah. Mohon ulangi!            ||\n");
    printf("|| ================================================== ||\n");
}

void menuListrik()
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
}

//registrasi
void registrasi(char *nama, float *selisihPemakaian, float *biayaPemakaian, float biayaKurang10, float biayaLebih10, float biayaLebih20)
{   
    int x = 0;
    while (x == 0)
    {
        x--;
        printf("|| ================================================== ||\n");
        printf("||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
        printf("|| ================================================== ||\n");
        printf("||                  ~ REGISTRASI ~                    ||\n");
        printf("||              Registrasikan data Anda.              ||\n");
        printf("|| ================================================== ||\n");
        printf("|| Nama : ");
        scanf("%[^\n]", nama);
        getchar();
        printf("|| Pemakaian sampai bulan lalu (m3) : ");
        float pemakaianBulanLalu = cekInput();
        printf("|| Pemakaian sampai bulan ini  (m3) : ");
        float pemakaianBulanIni = cekInput();
        system("clear");

        *selisihPemakaian = pemakaianBulanIni - pemakaianBulanLalu;
        if ((*selisihPemakaian) > 0 && (*selisihPemakaian) <= 10) *biayaPemakaian = biayaKurang10 * 10;
        else if ((*selisihPemakaian) > 10 && (*selisihPemakaian) <= 20) *biayaPemakaian = biayaLebih10 * (*selisihPemakaian);
        else if ((*selisihPemakaian) > 20) *biayaPemakaian = biayaLebih20 * (*selisihPemakaian);
        else
        {
            pesanError();
            x++;
        }
    }
}

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
        pesanError();
        ulangProgram();
    }
}

//rekapitulasi
void rekapitulasi(char nama[], char kelompok[], char golongan[], float selisihPemakaian, float biayaPemakaian, float bpm , float adm) {
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
    printf("|| Golongan    : %s\n", golongan);
    printf("|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Jatuh Tempo : %d-%d-%d\n", JATUH_TEMPO, tm.tm_mon+1, tm.tm_year+1900);
    printf("|| Pemakaian   : %.2f m3\n", selisihPemakaian);
    printf("|| Biaya Pakai : Rp %.2f\n", biayaPemakaian);
    printf("|| BPM         : Rp %.2f\n", bpm);
    printf("|| Denda       : Rp %.2f\n", denda);
    printf("|| Admintrasi  : Rp %.2f\n", adm);
    printf("|| ================================================== ||\n");
    printf("|| Total       : Rp %.2f\n", (biayaPemakaian + BPM_U + denda + ADM_U));
    printf("|| ================================================== ||\n");
    getchar();
    ulangProgram();
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
            menuUsaha();
            break;
        default:
            pesanError();
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
            pesanError();
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
    menuListrik();
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
            pesanError();
            d1();
            break;
    }
}

void d2() 
{
    menuListrik();
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
            pesanError();
            d2();
            break;
    }
}

void d3() 
{
    menuListrik();
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
            pesanError();
            d3();
            break;
    }
}

void d4() 
{
    menuListrik();
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
            pesanError();
            d4();
            break;
    }
}

void d5() 
{
    menuListrik();
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
            pesanError();
            d5();
            break;
    }
}

void d11()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 1780, 2060, 5880);

    rekapitulasi(nama, "Rumah Tangga", "D1 - 1", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d12()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 2060, 2340, 5940);


    rekapitulasi(nama, "Rumah Tangga", "D1 - 2", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d13()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6340, 9200, 9600);


   rekapitulasi(nama, "Rumah Tangga", "D1 - 3", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d14()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6420, 9350, 9650);


    rekapitulasi(nama, "Rumah Tangga", "D1 - 4", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d21()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 2340, 2620, 6000);


    rekapitulasi(nama, "Rumah Tangga", "D2 - 1", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d22()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 2620, 2900, 6060);


    rekapitulasi(nama, "Rumah Tangga", "D2 - 2", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d23()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6490, 9500, 9800);


    rekapitulasi(nama, "Rumah Tangga", "D2 - 3", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d24()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6570, 9650, 9950);


    rekapitulasi(nama, "Rumah Tangga", "D2 - 4", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d31()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 2900, 3180, 6120);


    rekapitulasi(nama, "Rumah Tangga", "D3 - 1", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d32()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 3180, 3460, 6180);


    rekapitulasi(nama, "Rumah Tangga", "D3 - 2", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d33()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6640, 9800, 10100);


    rekapitulasi(nama, "Rumah Tangga", "D3 - 3", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d34()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6720, 9950, 10250);


    rekapitulasi(nama, "Rumah Tangga", "D3 - 4", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d41()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 3460, 3740, 6240);


    rekapitulasi(nama, "Rumah Tangga", "D4 - 1", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d42()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 3740, 4020, 6300);


    rekapitulasi(nama, "Rumah Tangga", "D4 - 2", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d43()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6790, 10100, 10400);

    rekapitulasi(nama, "Rumah Tangga", "D4 - 3", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d44()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6870, 10250, 10550);

    rekapitulasi(nama, "Rumah Tangga", "D4 - 4", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d51()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 6940, 10400, 10700);

    rekapitulasi(nama, "Rumah Tangga", "D5 - 1", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d52()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 7020, 10550, 10850);

    rekapitulasi(nama, "Rumah Tangga", "D5 - 2", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d53()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 7090, 10700, 11000);

    rekapitulasi(nama, "Rumah Tangga", "D5 - 3", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void d54()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 7170, 10850, 11150);

    rekapitulasi(nama, "Rumah Tangga", "D5 - 4", selisihPemakaian, biayaPemakaian, BPM_RT, ADM_RT);
}

void e1() 
{
    menuListrik();
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
            pesanError();
            e1();
            break;
    }
}

void e2() 
{
    menuListrik();
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
            pesanError();
            e2();
            break;
    }
}

void e3() 
{
    menuListrik();
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
            pesanError();
            e3();
            break;
    }
}

void e11()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 9200, 9850, 10950);

    rekapitulasi(nama, "Usaha", "E1 - 1", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e12()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 9500, 10150, 11250);

    rekapitulasi(nama, "Usaha", "E1 - 2", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e13()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 9800, 10450, 11550);

    rekapitulasi(nama, "Usaha", "E1 - 3", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e14()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 10100, 10750, 11850);

    rekapitulasi(nama, "Usaha", "E1 - 4", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e21()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 10400, 11050, 12150);

    rekapitulasi(nama, "Usaha", "E2 - 1", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e22()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 10700, 11350, 12550);

    rekapitulasi(nama, "Usaha", "E2 - 2", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e23()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 11000, 11650, 12550);

    rekapitulasi(nama, "Usaha", "E2 - 3", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e24()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 11300, 11950, 13950);

    rekapitulasi(nama, "Usaha", "E2 - 4", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e31()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 11600, 12250, 14750);

    rekapitulasi(nama, "Usaha", "E3 - 1", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e32()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 11900, 12550, 15050);

    rekapitulasi(nama, "Usaha", "E3 - 2", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e33()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 12200, 12850, 15850);

    rekapitulasi(nama, "Usaha", "E3 - 3", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}

void e34()
{
    char nama[100];
    float selisihPemakaian,
        biayaPemakaian;
    registrasi(nama, &selisihPemakaian, &biayaPemakaian, 12500, 13150, 16650);

    rekapitulasi(nama, "Usaha", "E3 - 4", selisihPemakaian, biayaPemakaian, BPM_U, ADM_U);
}
