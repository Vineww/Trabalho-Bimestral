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

int recebex()
{
//o x deve ser um valor o qual será utilizado para delimitar o quanto de vezes eu atualizarei meu representante dentro do arquivo resultado
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


float calcularDistancia()
{
    //calcula a distância euclidiana entre a altura e largura da flor selecionada aleatoriamente e os atribui em variáveis, o número de flores aleatórias depende de k
    //a distância euclidiana vai ser usada para classificar a flor conforme o ponto médio calculado a seguir
}

Flower selecionarRepresentanteAleatorio(Flower flowers[], int numFlowers)
{
    int randomIndex = rand() % numFlowers;
    return flowers[randomIndex]; 
}


void criaGrupos(Flower flowers[], int numFlowers, int k, float threshold)
{
    for (int i = 1; i <= k; i++)
    {
        Flower representative = selecionarRepresentanteAleatorio(flowers, numFlowers);
    }
}

void ponto_Medio()
{
    //o ponto médio, será a soma dos atributos numéricos de uma flor com os atributos numéricos de outra flor dividido por dois
    //será usado para classificar a flor conforme o grupo criado no resultado
}

void resultado()
{
    ofstream file("resultado.csv");
    while(!file.eof())
    {
        //cria um arquivo csv que retorna 4 colunas a primeira = grupo o qual a flor pertence, segunda = altura da flor, terceira = largura da flor e ultima a espécie.

    }
}

void atualiza_Flor()
{
    //atualiza os representantes contidos no resultado
    //trunca o arquivo de texto "resultado" e muda seus valores
}

void repete()
{
    //atualiza as flores x vezes
}

int main()
{
    srand(time(0)); 

    Flower flowers[MAX_FLOWERS];
    int numFlowers = 0;
    lerArquivo(flowers, numFlowers);

    int k = recebeK();

    float threshold;
    cout << "Digite o valor de limiar de similaridade: ";
    cin >> threshold;

    criaGrupos(flowers, numFlowers, k, threshold);

    return 0;
}
