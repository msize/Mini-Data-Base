#include "EmployeeFilterByAge.h"

EmployeeFilterByAge::EmployeeFilterByAge(int minAge, int maxAge, DataReader &dataReader)
    : minAge_(minAge), maxAge_(maxAge), dataReader_(dataReader) {
}

EmployeeFilterByAge::~EmployeeFilterByAge() {
}

bool EmployeeFilterByAge::nextEmployee(Employee &employee) {
  while (employee.fromData(dataReader_))
    if (isPassFilter(employee))
      return true;
  return false;
}

bool EmployeeFilterByAge::isPassFilter(const Employee &employee) const {
  return minAge_ <= employee.age() && employee.age() <= maxAge_;
}
