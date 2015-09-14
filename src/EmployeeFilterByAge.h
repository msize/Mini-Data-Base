#ifndef __EMPLOYEEFILTERBYAGE_H__
#define __EMPLOYEEFILTERBYAGE_H__

#include "DataReader.h"
#include "Employee.h"

class EmployeeFilterByAge {

public:

  EmployeeFilterByAge(int minAge, int maxAge, DataReader &dataReader);
  virtual ~EmployeeFilterByAge();

  bool nextEmployee(Employee &employee);

private:

  bool isPassFilter(const Employee &employee) const;

  int minAge_;
  int maxAge_;
  DataReader &dataReader_;

};

#endif /* __EMPLOYEEFILTERBYAGE_H__ */
