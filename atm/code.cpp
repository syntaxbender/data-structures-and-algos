#include <iostream>
using namespace std;
int main(){
    int banknotlar[6][2] = {{200, 20}, {100, 20}, {50, 20}, {20, 20}, {10, 20}, {5, 20}};
    while(1){
        int kullanilanbanknotlar[6] = {0,0,0,0,0,0};
        int cekilecekmiktar;
        int banknotindexer = 0;
        cin >> cekilecekmiktar;
        int temp_cekilecekmiktar = cekilecekmiktar;
        while(temp_cekilecekmiktar>0 && banknotlar[5][0]<=temp_cekilecekmiktar){
            while(((banknotlar[banknotindexer][1]-kullanilanbanknotlar[banknotindexer])<1 || banknotlar[banknotindexer][0]>temp_cekilecekmiktar) && banknotindexer<6) banknotindexer++;
            kullanilanbanknotlar[banknotindexer]++;
            temp_cekilecekmiktar = temp_cekilecekmiktar-banknotlar[banknotindexer][0];
        }
        if(banknotindexer == 6) cout << "Haci abi basaramadik olmadi ya.";
        else{
            for (int i = 0; i < 6; i++) {
                banknotlar[i][1] = banknotlar[i][1]-kullanilanbanknotlar[i];
                cout << kullanilanbanknotlar[i] << "x : " << banknotlar[i][0]<< "\n";
            }
        }
    }
}
