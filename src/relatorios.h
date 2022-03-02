#ifndef RELATORIOS_H_
#define RELATORIOS_H_

#include "./candidato.h"
#include "./partido.h"
#include <cstddef>
#include <vector>

using std::size_t;
using std::vector;

class Relatorios {
private:
  static size_t
  calcula_numero_vagas(const vector<Candidato *> &lista_candidatos);
  static double calcula_porcentagem(double valor, double total);

public:
  static void relatorio1(const vector<Candidato *> &lista_candidatos);
  static void relatorio2(vector<Candidato *> &lista_candidatos);
  static void relatorio3(vector<Candidato *> &lista_candidatos);
  static void relatorio11(const vector<Partido *> &lista_partidos);
};

#endif // !RELATORIOS_H_
