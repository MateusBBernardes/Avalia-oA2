#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>

using namespace std;

struct Funcionario {
    int matricula;
    string nome;
    string cargo;
    float salario;
    Funcionario* esq;
    Funcionario* dir;
};

Funcionario* criar(int m, string n, string c, float s) {
    Funcionario* novo = new Funcionario;
    novo->matricula = m;
    novo->nome = n;
    novo->cargo = c;
    novo->salario = s;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Funcionario* inserir(Funcionario* raiz, int m, string n, string c, float s) {
    if (raiz == NULL) return criar(m, n, c, s);

    if (m < raiz->matricula)
        raiz->esq = inserir(raiz->esq, m, n, c, s);
    else
        raiz->dir = inserir(raiz->dir, m, n, c, s);

    return raiz;
}

Funcionario* buscar(Funcionario* raiz, int m) {
    if (raiz == NULL || raiz->matricula == m) return raiz;

    if (m < raiz->matricula)
        return buscar(raiz->esq, m);
    else
        return buscar(raiz->dir, m);
}

void atualizar(Funcionario* raiz, int m) {
    Funcionario* f = buscar(raiz, m);

    if (f != NULL) {
        cout << "Novo nome: ";
        cin >> f->nome;

        cout << "Novo cargo: ";
        cin >> f->cargo;

        cout << "Novo salario: ";
        cin >> f->salario;

        cout << "Atualizado!\n";
    } else {
        cout << "Nao encontrado!\n";
    }
}

void listar(Funcionario* raiz) {
    if (raiz != NULL) {
        listar(raiz->esq);

        cout << "\nMatricula: " << raiz->matricula << endl;
        cout << "Nome: " << raiz->nome << endl;
        cout << "Cargo: " << raiz->cargo << endl;
        cout << "Salario: " << raiz->salario << endl;

        listar(raiz->dir);
    }
}

#endif
