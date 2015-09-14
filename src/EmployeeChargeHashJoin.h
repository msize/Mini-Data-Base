#ifndef __EMPLOYEECHARGEHASHJOIN_H__
#define __EMPLOYEECHARGEHASHJOIN_H__

#include "EmployeeChargeJoin.h"
#include <unordered_set>

class EmployeeChargeHashJoin : public EmployeeChargeJoin {

public:

  EmployeeChargeHashJoin(EmployeeFilterByAge &employeeFilterByAge, ChargeFilterByDate &chargeFilterByDate);
  virtual ~EmployeeChargeHashJoin();

  bool nextCharge(Charge &charge);

private:

  void fillEmployeeIds();

  std::unordered_set<int> employeeIds_;
  bool isEmployeeScaned_;

};

#endif /* __EMPLOYEECHARGEHASHJOIN_H__ */
