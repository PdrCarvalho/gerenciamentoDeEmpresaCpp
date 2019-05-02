#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
using namespace std;
#include <iostream>
class Funcionario {
 private:
 	string nome;
 	string cpf;
 	float salario;
 	string data_admissao;
 
 public:
	Funcionario(string n, string c, float s, string d);
	string getNome();
	string getCPF();
	float getSalario();
	string getDataAdmissao();
	string infoFuncionario();
	void aumento (float valor);
	void setSalario(float valor);
	
};

#endif