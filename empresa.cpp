#include <iostream>
#include <list>
#include "empresa.h"
#include "funcionario.h"
using namespace std;

int Empresa::quantEmpresa = 0;
int Empresa::quantFunc = 0;
Empresa::Empresa(string n, string c)
{
    nome = n;
    cnpj = c;
    quantEmpresa++;
}

string Empresa::getNome()
{
    return nome;
}

string Empresa::getCNPJ()
{
    return cnpj;
}

map<string, Funcionario> Empresa::getListFuncionario()
{
    return func;
}

string Empresa::infoEmpresa()
{
    return nome + "\n" + cnpj + "\n";
}
void Empresa::addFuncionario(Funcionario funcionario)
{
    if (checkFuncionario(funcionario))
    {
        string a = funcionario.getCPF();
        func.insert(pair<string, Funcionario>(a, funcionario));
        quantFunc++;
    }
    else
    {
        cout << "Funcionario ja cadastrado" << endl;
    }
}
void Empresa::showFuncionario()
{
    for (std::map<string, Funcionario>::iterator it = func.begin(); it != func.end(); ++it)
    {
        std::cout << it->first << " " << it->second.getNome() << " " << it->second.getSalario() << '\n';
    }
}
int Empresa::checkFuncionario(Funcionario funcionario)
{
    auto b = func.find(funcionario.getCPF());
    if (b->first == funcionario.getCPF())
    {
        return 0;
    }
    return 1;
}
void Empresa::aumento(int valor)
{
    for (std::map<string, Funcionario>::iterator it = func.begin(); it != func.end(); ++it)
    {
        it->second.aumento(valor);
    }
}

float Empresa::quantPorEmpresa()
{
    return quantFunc / quantEmpresa;
}

std::ostream &operator<<(std::ostream &o, Empresa t)
{
    for (std::map<string, Funcionario>::iterator it = t.func.begin(); it != t.func.end(); ++it)
    {
        o << it->first << " " << it->second.getNome() << " " << it->second.getSalario() << '\n';
    }
    return o;
}