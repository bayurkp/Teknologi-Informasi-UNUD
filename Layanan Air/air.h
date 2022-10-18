#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BPM_RT 10 //Biaya Pemliharaan Meter Rumah Tangga
#define BPM_U 20 //Biaya Pemeliharaan Meter Usaha
#define ADM 50 //Biaya Administrasi
#define BIAYA_10 50 //Biaya 10 meter kubik pertama adalah Rp 50,- 
#define BIAYA_N 10 //Biaya 10+n meter kubik adalah Rp 10,- 
#define DENDA_100 20 //Denda pemakaian lebih dari 100 meter kubik adalah 20,-
#define DENDA_10_100 10 //Denda pemakaian lebih dari 10 meter kubik dan tidak lebih dari 100 meter kubik adalah Rp 10,-
#define BOLD "\e[1m"
#define BOLD_END "\e[m"

//deklarasi prosedur dan fungsi
float cekInput();
void pengguna(),
    menuKelompok(),
    rumahTangga(),
    usaha(),
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
        printf("\t\t|| ================================================== ||\n");
        printf("\t\t||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("\t\t|| ================================================== ||\n");
        printf("\t\t|| ");
        return cekInput();
    } else {
        return nilaiInput;
    }
}

void ulangProgram()
{
    int pilihan, menu;
    printf("\n\n\t\t|| ================================================== ||\n");
    printf("\t\t||    Apakah Anda ingin menjalankan program lagi?     ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| [1] Ya, saya ingin menjalankan program lagi.       ||\n");
    printf("\t\t|| [2] Tidak, saya ingin keluar dari program.         ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Pilihan Anda : ");
    pilihan = cekInput();
    switch (pilihan) {
    case 1:
        system("clear");
        pengguna();
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

//input nama pengguna
void pengguna()
{
    printf("\n\n\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||        \"Air Jernih, Bersih, dan Penuh Kasih\"       ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Oleh :                                             ||\n");
    printf("\t\t|| Ni Putu Andri Krisnantari                          ||\n");
    printf("\t\t|| Bayu Rizky Kurnia Pratama                          ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||            Tekan enter untuk melanjutkan!          ||\n");
    printf("\t\t|| ================================================== ||");
    getchar();
    system("clear");
    menuKelompok();
}

//input pilihan kelompok

void menuKelompok()
{
    int kode;
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                      Kelompok                      ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| [1] Rumah Tangga                                   ||\n");
    printf("\t\t|| [2] Usaha                                          ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Mohon masukkan kode : ");
    kode = cekInput();
    
    switch (kode)
    {
    case 1:
        rumahTangga();
        break;
    case 2:
        usaha();
        break;
    default:
        system("clear");
        printf("\t\t|| ================================================== ||\n");
        printf("\t\t||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("\t\t|| ================================================== ||\n");
        menuKelompok();
        break;
    }
}

void rumahTangga() 
{
    system("clear");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                    Rumah Tangga                    ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Nama Anda : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("\t\t|| Pemakaian sampai bulan lalu (m3) : ");
    float bulanLalu = cekInput();
    printf("\t\t|| Pemakaian sampai bulan ini  (m3) : ");
    float bulanIni = cekInput();
    printf("\t\t|| ================================================== ||\n");
    float pemakaian = bulanIni -  bulanLalu;
    printf("\t\t|| Pemakaian Anda pada bulan ini adalah %.2f m3\n", pemakaian);
    printf("\t\t|| ================================================== ||\n");

    float biayaPemakaian;
    if (pemakaian <= 10 && pemakaian > 0)
    {
        biayaPemakaian = ADM + BPM_RT + BIAYA_10;
    }

    else if (pemakaian > 10)
    {
        biayaPemakaian = ADM + BPM_RT + BIAYA_10 + ((pemakaian - 10) * BIAYA_N);
        if (pemakaian <= 100)
        {
            biayaPemakaian += DENDA_10_100;
        }

        else if (pemakaian > 100)
        {
            biayaPemakaian += DENDA_100;
        }
    } 

    else
    {
        system("clear");
        printf("\t\t|| ================================================== ||\n");
        printf("\t\t||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("\t\t|| ================================================== ||\n");
        rumahTangga();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\n\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                       Biaya                        ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Nama        : %s\n", nama);
    printf("\t\t|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t|| Pemakaian   : %.2f m3\n", pemakaian);
    printf("\t\t|| Total biaya : Rp %.2f,-\n", biayaPemakaian);
    printf("\t\t|| ================================================== ||\n");
    getchar();
    ulangProgram();
}

void usaha()
{
    system("clear");
    printf("\n\n\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                        Usaha                       ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Nama Anda : ");
    char nama[100];
    scanf("%[^\n]", nama);
    getchar();
    printf("\t\t|| Pemakaian sampai bulan lalu (m3) : ");
    float bulanLalu = cekInput();
    printf("\t\t|| Pemakaian sampai bulan ini  (m3) : ");
    float bulanIni = cekInput();
    printf("\t\t|| ================================================== ||\n");
    float pemakaian = bulanIni -  bulanLalu;
    printf("\t\t|| Pemakaian Anda pada bulan ini adalah %.2f\n", pemakaian);
    printf("\t\t|| ================================================== ||\n");

    float biayaPemakaian;
    if (pemakaian <= 10 && pemakaian > 0)
    {
        biayaPemakaian = ADM + BPM_U + BIAYA_10;
    }

    else if (pemakaian > 10)
    {
        biayaPemakaian = ADM + BPM_U + BIAYA_10 + ((pemakaian - 10) * BIAYA_N);
        if (pemakaian <= 100)
        {
            biayaPemakaian += DENDA_10_100;
        }

        else if (pemakaian > 100)
        {
            biayaPemakaian += DENDA_100;
        }
    } 

    else
    {
        system("clear");
        printf("\t\t|| ================================================== ||\n");
        printf("\t\t||           Ada yang salah. Mohon ulangi!            ||\n");
        printf("\t\t|| ================================================== ||\n");
        rumahTangga();
    }

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\n\t\t|| ================================================== ||\n");
    printf("\t\t||                " BOLD "CV. SAUBERES WASSER" BOLD_END "                 ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t||                       Biaya                        ||\n");
    printf("\t\t|| ================================================== ||\n");
    printf("\t\t|| Nama        : %s\n", nama);
    printf("\t\t|| Tanggal     : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t|| Pemakaian   : %.2f m3\n", pemakaian);
    printf("\t\t|| Total biaya : Rp %.2f,-\n", biayaPemakaian);
    printf("\t\t|| ================================================== ||\n");
    getchar();
    ulangProgram();
}
