#include "ChargeSumAggregate.h"

ChargeSumAggregate::ChargeSumAggregate(EmployeeChargeJoin &employeeChargeJoin)
    : employeeChargeJoin_(employeeChargeJoin) {
}

ChargeSumAggregate::~ChargeSumAggregate() {
}

double ChargeSumAggregate::result() {
  Charge charge;
  double sum = 0.0;
  while (employeeChargeJoin_.nextCharge(charge))
    sum += charge.amount();
  return sum;
}
