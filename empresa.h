#ifndef EMPRESA_H
#define EMPRESA_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include "funcionario.h"
using namespace std;

class Empresa {
 private:
 	string nome;
 	string cnpj;
	map<string,Funcionario> func;	
 public:
	static int quantEmpresa;
	static int quantFunc;
 	Empresa(string n, string c );
	string getNome();
	string getCNPJ();
	map<string,Funcionario> getListFuncionario();
	string infoEmpresa();
	void addFuncionario( Funcionario funcionario);
	void showFuncionario();
	int checkFuncionario(Funcionario funcionario);
	void aumento(int valor);
	static float quantPorEmpresa();
	friend std::ostream& operator<< (std::ostream &o, Empresa  t);
};
#endif