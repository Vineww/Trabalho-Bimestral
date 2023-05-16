#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_FLOWERS = 150;

// Características da flor
struct Flower
{
    float length;
    float width;
    string variety;
};

// Leitura do arquivo CSV
void lerArquivo(Flower flowers[], int& numFlowers)
{
    ifstream inputFile;
    inputFile.open("iris_petalas.csv");

    string line = "";
    getline(inputFile, line); 

    while (getline(inputFile, line))
    {
        if (numFlowers >= MAX_FLOWERS)
            break;

        string lengthStr, widthStr, variety;
        stringstream inputString(line);
        
        getline(inputString, lengthStr, ',');
        getline(inputString, widthStr, ',');
        getline(inputString, variety);

        // Converte as strings para float
        float length = stof(lengthStr);
        float width = stof(widthStr);

        // Armazena os dados na struct Flower
        flowers[numFlowers].length = length;
        flowers[numFlowers].width = width;
        flowers[numFlowers].variety = variety;

        numFlowers++;
    }

    inputFile.close();
}

// Imprime a tabela de flores
void imprimeTabela(const Flower flowers[], int numFlowers)
{
    for (int i = 0; i < numFlowers; i++)
    {
        cout << "Flor " << i + 1 << ":" << endl;
        cout << "  altura: " << flowers[i].length << endl;
        cout << "  largura: " << flowers[i].width << endl;
        cout << "  especie: " << flowers[i].variety << endl;
        cout << endl;
    }
}

// Função para receber o valor de k
int recebeK()
{
    int k;
    cout << "Quantas vezes voce deseja realizar a verificacao? ";
    cin >> k;

    while (k <= 0)
    {
        cout << "Numero invalido, tente novamente: ";
        cin >> k;

        if(k > 0) break;
    }

    return k;
}

int main()
{
    Flower flowers[MAX_FLOWERS];
    int numFlowers = 0;

    lerArquivo(flowers, numFlowers);
    imprimeTabela(flowers, numFlowers);

    int k = recebeK();
    cout << "executando verificacao " << k << " vezes" << endl;

    return 0;
}
