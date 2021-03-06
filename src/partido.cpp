#include "./partido.h"
#include "./candidato.h"

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

const Candidato *Partido::get_candidato_mais_votado() const {
  Candidato *mais_votado = this->candidatos.at(0);

  for (Candidato *c : this->candidatos) {
    if (c->get_votos_nominais() > mais_votado->get_votos_nominais()) {
      mais_votado = c;
    }
  }

  return mais_votado;
}

int Partido::get_numero_partido() const { return this->numero_partido; }

bool Partido::valido() const { return this->get_total_votos_validos() > 0; }

int Partido::get_votos_legenda() const { return this->votos_legenda; }

const string &Partido::get_nome_partido() const { return this->nome_partido; }

const string &Partido::get_sigla_partido() const { return this->sigla_partido; }

size_t Partido::get_total_votos_validos() const {
  size_t total = 0;

  for (const Candidato *c : this->candidatos) {
    if (c->get_destino_voto() == "Válido") {
      total += c->get_votos_nominais();
    }
  }

  return total + this->votos_legenda;
}
