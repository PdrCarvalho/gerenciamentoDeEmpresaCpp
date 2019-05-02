#include "funcionario.h"
#include "empresa.h"
#include "sebrae.h"
int main()
{
  Sebrae *sebrae = new Sebrae();
  sebrae->adicionarEmpresa();
  sebrae->showEmpresas();
  sebrae->adicionarEmpresa();
  sebrae->showEmpresas();
  return 0;
}