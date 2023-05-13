#include <fstream>
#include <iostream>

using namespace std;

//leitura do arquivo csv
void ler_Exel()
{
    ifstream ler("iris_petalas.csv");

    
    while(! ler.eof())
    {

    }
}

//leitura do valor k
void recebe_k()
{
    int k;
    cout << "quantas vezes voce deseja realizar a verificacao? " << endl;
    cin >> k;
    if(k <= 0)
    {
        cout << "numero invalido, deseja tentar novamente? S/N " << endl;
        char SN;
        char S = S;
        cin >> SN;
        if(SN == S)
        {
            
             recebe_k();
        }else{
            return;
        }
    }
}

int main()
{

recebe_k();
}