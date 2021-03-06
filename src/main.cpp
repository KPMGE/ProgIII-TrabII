#include "./Data.h"
#include "./candidato.h"
#include "./partido.h"
#include "./relatorios.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>

using std::atoi;
using std::cout;
using std::fstream;
using std::string;
using std::time_t;
using std::vector;

std::string ltrim(const std::string &s) {
  return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string &s) {
  return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string &s) { return ltrim(rtrim(s)); }

void le_partidos(string csv_partido, vector<Partido *> &partidos);
void le_candidatos(string csv_candidato, vector<Candidato *> &candidatos);
void relaciona_partidos_com_candidatos(vector<Partido *> &partidos,
                                       vector<Candidato *> &candidatos);
void destroi_partidos(vector<Partido *> &partidos);
void destroi_candidatos(vector<Candidato *> &candidatos);

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cout << "Usage: ./vereadores <csv partido> <csv candidato>";
    exit(1);
  }

  Data data_eleicao(argv[3]);
  vector<Partido *> partidos;
  vector<Candidato *> candidatos;

  le_candidatos(argv[1], candidatos);
  le_partidos(argv[2], partidos);
  relaciona_partidos_com_candidatos(partidos, candidatos);

  Relatorios r;
  r.relatorio1(candidatos);
  r.relatorio2(candidatos);
  r.relatorio3(candidatos);
  r.relatorio4(candidatos);
  r.relatorio5(candidatos);
  r.relatorio6(partidos);
  r.relatorio7(partidos);
  r.relatorio8(partidos);
  r.relatorio9(candidatos, data_eleicao);
  r.relatorio10(candidatos);
  r.relatorio11(partidos);

  destroi_partidos(partidos);
  destroi_candidatos(candidatos);
}

void le_partidos(string csv_partido, vector<Partido *> &partidos) {
  string numero_partido;
  string votos_legenda;
  string nome_partido;
  string sigla_partido;

  fstream csv_stream;

  try {
    csv_stream.open(csv_partido);
  } catch (const std::exception &) {
    std::cerr << "Erro ao abrir o arquivo";
  }

  getline(csv_stream, numero_partido, '\n'); // ignora a primeira linha

  while (csv_stream.good()) {
    getline(csv_stream, numero_partido, ',');
    getline(csv_stream, votos_legenda, ',');
    getline(csv_stream, nome_partido, ',');
    getline(csv_stream, sigla_partido, '\n');

    // removendo eventuais linhas em branco do come??o e do final das strings.
    nome_partido = trim(nome_partido);
    sigla_partido = trim(sigla_partido);

    if (!csv_stream.good()) {
      break;
    }

    Partido *novoPartido =
        new Partido(atoi(numero_partido.c_str()), atoi(votos_legenda.c_str()),
                    nome_partido, sigla_partido);
    partidos.push_back(novoPartido);
  }

  csv_stream.close();
}

void le_candidatos(string csv_candidato, vector<Candidato *> &candidatos) {
  string numero;
  string votos_nominais;
  string situacao;
  string nome;
  string nome_urna;
  string sexo;
  string data_nascimento_string;
  string destino_voto;
  string numero_partido;

  fstream csv_stream;
  try {
    csv_stream.open(csv_candidato);
  } catch (const std::exception &) {
    std::cerr << "Erro ao abrir o arquivo";
  }

  getline(csv_stream, nome, '\n'); // ignora a primeira linha

  while (csv_stream.good()) {
    getline(csv_stream, numero, ',');
    getline(csv_stream, votos_nominais, ',');
    getline(csv_stream, situacao, ',');
    getline(csv_stream, nome, ',');
    getline(csv_stream, nome_urna, ',');
    getline(csv_stream, sexo, ',');
    getline(csv_stream, data_nascimento_string, ',');
    getline(csv_stream, destino_voto, ',');
    getline(csv_stream, numero_partido, '\n');

    // removendo eventuais linhas em branco do come??o e do final das strings.
    nome = trim(nome);
    nome_urna = trim(nome_urna);
    destino_voto = trim(destino_voto);

    if (!csv_stream.good()) {
      break;
    }

    if (destino_voto != "V??lido") {
      continue;
    }

    // convertendo de string para n??mero
    int num = atoi(numero.c_str());
    int votos = atoi(votos_nominais.c_str());
    int num_partido = atoi(numero_partido.c_str());

    Data data_nascimento(data_nascimento_string);

    // criando novo candidato na heap
    Candidato *novoCandidato =
        new Candidato(num, votos, situacao, nome, nome_urna, sexo,
                      data_nascimento, destino_voto, num_partido);

    // adicionando-o ?? lista
    candidatos.push_back(novoCandidato);
  }

  csv_stream.close();
}

void relaciona_partidos_com_candidatos(vector<Partido *> &partidos,
                                       vector<Candidato *> &candidatos) {
  for (Partido *p : partidos) {
    for (Candidato *c : candidatos) {
      if (p->get_numero_partido() == c->get_numero_partido()) {
        p->adiciona_candidato(c);
        c->adiciona_partido(p);
      }
    }
  }
}

void destroi_partidos(vector<Partido *> &partidos) {
  for (Partido *p : partidos) {
    delete p;
  }
}

void destroi_candidatos(vector<Candidato *> &candidatos) {
  for (Candidato *c : candidatos) {
    delete c;
  }
}
