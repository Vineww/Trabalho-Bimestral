#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//caracteristicas da flor
struct flower
{

float lenght;
float width;
string variety;

}; flower petal;



//leitura do arquivo csv
void ler_Excel()
{

ifstream inputFile;
inputFile.open("iris_petalas.csv");

string line = "";
while (getline(inputFile, line)) 
{
    double length;
    double width;
    string variety;
    string tempString; // ler double

    stringstream inputString(line); // cria um stream fora da linha

    getline(inputString, variety), ',';

    
    getline(inputString, tempString, ',');
    width = atoi(tempString.c_str()); // atoi é uma função utilizada para converter variáveis em strings, necessário para usar o getline no width (que é um double).

    
    getline(inputString, tempString);
    length = atof(tempString.c_str()); // convertendo length em string.

    line = "";
}
}

//imprimir tabela

void imprime()
{
    
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