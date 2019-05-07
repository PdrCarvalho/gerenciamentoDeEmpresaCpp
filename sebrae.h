#ifndef SEBRAE_H
#define SEBRAE_H
#include "empresa.h"
class Sebrae {
    private:
    map<string,Empresa> empresas;
    public:
    void adicionarEmpresa ();
    int checkEmpresa(string cnpj);
    void showEmpresas();
    void Menu();
    void showOption();
    void adicionarFuncionario();
    void mostrarFuncionario();
    void aumento();
    struct tm ajusteData();
    void mostrarProData();

};

#endif