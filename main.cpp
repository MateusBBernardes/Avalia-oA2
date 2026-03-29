#include <iostream>
#include "arvore.h"

using namespace std;

int main() {

    Funcionario* raiz = NULL;

    int op;
    int matricula;
    string nome, cargo;
    float salario;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir\n";
        cout << "2 - Atualizar\n";
        cout << "3 - Buscar\n";
        cout << "4 - Listar (em ordem)\n";
        cout << "0 - Sair\n";

        cout << "Opcao: ";
        cin >> op;

        switch(op) {

            case 1:
                cout << "Matricula: ";
                cin >> matricula;

                cout << "Nome: ";
                cin >> nome;

                cout << "Cargo: ";
                cin >> cargo;

                cout << "Salario: ";
                cin >> salario;

                raiz = inserir(raiz, matricula, nome, cargo, salario);
                break;

            case 2:
                cout << "Matricula: ";
                cin >> matricula;
                atualizar(raiz, matricula);
                break;

            case 3: {
                cout << "Matricula: ";
                cin >> matricula;

                Funcionario* f = buscar(raiz, matricula);

                if (f != NULL) {
                    cout << "Nome: " << f->nome << endl;
                    cout << "Cargo: " << f->cargo << endl;
                    cout << "Salario: " << f->salario << endl;
                } else {
                    cout << "Nao encontrado!\n";
                }
                break;
            }

            case 4:
                listar(raiz);
                break;

            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while(op != 0);

    return 0;
}
