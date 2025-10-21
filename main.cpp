#include <iostream>
#include <limits>
#include "TList.h"
using namespace std;

int main()
{
    TList *a = nullptr;
    int opcao = -1;
    int tam = 0, num = 0, pos = 0, qtd = 0;

    do
    {
        cout << "\n======= MENU LISTA =======\n";
        cout << "0 - Inicializar Lista\n";
        cout << "1 - Inserir elemento no final\n";
        cout << "2 - Inserir elemento em posicao K\n";
        cout << "3 - Eliminar ultimo elemento\n";
        cout << "4 - Eliminar elemento em posicao K\n";
        cout << "5 - Imprimir lista\n";
        cout << "6 - Ordenar lista (Insertion Sort)\n";
        cout << "7 - Sair\n";
        cout << "==========================\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> opcao))
        {
            // entrada inválida: limpa e continua
            cout << "Entrada invalida! Digite um numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcao)
        {
            case 0:
                cout << "Digite o tamanho inicial da lista: ";
                if (!(cin >> tam))
                {
                    cout << "Entrada invalida! Voltando ao menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (tam <= 0)
                {
                    cout << "Tamanho invalido!\n";
                    break;
                }
                if (a != nullptr)
                {
                    delete a;
                    a = nullptr;
                    cout << "Lista antiga destruida.\n";
                }
                a = new TList(tam);
                cout << "Lista inicializada com capacidade " << tam << ".\n";
                break;

            case 1: {
                if (a == nullptr) {
                    cout << "Lista nao inicializada!\n";
                    break;
                }

                int qtd;
                cout << "Quantos elementos deseja inserir? ";
                cin >> qtd;

                int espacoDisponivel = a->capacidade() - a->tamanho(); // você precisa criar esses métodos
                if (qtd > espacoDisponivel) {
                    cout << "Aviso: Só é possivel inserir " << espacoDisponivel << " elementos.\n";
                    qtd = espacoDisponivel; // limita a quantidade
                }

                for (int i = 0; i < qtd; i++) {
                    float num;
                    cout << "Digite o numero " << i + 1 << ": ";
                    cin >> num;
                    a->InsereUlt(num);
                }

                if (qtd == 0)
                    cout << "Lista cheia! Nao é possivel inserir mais elementos.\n";


                break;
            }
            case 2:
                if (a == nullptr)
                {
                    cout << "Crie a lista primeiro (opcao 0)!\n";
                    break;
                }
                cout << "Digite a posicao (0 .. " << a->tamanho() << "): ";
                if (!(cin >> pos))
                {
                    cout << "Entrada invalida!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "Digite o numero: ";
                if (!(cin >> num))
                {
                    cout << "Entrada invalida!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                a->InsereK(pos, num);
                break;

            case 3:
                if (a == nullptr)
                {
                    cout << "Crie a lista primeiro (opcao 0)!\n";
                    break;
                }
                a->EliminaUlt();
                break;

            case 4:
                if (a == nullptr)
                {
                    cout << "Crie a lista primeiro (opcao 0)!\n";
                    break;
                }
                cout << "Digite a posicao a remover (0 .. " << a->tamanho()-1 << "): ";
                if (!(cin >> pos))
                {
                    cout << "Entrada invalida!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                a->EliminaK(pos);
                break;

            case 5:
                if (a == nullptr)
                {
                    cout << "Crie a lista primeiro (opcao 0)!\n";
                    break;
                }
                a->imprime();
                break;

            case 6:
                if (a == nullptr)
                {
                    cout << "Crie a lista primeiro (opcao 0)!\n";
                    break;
                }
                a->insertion();
                cout << "Lista ordenada com sucesso!\n";
                break;

            case 7:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }

    } while (opcao != 7);

    delete a;
    return 0;
}
