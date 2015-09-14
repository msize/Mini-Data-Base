#ifndef __EMPLOYEECHARGENESTEDLOOP_H__
#define __EMPLOYEECHARGENESTEDLOOP_H__

#include "EmployeeChargeJoin.h"

class EmployeeChargeNestedLoop : public EmployeeChargeJoin {

public:

  EmployeeChargeNestedLoop(EmployeeFilterByAge &employeeFilterByAge, ChargeFilterByDate &chargeFilterByDate);
  virtual ~EmployeeChargeNestedLoop();

  virtual bool nextCharge(Charge &charge);

private:

  Employee employee;

};

#endif /* __EMPLOYEECHARGENESTEDLOOP_H__ */
