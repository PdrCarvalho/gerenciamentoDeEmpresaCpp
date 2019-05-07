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
     system("clear");
     showOption();
     int select ;
     while(1){
        
        cout<< "Digite o comando ou Digite 7 para ver as opções"<<endl;
        cin>>select;
        if(select== 1){ adicionarEmpresa();}
        else if (select== 2){adicionarFuncionario();}
        else if (select== 3){aumento();}
        else if (select== 4){showEmpresas();}
        else if (select== 5){mostrarFuncionario();}
        else if (select== 6){cout<< Empresa::quantPorEmpresa()<<endl;}
        else if (select== 7){showOption();}
        else if (select== 8){mostrarProData();}
        else if (select== 9){break;}
        system("clear");
        
     }
     cout<< "Bye Bye"<<endl;
 }
 void Sebrae::showOption(){
     cout<<"     1-Criar empresa \n\\
     2-Adicionar Funcionario\n\\
     3-Aumento\n\\
     4-Mostrar Empresas\n\\
     5-Mostrar Funcionarios\n\\
     6-Mostrar media de funcionario por empresa\n\\
     7-Mostrar opções\n\\
     8-Mostrar funcionario por periodo de experiencia\n\\
     9-Exit"<<endl;
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
        cout<< "\n"<<endl;
        Funcionario *func = new Funcionario(nome,cpf,salario);
        cout<<"\n"<< endl;
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
 struct tm Sebrae::ajusteData(){
     struct tm tempo ;
     int select;
    cout<< "Selecione opção de data de admição \n0-usar data atual\n1-digitar data"<<endl;
    cin>>select;
    if(select== 1){
        int dado;
        cout<<"Digite ano de admiÇão"<<endl;
        cin >> dado;
        tempo.tm_year = dado - 1900;
        cout<<"Digite mes de admiÇão como valor entre 0-11"<<endl;
        cin >> dado;
        tempo.tm_mon= dado;
        cout<<"Digite dia de admiÇão como valor entre 1-31"<<endl;
        cin >> dado;
        tempo.tm_mday = dado; 
    }else{
        time_t atual;
        time(&atual);
        tempo = *localtime(&atual);
    }
     return tempo;
 }
 void Sebrae::mostrarProData(){
     string cnpj;
     int dias ;
     showEmpresas();
     cout<< "Digite o CNPJ"<<endl;
     cin>> cnpj;
     auto empresa = empresas.find(cnpj);
     if(empresa->first == cnpj ){
         cout<<"Digite o range de dias partindo da data atual"<<endl;
         cin>>dias;
         empresa->second.mostrarPorData(dias);
     }
     else{
        cout<< "Empresa não existente"<<endl;
     }
 }