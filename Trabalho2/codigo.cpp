#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <ctime>

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



// Função para receber o valor de k
int recebeK()
{
    int k;
    cout << "Quantas vezes voce deseja realizar a verificacao? ";
    cin >> k;

    while (k <= 1)
    {
        cout << "Numero invalido, tente novamente: ";
        cin >> k;
    }

    return k;
}


void escolher_Aleatoriamente(int* k1)
{
    // Ler flores
    Flower flowers[MAX_FLOWERS];
    int numFlowers = 0;
    lerArquivo(flowers, numFlowers);

    // Verificar se k é maior que o número de flores disponíveis
    int k = *k1;
    if (k > numFlowers)
    {
        cout << "O valor de k excede o número de flores disponíveis." << endl;
        return;
    }

    // Criar um array de ponteiros para armazenar as flores selecionadas
    Flower* selectedFlowers[MAX_FLOWERS];

    // Gerar k índices aleatórios sem repetição
    int selectedIndices[MAX_FLOWERS];
    for (int i = 0; i < k; i++)
    {
        int randomIndex;
        bool indexExists;

        do
        {
            indexExists = false;
            randomIndex = rand() % numFlowers;

            // Verificar se o índice já foi selecionado anteriormente
            for (int j = 0; j < i; j++)
            {
                if (selectedIndices[j] == randomIndex)
                {
                    indexExists = true;
                    break;
                }
            }
        } while (indexExists);

        selectedIndices[i] = randomIndex;
        selectedFlowers[i] = &flowers[randomIndex];
    }

    // Imprimir as flores selecionadas
    for (int i = 0; i < k; i++)
    {
        cout << "Flower " << i + 1 << ": " << endl;
        cout << "Length: " << selectedFlowers[i]->length << endl;
        cout << "Width: " << selectedFlowers[i]->width << endl;
        cout << "Variety: " << selectedFlowers[i]->variety << endl;
        cout << endl;
    }
}


int main()
{

    int k = recebeK();

    escolher_Aleatoriamente(&k);


    return 0;
}
