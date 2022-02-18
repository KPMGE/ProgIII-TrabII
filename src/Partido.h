#include <iostream>
using std::string;

class Partido {
private:
  int numero_partido;
  int votos_legenda;
  string nome_partido;
  string sigla_partido;

public:
  Partido();
  Partido(const int &numero_partido, const int &votos_legenda,
          const string &nome_partido, const string &sigla_partido);

  const int &get_votos_legenda() const;
  const int &get_numero_partido() const;
  const string &get_nome_partido() const;
  const string &get_sigla_partido() const;
};
