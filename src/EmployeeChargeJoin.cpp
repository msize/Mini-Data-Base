#include "EmployeeChargeJoin.h"

EmployeeChargeJoin::EmployeeChargeJoin(
    EmployeeFilterByAge &employeeFilterByAge,
    ChargeFilterByDate &chargeFilterByDate)
    : employeeFilterByAge_(employeeFilterByAge),
      chargeFilterByDate_(chargeFilterByDate) {
}

EmployeeChargeJoin::~EmployeeChargeJoin() {
}

