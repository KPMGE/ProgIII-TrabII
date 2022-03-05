#ifndef DATA_H_
#define DATA_H_

#include <string>
using std::string;

class Data {
private:
  unsigned short dia, mes, ano;

public:
  Data(const string &data_string = "0/0/0");
  Data(unsigned short dia, unsigned short mes, unsigned short ano);
  unsigned short get_dia() const;
  unsigned short get_mes() const;
  unsigned short get_ano() const;
};

#endif // !DATA_H_
