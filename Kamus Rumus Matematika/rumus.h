#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void menuUtama();

//Check input
float checkInput() {
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
        printf("||       Maaf, input Anda salah. Mohon ulangi!     ||\n");
        printf("|| ================================================== ||\n");
        printf("|| ");
        return checkInput();
    } else {
        return nilaiInput;
    }
}

//Coba Lagi
void cobaLagi()  {
    int pilihan, menu;
    printf("\n\n|| ================================================== ||\n");
    printf("||   Apakah Anda ingin menjalankan program kembali?   ||\n");
    printf("|| ================================================== ||\n");
    printf("||  Kode ||               Pilihan                     ||\n");
    printf("|| ================================================== ||\n");
    printf("||  [1]  ||                 Iya                       ||\n");
    printf("||  [2]  ||                Tidak                      ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda : ");
    pilihan = checkInput();
    switch (pilihan) {
    case 1:
        system("clear");
        menuUtama();
    case 2:
        system("clear");
        break;
    default :
        printf("|| ================================================== ||\n");
        printf("||        Maaf, input Anda salah. Mohon ulangi!       ||\n");
        printf("|| ================================================== ||\n\n");
        cobaLagi();
    }
}

//Rumus kecepatan, perpindahan, dan selang waktu
float kecepatan() {
    float kecepatan,
        perpindahan,
        selangWaktu;

    printf("\n|| ================================================== ||\n");
    printf("||       Kecepatan = Perpindahan / Selang Waktu       ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan perpindahan  : ");
    perpindahan = checkInput();
    printf("|| Masukkan selang waktu : ");
    selangWaktu = checkInput();

    kecepatan = perpindahan / selangWaktu;
    return kecepatan;
}

float perpindahan() {
    float kecepatan,
        perpindahan,
        selangWaktu;

    printf("\n|| ================================================== ||\n");
    printf("||       Perpindahan = Kecepatan * Selang Waktu       ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan kecepatan    : ");
    kecepatan = checkInput();
    printf("|| Masukkan selang waktu : ");
    selangWaktu = checkInput();

    perpindahan = kecepatan * selangWaktu;
    return perpindahan;
}

float selangWaktu() {
    float kecepatan,
        perpindahan,
        selangWaktu;

    printf("\n|| ================================================== ||\n");
    printf("||       Selang Waktu = Perpindahan / Kecepatan       ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan kecepatan  : ");
    kecepatan = checkInput();
    printf("|| Masukkan perpindahan : ");
    perpindahan = checkInput();

    selangWaktu = perpindahan / kecepatan;
    return selangWaktu;
}

void menuGLBB() {
    int menu;
    float outputKecepatan,
        outputPerpindahan,
        outputSelangWaktu;

    printf("\n|| ================================================== ||\n");
    printf("||                       Menu                         ||\n");
    printf("|| ================================================== ||\n");
    printf("||           Formula Gerak Lurus Beraturan            ||\n");
    printf("|| ================================================== ||\n");
    printf("|| 1. Kecepatan                                       ||\n");
    printf("|| 2. Perpindahan                                     ||\n");
    printf("|| 3. Selang Waktu                                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda: ");
    menu = checkInput();
    printf("|| ================================================== ||\n");
    
    switch (menu) {
    case 1:
        outputKecepatan = kecepatan();
        printf("|| Kecepatan Anda adalah %.2f", outputKecepatan);
        printf("\n|| ================================================== ||\n\n");
        break;
    case 2:
        outputPerpindahan = perpindahan();
        printf("|| Perpindahan Anda adalah %.2f", outputPerpindahan);
        printf("\n|| ================================================== ||\n\n");
        break;
    case 3:
        outputSelangWaktu = selangWaktu();
        printf("|| Perpindahan Anda adalah %.2f", outputSelangWaktu);
        printf("\n|| ================================================== ||\n\n");
        break;
    default:
        printf("\n|| ================================================== ||\n");
        printf("||        Maaf, input Anda salah. Mohon ulangi!       ||\n");
        printf("|| ================================================== ||\n\n");
        menuGLBB();
        break;
    }

    cobaLagi();
}

//Rumus bangun datar
//Persegi, Persegi Panjang, Segitiga Sama Sisi, Jajar Genjang, Lingkaran, Belah Ketupat
float persegiKeliling() {
    float sisi,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||                   Keliling Persegi                 ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi : ");
    sisi = checkInput();

    keliling = 4 * sisi;
    return keliling;
}

float persegiLuas() {
    float sisi,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||                     Luas Persegi                   ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi : ");
    sisi = checkInput();

    luas = sisi * sisi;
    return luas;
}

float persegiPanjangKeliling() {
    float panjang,
        lebar,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||             Keliling Persegi Panjang               ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan panjang : ");
    panjang = checkInput();
    printf("|| Masukkan lebar : ");
    lebar = checkInput();

    keliling = 2 * (panjang + lebar);
    return keliling;
}

float persegiPanjangLuas() {
    float panjang,
        lebar,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Persegi Panjang                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan panjang : ");
    panjang = checkInput();
    printf("|| Masukkan lebar : ");
    lebar = checkInput();

    luas = panjang * lebar;
    return luas;
}

float segitigaSamaSisiKeliling() {
    float sisi,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||            Keliling Segitiga Sama Sisi             ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi : ");
    sisi = checkInput();

    keliling = 3 * sisi;
    return keliling;
}

float segitigaSamaSisiLuas() {
    float sisi,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||              Luas Segigita Sama Sisi               ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi : ");
    sisi = checkInput();

    luas = 0.5 * sisi /* alas */ * sqrt(pow(sisi, 2) - (pow((sisi/2), 2))) /* tinggi */;
    return luas;
}

float jajarGenjangKeliling() {
    float sisiHorizontal,
        sisiDiagonal,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||              Keliling Jajar Genjang                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi horizontal : ");
    sisiHorizontal = checkInput();
    printf("|| Masukkan sisi diagonal : ");
    sisiDiagonal = checkInput();

    keliling = 2 * (sisiHorizontal + sisiDiagonal);
    return keliling;
}

float jajarGenjangLuas() {
    float alas,
        tinggi,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Jajar Genjang                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan alas : ");
    alas = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();

    luas = alas * tinggi;
    return luas;
}

float lingkaranKeliling() {
    float jariJari,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||                Keliling Lingkaran                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan alas : ");
    jariJari = checkInput();

    keliling = M_PI * pow(jariJari, 2);
    return keliling;
}

float lingkaranLuas() {
    float jariJari,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||                  Luas Lingkaran                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan alas : ");
    jariJari = checkInput();

    luas = M_PI * 2 * jariJari;
    return luas;
}

float belahKetupatKeliling() {
    float sisi,
        keliling;

    printf("\n|| ================================================== ||\n");
    printf("||               Keliling Belah Ketupat               ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan sisi : ");
    sisi = checkInput();

    keliling = 4 * sisi;
    return keliling;
}

float belahKetupatLuas() {
    float diagonal1,
        diagonal2,
        luas;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Belah Ketupat                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan diagonal 1 : ");
    diagonal1 = checkInput();
    printf("|| Masukkan diagonal 2 : ");
    diagonal2 = checkInput();

    luas = 0.5 * diagonal1 * diagonal2;
    return luas;
}

void menuBangunDatar() {
    int menu;

    printf("\n|| ================================================== ||\n");
    printf("||                       Menu                         ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Formula Bangun Datar                ||\n");
    printf("|| ================================================== ||\n");
    printf("||  1. Keliling  Persegi                              ||\n");
    printf("||  2. Luas      Persegi                              ||\n");
    printf("||  3. Keliling  Persegi Panjang                      ||\n");
    printf("||  4. Luas      Persegi Panjang                      ||\n");
    printf("||  5. Keliling  Segitiga Sama Sisi                   ||\n");
    printf("||  6. Luas      Segitiga Sama Sisi                   ||\n");
    printf("||  7. Keliling  Jajar Genjang                        ||\n");
    printf("||  8. Luas      Jajar Genjang                        ||\n");
    printf("||  9. Keliling  Lingkaran                            ||\n");
    printf("|| 10. Luas      Lingkaran                            ||\n");
    printf("|| 11. Keliling  Belah Ketupat                        ||\n");
    printf("|| 12. Luas      Belah Ketupat                        ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda: ");
    menu = checkInput();
    printf("|| ================================================== ||\n");
    
    switch (menu) {
    case 1:
        printf("|| Keliling persegi Anda adalah %.2f", persegiKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 2:
        printf("|| Luas persegi Anda adalah %.2f", persegiLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 3:
        printf("|| Keliling persegi panjang Anda adalah %.2f", persegiPanjangKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 4:
        printf("|| Luas persegi panjang Anda adalah %.2f", persegiPanjangLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 5:
        printf("|| Keliling segitiga sama sisi Anda adalah %.2f", segitigaSamaSisiKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 6:
        printf("|| Luas segitga sama sisi Anda adalah %.2f", segitigaSamaSisiLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 7:
        printf("|| Keliling jajar genjang Anda adalah %.2f", jajarGenjangKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 8:
        printf("|| Luas jajar gejang Anda adalah %.2f", jajarGenjangLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 9:
        printf("|| Keliling lingkaran Anda adalah %.2f", lingkaranKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 10:
        printf("|| Luas lingkaran Anda adalah %.2f", lingkaranLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 11:
        printf("|| Keliling belah ketupat Anda adalah %.2f", belahKetupatKeliling());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 12:
        printf("|| Perpindahan belah ketupat Anda adalah %.2f", belahKetupatLuas());
        printf("\n|| ================================================== ||\n\n");
        break;
    default:
        printf("\n|| ================================================== ||\n");
        printf("||        Maaf, input Anda salah. Mohon ulangi!       ||\n");
        printf("|| ================================================== ||\n\n");
        menuBangunDatar();
        break;
    }

    cobaLagi();
}

//Rumus bangun ruang
//Kubus, Balok, Kerucut, Bola, Tabung
float kubusLuasPermukaan() {
    float rusuk,
        luasPermukaan;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Permukaan Kubus                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan rusuk : ");
    rusuk = checkInput();

    luasPermukaan = 6 * rusuk * rusuk;
    return luasPermukaan;
}

float kubusVolume() {
    float rusuk,
        volume;

    printf("\n|| ================================================== ||\n");
    printf("||                    Volume Kubus                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan rusuk : ");
    rusuk = checkInput();

    volume = rusuk * rusuk * rusuk;
    return volume;
}

float balokLuasPermukaan() {
    float panjang,
        lebar,
        tinggi,
        luasPermukaan;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Permukaan Balok                ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan panjang : ");
    panjang = checkInput();
    printf("|| Masukkan lebar : ");
    lebar = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();

    luasPermukaan = 2 * ((panjang * lebar) + (panjang * tinggi) + (lebar * tinggi));
    return luasPermukaan;
}

float balokVolume() {
    float panjang,
        lebar,
        tinggi,
        volume;

    printf("\n|| ================================================== ||\n");
    printf("||                    Volume Balok                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan panjang : ");
    panjang = checkInput();
    printf("|| Masukkan lebar : ");
    lebar = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();

    volume = panjang * lebar * tinggi;
    return volume;
}

float kerucutLuasPermukaan() {
    float jariJariAlas,
        garisPelukis,
        luasPermukaan;

    printf("\n|| ================================================== ||\n");
    printf("||               Luas Permukaan Kerucut               ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari alas : ");
    jariJariAlas = checkInput();
    printf("|| Masukkan garis pelukis : ");
    garisPelukis = checkInput();

    luasPermukaan = M_PI * jariJariAlas * (jariJariAlas + garisPelukis);
    return luasPermukaan;
}

float kerucutVolume() {
    float jariJariAlas,
        tinggi,
        volume;

    printf("\n|| ================================================== ||\n");
    printf("||                   Volume Kerucut                   ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari alas : ");
    jariJariAlas = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();

    volume = (1.0 / 3.0) * M_PI * pow(jariJariAlas, 2) * tinggi;
    return volume;
}

float bolaLuasPermukaan() {
    float jariJari,
        luasPermukaan;

    printf("\n|| ================================================== ||\n");
    printf("||                Luas Permukaan Bola                 ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari bola : ");
    jariJari = checkInput();

    luasPermukaan = 4 *  M_PI * pow(jariJari, 2);
    return luasPermukaan;
}

float bolaVolume() {
    float jariJari,
        volume;

    printf("\n|| ================================================== ||\n");
    printf("||                     Volume Bola                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari bola : ");
    jariJari = checkInput();

    volume = 4.0/3.0 *  M_PI * pow(jariJari, 3);
    return volume;
}

float tabungLuasPermukaan() {
    float jariJariAlas,
        tinggi,
        luasPermukaan;

    printf("\n|| ================================================== ||\n");
    printf("||              Luas Permukaan Tabung                 ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari alas : ");
    jariJariAlas = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();

    luasPermukaan = (M_PI * 2 * jariJariAlas * tinggi) + 2 * (M_PI * pow(jariJariAlas, 2));
    return luasPermukaan;
}

float tabungVolume() {
    float jariJariAlas,
        tinggi,
        volume;

    printf("\n|| ================================================== ||\n");
    printf("||                   Volume Tabung                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan jari-jari alas : ");
    jariJariAlas = checkInput();
    printf("|| Masukkan tinggi : ");
    tinggi = checkInput();


    volume = M_PI * pow(jariJariAlas, 2) * tinggi;
    return volume;
}

void menuBangunRuang() {
    int menu;

    printf("\n|| ================================================== ||\n");
    printf("||                       Menu                         ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Formula Bangun Ruang                ||\n");
    printf("|| ================================================== ||\n");
    printf("||  1. Luas Permukaan   Kubus                         ||\n");
    printf("||  2. Volume           Kubus                         ||\n");
    printf("||  3. Luas Permukaan   Balok                         ||\n");
    printf("||  4. Volume           Balok                         ||\n");
    printf("||  5. Luas Permukaan   Kerucut                       ||\n");
    printf("||  6. Volume           Kerucut                       ||\n");
    printf("||  7. Luas Permukaan   Bola                          ||\n");
    printf("||  8. Volume           Bola                          ||\n");
    printf("||  9. Luas Permukaan   Tabung                        ||\n");
    printf("|| 10. Volume           Tabung                        ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda: ");
    menu = checkInput();
    printf("|| ================================================== ||\n");
    
    switch (menu) {
    case 1:
        printf("|| Luas permukaan kubus Anda adalah %.2f", kubusLuasPermukaan());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 2:
        printf("|| Volume kubus Anda adalah %.2f", kubusVolume());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 3:
        printf("|| Luas permukaan balok Anda adalah %.2f", balokLuasPermukaan());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 4:
        printf("|| Volume balok Anda adalah %.2f", balokVolume());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 5:
        printf("|| Luas permukaan kerucut Anda adalah %.2f", kerucutLuasPermukaan());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 6:
        printf("|| Volume kerucut Anda adalah %.2f", kerucutVolume());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 7:
        printf("|| Luas permukaan bola Anda adalah %.2f", bolaLuasPermukaan());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 8:
        printf("|| Volume bola Anda adalah %.2f", bolaVolume());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 9:
        printf("|| Luas permukaan tabung Anda adalah %.2f", tabungLuasPermukaan());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 10:
        printf("|| Volume tabung Anda adalah %.2f", tabungVolume());
        printf("\n|| ================================================== ||\n\n");
        break;
    default:
        printf("\n|| ================================================== ||\n");
        printf("||       Maaf, input Anda salah. Mohon ulangi!        ||\n");
        printf("|| ================================================== ||\n\n");
        menuBangunRuang();
        break;
    }

    cobaLagi();
}


//Rumus barisan dan deret
float deretGeometri() {
    float sukuPertama,
        banyakSuku,
        rasio,
        deretKeN;

    printf("\n|| ================================================== ||\n");
    printf("||                  Deret Geometri                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan suku pertama : ");
    sukuPertama = checkInput();
    printf("|| Masukkan banyak suku : ");
    banyakSuku = checkInput();
    printf("|| Masukkan rasio: ");
    rasio = checkInput();

    if (rasio > 1) {
        deretKeN = sukuPertama * (1 - (pow(rasio, banyakSuku))) / (1 - rasio);
        return deretKeN;
    } else if (rasio < 1) {
        deretKeN = sukuPertama * ((pow(rasio, banyakSuku)) - 1) / (rasio - 1);
        return deretKeN;
    } else {
        printf("\n|| ================================================== ||\n");
        printf("||     Mohon untuk tidak menginput 1 pada rasio!      ||\n");
        printf("|| ================================================== ||\n\n");
        deretGeometri();
    }

}

float barisanGeometri() {
    float sukuPertama,
        banyakSuku,
        rasio,
        sukuKeN;

    printf("\n|| ================================================== ||\n");
    printf("||                Barisan Geometri                    ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan suku pertama : ");
    sukuPertama = checkInput();
    printf("|| Masukkan banyak suku : ");
    banyakSuku = checkInput();
    printf("|| Masukkan rasio: ");
    rasio = checkInput();

    sukuKeN = sukuPertama * pow(rasio, (banyakSuku - 1));
    return sukuKeN;
}

float deretAritmatika() {
    float sukuPertama,
        banyakSuku,
        beda,
        deretKeN;

    printf("\n|| ================================================== ||\n");
    printf("||                  Deret Aritmatika                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan suku pertama : ");
    sukuPertama = checkInput();
    printf("|| Masukkan banyak suku : ");
    banyakSuku = checkInput();
    printf("|| Masukkan beda: ");
    beda = checkInput();

    deretKeN = 0.5 * banyakSuku * (2 * sukuPertama + (banyakSuku - 1) * beda);
    return deretKeN;
}

float barisanAritmatika() {
    float sukuPertama,
        banyakSuku,
        beda,
        sukuKeN;

    printf("\n|| ================================================== ||\n");
    printf("||                Barisan Aritmatika                  ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Masukkan suku pertama : ");
    sukuPertama = checkInput();
    printf("|| Masukkan banyak suku : ");
    banyakSuku = checkInput();
    printf("|| Masukkan beda: ");
    beda = checkInput();

    sukuKeN = sukuPertama + (banyakSuku - 1) * beda;
    return sukuKeN;
}

void menuDeretBarisan() {
    int menu;

    printf("\n|| ================================================== ||\n");
    printf("||                       Menu                         ||\n");
    printf("|| ================================================== ||\n");
    printf("||              Formula Deret & Barisan               ||\n");
    printf("|| ================================================== ||\n");
    printf("||  1. Deret    Geometri                              ||\n");
    printf("||  2. Barisan  Geometri                              ||\n");
    printf("||  3. Deret    Aritmatika                            ||\n");
    printf("||  4. Barisan  Aritmatika                            ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda: ");
    menu = checkInput();
    printf("|| ================================================== ||\n");
    
    switch (menu) {
    case 1:
        printf("|| Jumlah suku Anda sampai ke-N adalah %.2f", deretGeometri());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 2:
        printf("|| Suku ke-N Anda adalah %.2f", barisanGeometri());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 3:
        printf("|| Suku ke-N Anda adalah %.2f", deretAritmatika());
        printf("\n|| ================================================== ||\n\n");
        break;
    case 4:
        printf("|| Suku ke-N Anda adalah %.2f", barisanAritmatika());
        printf("\n|| ================================================== ||\n\n");
        break;
    default:
        printf("\n|| ================================================== ||\n");
        printf("||       Maaf, input Anda salah. Mohon ulangi!     ||\n");
        printf("|| ================================================== ||\n\n");
        menuDeretBarisan();
        break;
    }

    cobaLagi();
}

void menuUtama() {
    int menu;

    printf("\n|| ================================================== ||\n");
    printf("||                       Menu                         ||\n");
    printf("|| ================================================== ||\n");
    printf("||                       Utama                        ||\n");
    printf("|| ================================================== ||\n");
    printf("||  1. Gerak Lurus Beraturan                          ||\n");
    printf("||  2. Bangun Datar                                   ||\n");
    printf("||  3. Bangun Ruang                                   ||\n");
    printf("||  4. Deret dan Barisan                              ||\n");
    printf("|| ================================================== ||\n");
    printf("|| Pilihan Anda: ");
    menu = checkInput();
    printf("|| ================================================== ||\n");
    
    switch (menu) {
    case 1:
        menuGLBB();
        break;
    case 2:
        menuBangunDatar();
        break;
    case 3:
        menuBangunRuang();
        break;
    case 4:
        menuDeretBarisan();
        break;
    default:
        printf("\n|| ================================================== ||\n");
        printf("||       Maaf, input Anda salah. Mohon ulangi!     ||\n");
        printf("|| ================================================== ||\n\n");
        menuDeretBarisan();
        break;
    }
}
