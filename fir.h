#ifndef __fir_h__
#define __fir_h__
#include <vector>

class FIR {
public:
  FIR(std::vector<double> coeff);
  FIR();
  void setcoeff(std::vector<double> coeff);
  double push_back(double data);
  void reset();
  const double ist();
  const std::vector<double> getcoeff();
  double operator<<(double data);
private:
  std::vector<double> _coeff;
  std::vector<double> _data;
  double _out;
  unsigned int _taps;
  void _process();
  void _cleardata();
};

#endif
