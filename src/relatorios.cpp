#include "./relatorios.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

unsigned int
Relatorios::calcula_numero_vagas(const vector<Candidato *> &lista_candidatos) {
  int qtd_vagas = 0;

  for (const Candidato *c : lista_candidatos) {
    if (c->get_situacao() == "Eleito") {
      qtd_vagas++;
    }
  }

  return qtd_vagas;
}

void Relatorios::relatorio1(const vector<Candidato *> &lista_candidatos) {
  cout << "Número de vagas: " << calcula_numero_vagas(lista_candidatos) << endl
       << endl;
}

void Relatorios::relatorio2(vector<Candidato *> &lista_candidatos) {
  auto comp = [](Candidato const *c1, Candidato const *c2) {
    return c2->get_votos_nominais() < c1->get_votos_nominais();
  };

  std::sort(lista_candidatos.begin(), lista_candidatos.end(), comp);

  int i = 1;
  for (const Candidato *const c : lista_candidatos) {
    if (c->get_situacao() == "Eleito") {
      cout << i++ << " - " << c->get_nome() << " / " << c->get_nome_urna()
           << " (" << c->get_partido()->get_sigla_partido() << ", "
           << c->get_votos_nominais() << " votos)" << endl;
    }
  }

  cout << endl;
}

void Relatorios::relatorio3(vector<Candidato *> &lista_candidatos) {
  auto comp = [](Candidato const *c1, Candidato const *c2) {
    return c2->get_votos_nominais() < c1->get_votos_nominais();
  };

  std::sort(lista_candidatos.begin(), lista_candidatos.end(), comp);
  unsigned int qtd_vagas = calcula_numero_vagas(lista_candidatos);

  for (unsigned int i = 0; i < qtd_vagas; i++) {
    const Candidato *c = lista_candidatos[i];

    cout << i + 1 << " - " << c->get_nome() << " / " << c->get_nome_urna()
         << " (" << c->get_partido()->get_sigla_partido() << ", "
         << c->get_votos_nominais() << " votos)" << endl;
  }
}
