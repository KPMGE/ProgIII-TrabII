#include "./Data.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using std::getline;
using std::stringstream;

Data::Data(const string &data_string) {
  stringstream data_stream(data_string);
  string dia, mes, ano;

  getline(data_stream, dia, '/');
  getline(data_stream, mes, '/');
  getline(data_stream, ano, '\n');

  this->dia = std::atoi(dia.c_str());
  this->mes = std::atoi(mes.c_str());
  this->ano = std::atoi(ano.c_str());
}

Data::Data(unsigned short dia, unsigned short mes, unsigned short ano) {
  this->dia = dia;
  this->ano = ano;
  this->mes = mes;
}

unsigned short Data::get_dia() const { return this->dia; }

unsigned short Data::get_mes() const { return this->mes; }

unsigned short Data::get_ano() const { return this->ano; }
