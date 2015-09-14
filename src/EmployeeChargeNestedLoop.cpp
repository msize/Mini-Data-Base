#include "EmployeeChargeNestedLoop.h"

EmployeeChargeNestedLoop::EmployeeChargeNestedLoop(
    EmployeeFilterByAge &employeeFilterByAge,
    ChargeFilterByDate &chargeFilterByDate)
    : EmployeeChargeJoin(employeeFilterByAge, chargeFilterByDate) {
}

EmployeeChargeNestedLoop::~EmployeeChargeNestedLoop() {
}

bool EmployeeChargeNestedLoop::nextCharge(Charge &charge) {
  if (employee.id())
    if (chargeFilterByDate_.nextCharge(employee.id(), charge))
      return true;
  while (employeeFilterByAge_.nextEmployee(employee))
    if (chargeFilterByDate_.nextCharge(employee.id(), charge))
      return true;
  return false;
}
