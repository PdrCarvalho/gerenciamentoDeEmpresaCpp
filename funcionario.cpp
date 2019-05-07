#include <iostream>
#include "funcionario.h"
using namespace std;
Funcionario::Funcionario(string n, string c, float s){
	nome = n;
 	cpf = c;
 	salario = s;
	struct tm *tempo;
	int dado;
    cout<<"Digite ano de admiÇão"<<endl;
    cin >> dado;
    tempo->tm_year = dado - 1900;
    cout<<"Digite mes de admiÇão como valor entre 0-11"<<endl;
    cin >> dado;
    tempo->tm_mon= dado;
    cout<<"Digite dia de admiÇão como valor entre 1-31"<<endl;
    cin >> dado;
    tempo->tm_mday = dado;
 	data_admissao =  mktime(tempo);
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



string Funcionario::infoFuncionario(){
	return nome+"\n"+cpf+"\n"+to_string(salario)+"\n"+ctime(&data_admissao);
}

void Funcionario::aumento (float valor){
	salario = salario * (1 + (valor/100));

}
void Funcionario::setSalario(float valor){
	salario = valor;
}
time_t  Funcionario::getDataAdmissao(){
	return data_admissao;
}

string Funcionario::dataToString(){
	return ctime(&data_admissao);
}
void Funcionario::showdata(){
	cout<< ctime(&data_admissao);
}