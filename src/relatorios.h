#ifndef RELATORIOS_H_
#define RELATORIOS_H_

#include "./candidato.h"
#include <vector>

using std::vector;

class Relatorios {
public:
  static void relatorio1(const vector<Candidato *> &lista_candidatos);
  static void relatorio2(vector<Candidato *> &lista_candidatos);
};

#endif // !RELATORIOS_H_
