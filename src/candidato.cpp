#include "./candidato.h"
#include "partido.h"
#include <vector>

using std::vector;

Candidato::Candidato(int numero, int votos_nominais, const string &situacao,
                     const string &nome, const string &nome_urna,
                     const string &sexo, const Data &data_nascimento,
                     const string &destino_voto, int numero_partido) {
  this->numero = numero;
  this->votos_nominais = votos_nominais;
  this->situacao = situacao;
  this->nome = nome;
  this->nome_urna = nome_urna;
  this->sexo = sexo;
  this->data_nascimento = data_nascimento;
  this->destino_voto = destino_voto;
  this->numero_partido = numero_partido;
}

bool Candidato::eleito() const { return this->situacao == "Eleito"; }

unsigned short Candidato::calcula_idade_em_anos(const Data &data) const {
  return data.get_ano() - data_nascimento.get_ano();
}

bool Candidato::mais_velho(const Candidato *const c) const {
  // dados de ano, mes e dia de nascimento do candidato a ser comparado
  const Data &nascimento_c = c->get_data_nascimento();
  int ano_c = nascimento_c.get_ano();
  int mes_c = nascimento_c.get_mes();
  int dia_c = nascimento_c.get_dia();

  // se o ano de nascimento de c for igual ao do candidato atual
  if (this->data_nascimento.get_ano() == ano_c) {

    // se o mes de nascimento de c for igual ao do candidato atual, então
    // compare o dia.
    if (this->data_nascimento.get_mes() == mes_c) {
      return this->data_nascimento.get_dia() < dia_c;
    }

    // se o mes de nascimento do candidato atual for menor, ele é mais velho
    if (this->data_nascimento.get_mes() < mes_c) {
      return true;
    }

    return false;
  }

  // se o ano de nascimento do candidato atual é menor, ele é mais velho
  return this->data_nascimento.get_ano() < ano_c;
}

void Candidato::adiciona_partido(Partido *novo_partido) {
  this->partido = novo_partido;
}

int Candidato::get_numero() const { return this->numero; }

size_t Candidato::get_votos_nominais() const { return this->votos_nominais; }

const string &Candidato::get_situacao() const { return this->situacao; }

const string &Candidato::get_nome() const { return this->nome; }

const string &Candidato::get_nome_urna() const { return this->nome_urna; }

const string &Candidato::get_sexo() const { return this->sexo; }

const Data &Candidato::get_data_nascimento() const {
  return this->data_nascimento;
}

const string &Candidato::get_destino_voto() const { return this->destino_voto; }

int Candidato::get_numero_partido() const { return this->numero_partido; }

const Partido *Candidato::get_partido() const { return this->partido; }

const vector<Candidato *> &Partido::get_candidatos() const {
  return this->candidatos;
}
