#ifndef SEBRAE_H
#define SEBRAE_H
#include "empresa.h"
class Sebrae {
    private:
    map<string,Empresa> empresas;
    public:
    void adicionarEmpresa ();
    void menu();
    int checkEmpresa(string cnpj);
    void showEmpresas();

};

#endif