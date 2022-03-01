#ifndef CANDIDATO_H_
#define CANDIDATO_H_

#include "./partido.h"
#include <string>
#include <vector>

using std::string;

class Candidato {
private:
  int numero;
  int votos_nominais;
  string situacao;
  string nome;
  string nome_urna;
  string sexo;
  string data_nascimento;
  string destino_voto;
  int numero_partido;
  Partido *partido;

public:
  Candidato(int numero, int votos_nominais, const string &situacao,
            const string &nome, const string &nome_urna, const string &sexo,
            const string &data_nascimento, const string &destino_voto,
            int numero_partido);

  void adiciona_partido(Partido *novo_partido);
  int get_numero() const;
  int get_votos_nominais() const;
  const string &get_situacao() const;
  const string &get_nome() const;
  const string &get_nome_urna() const;
  const string &get_sexo() const;
  const string &get_data_nascimento() const;
  const string &get_destino_voto() const;
  int get_numero_partido() const;
  const Partido *get_partido() const;
};

#endif // CANDIDATO_H_
