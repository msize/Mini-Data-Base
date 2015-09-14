#ifndef __EMPLOYEECHARGEJOIN_H__
#define __EMPLOYEECHARGEJOIN_H__

#include "EmployeeFilterByAge.h"
#include "ChargeFilterByDate.h"

class EmployeeChargeJoin {

public:

  EmployeeChargeJoin(EmployeeFilterByAge &employeeFilterByAge, ChargeFilterByDate &chargeFilterByDate);
  virtual ~EmployeeChargeJoin();

  virtual bool nextCharge(Charge &charge) = 0;

protected:

  EmployeeFilterByAge &employeeFilterByAge_;
  ChargeFilterByDate &chargeFilterByDate_;

};

#endif /* __EMPLOYEECHARGEJOIN_H__ */
