#include "./partido.h"

Partido::Partido(const int &numero_partido, const int &votos_legenda,
                 const string &nome_partido, const string &sigla_partido) {
  this->nome_partido = nome_partido;
  this->votos_legenda = votos_legenda;
  this->sigla_partido = sigla_partido;
  this->numero_partido = numero_partido;
}

void Partido::adiciona_candidato(Candidato *novo_candidato) {
  this->candidatos.push_back(novo_candidato);
}

int Partido::get_numero_partido() const { return this->numero_partido; }
int Partido::get_votos_legenda() const { return this->votos_legenda; }
const string &Partido::get_nome_partido() const { return this->nome_partido; }
const string &Partido::get_sigla_partido() const { return this->sigla_partido; }
