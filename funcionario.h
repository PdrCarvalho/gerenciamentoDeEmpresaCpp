#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
using namespace std;
#include <iostream>
#include "time.h"
class Funcionario {
 private:
 	string nome;
 	string cpf;
 	float salario;
 	time_t data_admissao;
 
 public:
	Funcionario(string n, string c, float s);
	string getNome();
	string getCPF();
	float getSalario();
	time_t  getDataAdmissao();
	string infoFuncionario();
	void aumento (float valor);
	void setSalario(float valor);
	string dataToString();
	void showdata();
	
};

#endif