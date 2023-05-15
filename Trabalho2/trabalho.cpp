#include <fstream>
#include <iostream>

using namespace std;

//caracteristicas da flor
struct flores
{
float petal_Lenght;
float petal_Width;
string variety;
}; flores flor;

//leitura do arquivo csv
void ler_Excel()
{
    ifstream ler("iris_petalas.csv");

    
    while(! ler.eof())
    {

    }
}

//leitura do valor k
void recebe_k(int* pk)
{
    if(*(pk) <= 0)
    {
        cout << "numero invalido, tente novamente. " << endl;
        return;

    }
}

int main()
{

    int k;
    cout << "quantas vezes voce deseja realizar a verificacao? " << endl;
    cin >> k;
    recebe_k(&k);
}