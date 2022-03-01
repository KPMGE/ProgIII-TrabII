#ifndef PARTIDO_H_
#define PARTIDO_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

class Candidato;

class Partido {
private:
  int numero_partido;
  int votos_legenda;
  string nome_partido;
  string sigla_partido;
  vector<Candidato *> candidatos;

public:
  Partido(const int &numero_partido, const int &votos_legenda,
          const string &nome_partido, const string &sigla_partido);
  void adiciona_candidato(Candidato *novo_candidato);
  int get_votos_legenda() const;
  int get_numero_partido() const;
  const string &get_nome_partido() const;
  const string &get_sigla_partido() const;
  const vector<Candidato *> &get_candidatos() const;
};

#endif // !PARTIDO_H_