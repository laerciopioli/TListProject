#include "TList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

TList::TList(int tam)
{
    if (tam <= 0) tam = 1;
    m = tam;
    ultimo = 0;
    vet = new float[m];
}

TList::~TList()
{
    delete [] vet;
}

void TList::atribui(int k, float val)
{
    if (k >= 0 && k < ultimo)
    {
        vet[k] = val;
    }
    else
    {
        cout << "Indice Invalido!" << endl;
    }
}

// inserir em posicao k (0..ultimo) — inserir no final = k == ultimo
void TList::InsereK(int k, float val)
{
    if (ultimo >= m)
    {
        cout << "Lista Cheia! Nao é possivel inserir." << endl;
        return;
    }
    if (k >= 0 && k <= ultimo)
    {
        // desloca para a direita os elementos a partir de k
        for (int i = ultimo - 1; i >= k; i--)
        {
            vet[i + 1] = vet[i];
        }
        vet[k] = val;
        ultimo++;
    }
    else
    {
        cout << "Indice Invalido!" << endl;
    }
}

float TList::consulta(int k)
{
    if (k >= 0 && k < ultimo)
    {
        return vet[k];
    }
    else
    {
        cout << "Indice invalido!" << endl;
        return 0.0f; // valor simbólico — avisa com mensagem
    }
}

void TList::InsereUlt(float val)
{
    if (ultimo >= m)
    {
        cout << "Lista Cheia! Nao é possivel inserir." << endl;
        return;
    }
    vet[ultimo] = val;
    ultimo++;
}

void TList::EliminaUlt()
{
    if (ultimo == 0)
    {
        cout << "Lista Vazia" << endl;
        return;
    }
    ultimo--;
}

void TList::EliminaK(int k)
{
    if (k >= 0 && k < ultimo)
    {
        for (int i = k; i < ultimo - 1; i++)
        {
            vet[i] = vet[i + 1];
        }
        ultimo--;
    }
    else
    {
        cout << "Indice Invalido!" << endl;
    }
}

void TList::imprime()
{
    if (ultimo == 0)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    cout << "Lista: ";
    for (int aux = 0; aux < ultimo; aux++)
    {
        cout << "[ " << vet[aux] << " ]";
        if (aux < ultimo - 1)
            cout << " -> ";
    }
    cout << " -> NULL" << endl;
}

void TList::insertion()
{
    // ordena apenas os 'ultimo' elementos válidos
    for (int i = 1; i < ultimo; i++)
    {
        float pivo = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > pivo)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = pivo;
    }
}
