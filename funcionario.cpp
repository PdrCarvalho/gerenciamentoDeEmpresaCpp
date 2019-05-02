#include <iostream>
#include "funcionario.h"
using namespace std;
Funcionario::Funcionario(string n, string c, float s, string d){
	nome = n;
 	cpf = c;
 	salario = s;
 	data_admissao = d;
}

string Funcionario::getNome(){
	return nome;
}

string Funcionario::getCPF(){
	return cpf;
}
 
float Funcionario::getSalario(){
	return salario;
}

string Funcionario::getDataAdmissao(){
	return data_admissao;
}

string Funcionario::infoFuncionario(){
	return nome+"\n"+cpf+"\n"+to_string(salario)+"\n"+data_admissao;
}

void Funcionario::aumento (float valor){
	salario = salario * (1 + (valor/100));

}
void Funcionario::setSalario(float valor){
	salario = valor;
}