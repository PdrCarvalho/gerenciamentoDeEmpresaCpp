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