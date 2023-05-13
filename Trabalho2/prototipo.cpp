
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

// Definição da estrutura de dados para representar uam flor
struct Flor{
 double largura_petala;
    double altura_petala;
    int especie;
    int grupo;
};

 // Leitura do valor de k
  int k;
  std::cout << "Digite o número de grupos (k > 1): ";
  std::cin >> k;

  if (k <= 1) {
    std::cout << "O número de grupos deve ser maior que 1." << std::endl;
    return 0;
  }

   // Escolher aleatoriamente k flores como representantes iniciais
  std::random_shuffle(flowers.begin(), flowers.end());
  for (int i = 0; i < k; i++) {
    flowers[i].group = i;
  }


// Função para ler os dados do arquivo e armazenar em um vetor
Flor* lerDados(int& n) {
    ifstream arquivo("dados.csv");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    arquivo >> n; // primeiro número no arquivo é o número de flores
    Flor* flores = new Flor[n];

    for (int i = 0; i < n; i++) {
        arquivo >> flores[i].largura_petala >> flores[i].altura_petala >> flores[i].especie;
    }

    arquivo.close();

    return flores;
}



// Atualiza o representante de um grupo com o ponto médio das flores daquele grupo
void updateGroupRepresentative(Flor **flores, int numFlores, int grupo) {
    double avgWidth = 0;
    double avgHeight = 0;
    int count = 0

// Função para calcular a distância euclidiana entre duas flores
double Distancia (Flor f1, Flor f2) {
  double distancia = sqrt(pow(f1.largura da flor 1 - f2.altura da flor 2, 2) + pow(f1.altura da flor 1 - f2.altura da flor 2, 2));
  return distancia;

}

  // Soma as larguras e alturas das flores no grupo
    for (int i = 0; i < flores.size(); i++) {
        if (flowers[i].group == group) {
            avgAltura += flores[i].petalAltura;
            avgLargura += flores[i].petalLargura;
            count++;
        }
    }

    // Calcula a média das larguras e alturas das flores no grupo
    if (count > 0) {
        avgLargura /= count;
        avgAltura /= count;
    }

    // Define o representante do grupo com a média das larguras e alturas
    for (int i = 0; i < flores.size(); i++) {
        if (flores[i].grupo == grupo) {
            flores[i].petalAltura = avgAltura;
            flores[i].petalLargura = avgLargura;
        }
    }
}

// Função para atualizar o representante de um grupo
void updateGroupRepresentative(Flor* flores, int size, int group, Flor& representative) {
int count = 0;
double totalAltura = 0.0;
double totalLargura = 0.0;

for (int i = 0; i < size; i++) {
Flower flower = flowers[i];
if (flower.group == group) {
count++;
totalLargura += flower.largura;
totalAltura += flower.altura;
}
}

representative.Largura = totalLargura / count;
representative.Altura = totalAltura / count;
}

// Função para ler os dados do arquivo e armazenar em um vetor
Flor* lerDados(int& n) {
    ifstream arquivo("dados.csv");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    arquivo >> n; // primeiro número no arquivo é o número de flores
    Flor* flores = new Flor[n];

    for (int i = 0; i < n; i++) {
        arquivo >> flores[i].largura_petala >> flores[i].altura_petala >> flores[i].especie;
    }

    arquivo.close();

    return flores;
}

// Função para alocar cada flor ao grupo mais próximo
void alocarAoGrupoMaisProximo(int k, int n, Flor* flores, Flor* representantes) {
    for (int i = 0; i < n; i++) {
        double menor_distancia = calcularDistancia(flores[i], representantes[0]);
        int grupo_mais_proximo = 0;

        for (int j = 1; j < k; j++) {
            double distancia = calcularDistancia(flores[i], representantes[j]);

            if (distancia < menor_distancia) {
                menor_distancia = distancia;
                grupo_mais_proximo = j;
            }
        }

        flores[i].grupo = grupo_mais_proximo;
    }
}


// Estrutura para representar uma flor
struct Flower {
  double width;
  double height;
  int group;
};

// Função para calcular a distância euclidiana entre duas flores
double euclideanDistance(Flower f1, Flower f2) {
  double distance = sqrt(pow(f1.width - f2.width, 2) + pow(f1.height - f2.height, 2));
  return distance;
}

// Função para atualizar o representante de um grupo
Flower updateGroupRepresentative(std::vector<Flower>& flowers, int group) {
  int count = 0;
  double totalWidth = 0.0;
  double totalHeight = 0.0;

  for (Flower flower : flowers) {
    if (flower.group == group) {
      count++;
      totalWidth += flower.width;
      totalHeight += flower.height;
    }
  }

  Flower representative;
  representative.width = totalWidth / count;
  representative.height = totalHeight / count;

  return representative;
}

int main() {
  // Ler o arquivo de dados
  std::ifstream dataFile("data.txt");
  if (!dataFile.is_open()) {
    std::cout << "Erro ao abrir o arquivo de dados." << std::endl;
    return 0;
  }

  std::vector<Flower> flowers;
  double width, height;
  int species;
  while (dataFile >> width >> height >> species) {
    Flower flower;
    flower.width = width;
    flower.height = height;
    flower.group = -1; // grupo não definido ainda
    flowers.push_back(flower);
  }

  dataFile.close();

  // Ler o valor de k
  int k;
  std::cout << "Digite o número de grupos (k > 1): ";
  std::cin >> k;

  if (k <= 1) {
    std::cout << "O número de grupos deve ser maior que 1." << std::endl;
    return 0;
  }

  // Escolher aleatoriamente k flores como representantes iniciais
  std::random_shuffle(flowers.begin(), flowers.end());
  for (int i = 0; i < k; i++) {
    flowers[i].group = i;
  }

  // Alocar cada flor ao grupo mais próximo
  bool hasChanged = true;
  int iterations = 0;
  while (hasChanged && iterations < 1000) {
    hasChanged = false;

    for (Flower& flower : flowers) {
      double minDistance = INFINITY;
      int minGroup = -1;

      for (int i = 0; i < k; i++) {
        double distance = euclideanDistance(flower, flowers[i]);
        if (distance < minDistance) {
          minDistance = distance;
          minGroup = i;
        }
      }

      if (flower.group != minGroup) {
        flower.group = minGroup;
        hasChanged = true;
      }
    }


int main() {
    // Lê o arquivo de dados que contém informações sobre as flores
    vector<Flower> flowers;
    ifstream inFile("flower_data.txt");
    double petalWidth, petalHeight;
    while (inFile >> petalWidth >> petalHeight) {
        Flower f;
        f.petalWidth = petalWidth;
        f.petalHeight = petalHeight;
        f.group = 0;
        flowers.push_back(f);
    }
    inFile.close();

    // Pergunta ao usuário o número de grupos (k) que deseja formar
    int k;
    cout << "Digite o número de grupos (k) que deseja formar: ";
    cin >> k;

    // Escolhe aleatoriamente k flores do conjunto de dados para representar cada grupo
    srand(time(0));
    for (int i = 0; i < k; i++) {
        int index = rand() % flowers.size();
        flowers[index].group = i+1;
    }


    // Repete os passos 4 e 5 várias vezes até que as flores parem de mudar de grupo ou um número máximo de iterações seja atingido
    int maxIterations = 100;
    int iterationCount = 0;
    bool moved;
    do {
        moved = false;

        // Para cada flor do conjunto de dados, aloca-a ao grupo mais próximo, usando a distância euclidiana
        for (int i = 0; i < flowers.size(); i++) {
            double minDist = euclideanDistance(flowers[i], flowers[0]);
19:17


