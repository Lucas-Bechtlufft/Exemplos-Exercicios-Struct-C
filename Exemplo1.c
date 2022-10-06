/* Exercício struct - Distância viagem
struct caminho
{
 int distancia;
 char inicio[50];
 char fim[50];
 int ordem;
};
Criar um programa em C que possa armazenar um vetor da struct "caminho", com até 6 estruturas,
que irão armazenar trechos de uma viagem indicando a cidade inicial e a cidade final.
· Criar uma função para solicitar na tela as estruturas e armazenar no vetor.
· Identificar e imprimir na tela qual é a distância total da viagem, e os pontos de parada em
cada cidade, na ordem correta da viagem */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL 3

struct caminho
{
  int distancia;
  char inicio[50];
  char fim[50];
  int ordem;
};

struct caminho BuscaCaminho()
{
  struct caminho oCaminho;

  printf("\nInforme o Inicio ");
  scanf("%s", oCaminho.inicio);
  printf("\nInforme o Final ");
  scanf("%s", oCaminho.fim);
  printf("\nInforme a distancia ");
  scanf("%d", &oCaminho.distancia);
  printf("\nInforme a ordem ");
  scanf("%d", &oCaminho.ordem);

  return oCaminho;
};

void Imprime(struct caminho oCaminho)
{
  printf("\n%d - De: %s para %s - %d KM\n", oCaminho.ordem, oCaminho.inicio, oCaminho.fim, oCaminho.distancia);
}
int BuscaOrdem(struct caminho oCaminho, int ordem)
{
  if (oCaminho.ordem == ordem)
    return 1;

  return 0;
}

int main()
{

  struct caminho umCaminho;
  struct caminho Viagem[10];
  int x, y, ordem = 0, distanciaTotal = 0;

  for (x = 0; x < TOTAL; x++)
  {
    Viagem[x] = BuscaCaminho();
  }

  for (x = 0; x < TOTAL; x++)
  {
    distanciaTotal += Viagem[x].distancia;
  }

  for (y = 0; y < TOTAL; y++)
  {
    ordem++;

    for (x = 0; x < TOTAL; x++)
    {
      if (BuscaOrdem(Viagem[x], ordem) == 1)
      {
        Imprime(Viagem[x]);
        break;
      }
    }
  }
  printf("\nDistancia total da viagem : %d\n", distanciaTotal);

  return 0;
}
