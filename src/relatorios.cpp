#include "./relatorios.h"
#include "./NumberUtils.h"
#include "partido.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using cpp_util::formatDouble;
using cpp_util::LOCALE_PT_BR;
using std::cout;
using std::endl;

double Relatorios::calcula_porcentagem(double valor, double total) {
  return (valor * 100) / total;
}

size_t
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
  size_t qtd_vagas = calcula_numero_vagas(lista_candidatos);

  for (size_t i = 0; i < qtd_vagas; i++) {
    const Candidato *c = lista_candidatos[i];

    cout << i + 1 << " - " << c->get_nome() << " / " << c->get_nome_urna()
         << " (" << c->get_partido()->get_sigla_partido() << ", "
         << c->get_votos_nominais() << " votos)" << endl;
  }

  cout << endl;
}

void Relatorios::relatorio10(const vector<Candidato *> &lista_candidatos) {
  size_t qtd_homens = 0, qtd_mulheres = 0, total;

  for (const Candidato *const c : lista_candidatos) {
    if (c->eleito()) {
      if (c->get_sexo() == "F") {
        qtd_mulheres++;
      } else {
        qtd_homens++;
      }
    }
  }

  total = qtd_homens + qtd_mulheres;
  double porcentagem_mulheres = calcula_porcentagem(qtd_mulheres, total);
  double porcentagem_homens = calcula_porcentagem(qtd_homens, total);
  string porcentagem_mulheres_pt_br =
      formatDouble(porcentagem_mulheres, LOCALE_PT_BR);
  string porcentagem_homens_pt_br =
      formatDouble(porcentagem_homens, LOCALE_PT_BR);

  cout << "Eleitos, por sexo:" << endl;
  cout << "Feminino: " << qtd_mulheres << " (" << porcentagem_mulheres_pt_br
       << "%)" << endl;
  cout << "Masculino: " << qtd_homens << " (" << porcentagem_homens_pt_br
       << "%)" << endl
       << endl;
}

void Relatorios::relatorio11(const vector<Partido *> &lista_partidos) {
  size_t votos_validos = 0;
  size_t votos_nominais = 0;
  size_t votos_legenda = 0;

  for (const Partido *p : lista_partidos) {
    votos_validos += p->get_total_votos_validos();
    votos_legenda += p->get_votos_legenda();
  }

  votos_nominais = votos_validos - votos_legenda;

  double porcentagem_votos_nominais =
      calcula_porcentagem(votos_nominais, votos_validos);
  double porcentagem_votos_legenda =
      calcula_porcentagem(votos_legenda, votos_validos);

  string porcentagem_votos_nominais_em_pt =
      formatDouble(porcentagem_votos_nominais, LOCALE_PT_BR);
  string porcentagem_votos_legenda_em_pt =
      formatDouble(porcentagem_votos_legenda, LOCALE_PT_BR);

  cout << "Total de votos válidos:    " << votos_validos << endl;
  cout << "Total de votos nominais:   " << votos_nominais << " ("
       << porcentagem_votos_nominais_em_pt << "%)" << endl;
  cout << "Total de votos de legenda: " << votos_nominais << " ("
       << porcentagem_votos_legenda_em_pt << "%)" << endl
       << endl;
}
