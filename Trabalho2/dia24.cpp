#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>

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

    string line = "";              // pula o cabeçalho
    getline(inputFile, line); 

    while (getline(inputFile, line))
    {
        if (numFlowers >= MAX_FLOWERS) //contador é maior que o número de flores na tabela
            break;

        string lengthStr, widthStr, variety;
        stringstream inputString(line); // inicializando um objeto do tipo stringstream e armazenando as aspas duplas dentro dele
        
        getline(inputString, lengthStr, ','); // delimita o quanto o getline está lendo
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

// Função para calcular a distância euclidiana entre duas flores
float calcularDistancia(const Flower& flower1, const Flower& flower2)
{
    float lengthDiff = flower1.length - flower2.length;
    float widthDiff = flower1.width - flower2.width;

    return sqrt(lengthDiff * lengthDiff + widthDiff * widthDiff);
}

// Função para verificar se uma flor é semelhante ao representante
bool ehSemelhante(const Flower& flower, const Flower& representative, float threshold)
{
    float distance = calcularDistancia(flower, representative);
    return distance <= threshold;
}

// Função para selecionar um representante aleatório
Flower selecionarRepresentanteAleatorio(Flower flowers[], int numFlowers)
{
    int randomIndex = rand() % numFlowers;
    return flowers[randomIndex];
}

// Função para criar grupos
void criaGrupos(Flower flowers[], int numFlowers, int k, float threshold)
{
    for (int i = 1; i <= k; i++)
    {
        cout << "===== GRUPO " << i << " =====" << endl;

        Flower representative = selecionarRepresentanteAleatorio(flowers, numFlowers);

        cout << "Representative:" << endl;
        cout << "Length: " << representative.length << endl;
        cout << "Width: " << representative.width << endl;
        cout << "Variety: " << representative.variety << endl;

        cout << endl << "Outras flores:" << endl;

        int numOtherFlowers = 0;
        for (int j = 0; j < numFlowers; j++)
        {
            if (ehSemelhante(flowers[j], representative, threshold))
            {
                if (numOtherFlowers == 0)
                {
                    cout << "Length: " << flowers[j].length << endl;
                    cout << "Width: " << flowers[j].width << endl;
                    cout << "Variety: " << flowers[j].variety << endl;
                }
                else
                {
                    cout << endl << "Length: " << flowers[j].length << endl;
                    cout << "Width: " << flowers[j].width << endl;
                    cout << "Variety: " << flowers[j].variety << endl;
                }

                numOtherFlowers++;
            }
        }

        cout << endl;
    }
}

void arquivo_Euclidiano(Flower distancia[], int contador)
{

ofstream file("resultado.csv");
        for(int i = 0; i <= MAX_FLOWERS; i++) 
        {
            
        }

}


int main()
{
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    Flower flowers[MAX_FLOWERS];
    int numFlowers = 0;
    lerArquivo(flowers, numFlowers);

    int k = recebeK();

    float threshold;
    cout << "Digite o valor de limiar de similaridade: ";
    cin >> threshold;

    criaGrupos(flowers, numFlowers, k, threshold);
    arquivo_Euclidiano(flowers,numFlowers);
    return 0;
}
