#ifndef RELATORIOS_H_
#define RELATORIOS_H_

#include "./candidato.h"
#include <vector>

using std::vector;

class Relatorios {
private:
  static unsigned int
  calcula_numero_vagas(const vector<Candidato *> &lista_candidatos);

public:
  static void relatorio1(const vector<Candidato *> &lista_candidatos);
  static void relatorio2(vector<Candidato *> &lista_candidatos);
  static void relatorio3(vector<Candidato *> &lista_candidatos);
};

#endif // !RELATORIOS_H_
