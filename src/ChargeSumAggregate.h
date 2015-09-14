#ifndef __CHARGESUM_H__
#define __CHARGESUM_H__

#include "EmployeeChargeJoin.h"

class ChargeSumAggregate {

public:

  ChargeSumAggregate(EmployeeChargeJoin &employeeChargeJoin);
  virtual ~ChargeSumAggregate();

  double result();

private:

  EmployeeChargeJoin &employeeChargeJoin_;

};

#endif /* __CHARGESUM_H__ */
