#include "Tools.h"
#include "Charge.h"
#include "Employee.h"
#include <fstream>
#include <map>
#include <functional>

namespace tools {

template<typename T>
void writeIndex(const std::string &indexFile, T &indexMap) {
  std::ofstream outFile(indexFile);
  for (auto i : indexMap)
    outFile << i.first << " " << i.second << "\n";
}

template<typename R, typename F, typename M>
void makeIndex(const std::string &dateFile, R &rec, F func, M &indexMap) {
  DataReader data(dateFile);
  int prevPos = 0;
  while (rec.fromData(data)) {
    indexMap.insert(typename M::value_type(func(rec), prevPos));
    prevPos = data.getPos();
  }
}

void makeChargeIndexByEmployeeId(const std::string &file, const std::string &index) {
  Charge charge;
  std::multimap<int, int> idPos;
  std::function<int(Charge&)> func = std::mem_fn(&Charge::employeeId);
  makeIndex(file, charge, func, idPos);
  writeIndex(index, idPos);
}

void makeChargeIndexByDateId(const std::string &file, const std::string &index) {
  Charge charge;
  std::multimap<Date, int> idPos;
  std::function<Date(Charge&)> func = std::mem_fn(&Charge::date);
  makeIndex(file, charge, func, idPos);
  writeIndex(index, idPos);
}

void makeEmployeeIndexByAgeId(const std::string &file, const std::string &index) {
  Employee employee;
  std::multimap<int, int> idPos;
  std::function<int(Employee&)> func = std::mem_fn(&Employee::age);
  makeIndex(file, employee, func, idPos);
  writeIndex(index, idPos);
}

} /* namespace tools */
