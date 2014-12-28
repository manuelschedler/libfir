#include <vector>
#include "fir.h"

FIR::FIR(std::vector<double> coeff) {
  setcoeff(coeff);
};

FIR::FIR() {
};

void FIR::setcoeff(std::vector<double> coeff) {
  _coeff.clear();
  for(std::vector<double>::iterator it=coeff.begin(); it!=coeff.end(); ++it) {
    _coeff.push_back(*it);
  }

};
double FIR::push_back(double data) {
  _data.push_back(data);
  while(_data.size() > _coeff.size()) {
    _data.erase(_data.begin());
  }
  _process();
  return ist();
};

void FIR::reset() {
  _data.clear();
};

const double FIR::ist() {
  return _out;
};

const std::vector<double> FIR::getcoeff() {
  return _coeff;
};

double FIR::operator<<(double data) {
  return push_back(data);
}

void FIR::_process() {
  double val=0;
  std::vector<double>::iterator it2=_coeff.begin();
  for(std::vector<double>::iterator it=_data.begin(); it != _data.end(); ++it) {
    if(it2==_coeff.end()) break;
    val+=*it**it2;
    ++it2;
  }
  _out=val;
};

void FIR::_cleardata() {
  _data.clear();
  for(unsigned int i=0; i<_coeff.size(); ++i) {
    _data.push_back(0);
  }
};
