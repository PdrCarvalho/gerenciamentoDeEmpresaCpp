#include "sebrae.h"

 void Sebrae::adicionarEmpresa(){
     string nome ;
     string cnpj;
     cout<< "digite nome da empresa"<<endl;
     cin>>nome ;
     cout<< "digite cnpj da empresa"<<endl;
     cin>>cnpj ;
     if (checkEmpresa(cnpj)){
         empresas.insert(pair<string,Empresa>(cnpj,*new Empresa(nome,cnpj)));
     }
     else {
         cout<< "Empresa ja existe"<<endl;
     }

 }
 int Sebrae::checkEmpresa(string cnpj){
    auto b = empresas.find(cnpj);
    if (b->first == cnpj)
    {
        return 0;
    }
    return 1;
 }
 void Sebrae::showEmpresas(){
     for (std::map<string, Empresa>::iterator it = empresas.begin(); it != empresas.end(); ++it)
    {
        std::cout << " " << it->second.getNome() << " " << it->second.getCNPJ() << '\n';
    }
 }
 void Sebrae::Menu(){
     showOption();
     int select ;
     while(1){
        
        cout<< "Digite o comando"<<endl;
        cin>>select;
        if(select== 1){ adicionarEmpresa();}
        else if (select== 2){adicionarFuncionario();}
        else if (select== 3){}
        else if (select== 4){showEmpresas();}
        else if (select== 5){mostrarFuncionario();}
        else if (select== 6){break;}
        
     }
     cout<< "Bye Bye"<<endl;
 }
 void Sebrae::showOption(){
     cout<<"     1-Criar empresa \n\\
     2-Adicionar Funcionario\n\\
     3-Aumento\n\\
     4-Mostrar Empresas\n\\
     5-Mostrar Funcionarios\\
     6-Exit"<<endl;
 }
 void Sebrae::adicionarFuncionario(){
     string cnpj;
     showEmpresas();
     cout<< "Digite o CNPJ"<<endl;
     cin>> cnpj;
     auto empresa = empresas.find(cnpj);
     if(empresa->first == cnpj ){
        string nome;
        float salario;
        string cpf;
        cout<< "Digite nome do funcionario"<<endl;
        cin>> nome;
        cout<< "Digite salario do funcionario" << endl;
        cin>> salario;
        cout<< "Digite cpf"<<endl;
        cin>> cpf;
        Funcionario *func = new Funcionario(nome,cpf,salario, "Qualquer data" );
        empresa->second.addFuncionario(*func);
     }
     else{
         cout<< "Empresa n existente"<<endl;
     }
     
 }

 void Sebrae::mostrarFuncionario(){
     string cnpj;
     showEmpresas();
     cout<< "Digite o CNPJ"<<endl;
     cin>> cnpj;
     auto empresa = empresas.find(cnpj);
     if(empresa->first == cnpj ){
        cout<<empresa->second<<endl;
     }
     else{
         cout<< "Empresa não existente"<<endl;
     }
 }
 void Sebrae::aumento(){
     string cnpj;
     showEmpresas();
     cout<< "Digite o CNPJ"<<endl;
     cin>> cnpj;
     auto empresa = empresas.find(cnpj);
     if(empresa->first == cnpj ){
         int aumento;
        cout<< "Digite o valor do aumento em porcentagem"<<endl;
        cin>>aumento;
        empresa->second.aumento(aumento);
        }
     else{
         cout<< "Empresa não existente"<<endl;
     }
 }