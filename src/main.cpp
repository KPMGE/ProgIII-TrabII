#include "./Partido.h"
#include <fstream>
#include <iostream>
#include <vector>

using std::atoi;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  vector<Partido> partidos;

  string numero_partido;
  string votos_legenda;
  string nome_partido;
  string sigla_partido;

  fstream csv_stream;
  csv_stream.open(argv[1]);
  getline(csv_stream, numero_partido, '\n'); // ignora a primeira linha

  while (csv_stream.good()) {
    getline(csv_stream, numero_partido, ',');
    getline(csv_stream, votos_legenda, ',');
    getline(csv_stream, nome_partido, ',');
    getline(csv_stream, sigla_partido, '\n');

    if (!csv_stream.good()) {
      break;
    }
    Partido novoCandidato =
        Partido(atoi(numero_partido.c_str()), atoi(votos_legenda.c_str()),
                nome_partido, sigla_partido);
    partidos.push_back(novoCandidato);
    cout << endl;
  }

  csv_stream.close();

  cout << "Candidatos: \n";
  for (const Partido &c : partidos) {
    cout << "numero partido: " << c.get_numero_partido() << endl;
    cout << "votos_legenda: " << c.get_votos_legenda() << endl;
    cout << "nome_partido: " << c.get_nome_partido() << endl;
    cout << "sigla_partido: " << c.get_sigla_partido() << endl;
    cout << endl;
  }
}
