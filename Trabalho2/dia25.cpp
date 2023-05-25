#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_FLOWERS = 150;

struct Flower
{
    float length;
    float width;
    string variety;
    int group;
};

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

        float length = stof(lengthStr);
        float width = stof(widthStr);

        flowers[numFlowers].length = length;
        flowers[numFlowers].width = width;
        flowers[numFlowers].variety = variety;

        numFlowers++;
    }

    inputFile.close();
}

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

float calcularDistancia(const Flower& f1, const Flower& f2)
{
    float lengthDiff = f1.length - f2.length;
    float widthDiff = f1.width - f2.width;
    return sqrt(lengthDiff * lengthDiff + widthDiff * widthDiff);
}

Flower selecionarRepresentanteAleatorio(Flower flowers[], int numFlowers)
{
    int randomIndex = rand() % numFlowers;
    return flowers[randomIndex];
}

void atualizarRepresentante(Flower& representative, const Flower flowers[], int numFlowers, int group)
{
    float sumLength = 0.0f;
    float sumWidth = 0.0f;
    int count = 0;

    for (int i = 0; i < numFlowers; i++)
    {
        if (flowers[i].group == group)
        {
            sumLength += flowers[i].length;
            sumWidth += flowers[i].width;
            count++;
        }
    }

    if (count > 0)
    {
        representative.length = sumLength / count;
        representative.width = sumWidth / count;
    }
}

void gerarGrupos(Flower flowers[], int numFlowers, int k, int x)
{
    Flower* representatives = new Flower[k];

    for (int i = 0; i < k; i++)
    {
        representatives[i] = selecionarRepresentanteAleatorio(flowers, numFlowers);
    }

    for (int iter = 0; iter < x; iter++)
    {
        for (int i = 0; i < numFlowers; i++)
        {
            float minDistance = -1;
            int closestGroup = -1;

            for (int j = 0; j < k; j++)
            {
                float distance = calcularDistancia(flowers[i], representatives[j]);
                if (minDistance == -1 || distance < minDistance)
                {
                    minDistance = distance;
                    closestGroup = j;
                }
            }

            flowers[i].group = closestGroup;
        }

        for (int i = 0; i < k; i++)
        {
            float sumLength = 0.0f;
            float sumWidth = 0.0f;
            int count = 0;

            for (int j = 0; j < numFlowers; j++)
            {
                if (flowers[j].group == i)
                {
                    sumLength += flowers[j].length;
                    sumWidth += flowers[j].width;
                    count++;
                }
            }

            if (count > 0)
            {
                representatives[i].length = sumLength / count;
                representatives[i].width = sumWidth / count;
            }
        }
    }

    delete[] representatives;
}

void escreverArquivoResultado(const Flower flowers[], int numFlowers)
{
    ofstream file("resultado.csv");

    file << "Grupo,Altura,Largura,Especie" << endl;
    for (int i = 0; i < numFlowers; i++)
    {
        file << flowers[i].group << "," << flowers[i].length << ","
             << flowers[i].width << "," << flowers[i].variety << endl;
    }

    file.close();
}

int main()
{
    srand(time(0));

    Flower flowers[MAX_FLOWERS];
    int numFlowers = 0;
    lerArquivo(flowers, numFlowers);

    int k = recebeK();
    int x; // Lê o valor de x do usuário
    cout << "Digite o valor de x: ";
    cin >> x;

    gerarGrupos(flowers, numFlowers, k, x);
    escreverArquivoResultado(flowers, numFlowers);

    return 0;
}
