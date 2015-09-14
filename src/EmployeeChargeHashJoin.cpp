#include "EmployeeChargeHashJoin.h"

EmployeeChargeHashJoin::EmployeeChargeHashJoin(
    EmployeeFilterByAge &employeeFilterByAge,
    ChargeFilterByDate &chargeFilterByDate)
    : EmployeeChargeJoin(employeeFilterByAge, chargeFilterByDate),
      isEmployeeScaned_(false) {
}

EmployeeChargeHashJoin::~EmployeeChargeHashJoin() {
}

bool EmployeeChargeHashJoin::nextCharge(Charge &charge) {
  if (!isEmployeeScaned_)
    fillEmployeeIds();
  if (employeeIds_.empty())
    return false;
  while (chargeFilterByDate_.nextCharge(charge))
    if (employeeIds_.end() != employeeIds_.find(charge.employeeId()))
      return true;
  return false;
}

void EmployeeChargeHashJoin::fillEmployeeIds() {
  Employee employee;
  while (employeeFilterByAge_.nextEmployee(employee))
    employeeIds_.insert(employee.id());
  isEmployeeScaned_ = true;
}

