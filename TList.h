#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED
#include <cstdlib>

class TList
{
private:
    int m;         // capacidade máxima
    int ultimo;    // número de elementos válidos (0..ultimo-1)
    float *vet;
public:
    TList(int tam);
    void atribui(int k,float val);
    void InsereK(int k,float val);
    float consulta(int k);
    void InsereUlt(float val);
    void EliminaUlt();
    void EliminaK(int k);
    void imprime();
    void insertion(); // insertion sort
    ~TList();
    int tamanho() const { return ultimo; }    // útil para verificação
    int capacidade() const { return m; }
    int tamanhoAtual() { return ultimo; }
    int capacidade() { return m; }
};

#endif // TLIST_H_INCLUDED
