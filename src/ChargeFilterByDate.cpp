#include "ChargeFilterByDate.h"

ChargeFilterByDate::ChargeFilterByDate(const Date &startDate, const Date &endDate, DataReader &dataReader)
    : startDate_(startDate), endDate_(endDate), dataReader_(dataReader) {
}

ChargeFilterByDate::~ChargeFilterByDate() {
}

bool ChargeFilterByDate::nextCharge(Charge &charge) {
  while (charge.fromData(dataReader_))
    if (isPassFilter(charge))
      return true;
  return false;
}

bool ChargeFilterByDate::nextCharge(int employeeId, Charge &charge) {
  while (true) {
    if (!dataReader_.bumpReadingIndex(employeeId))
      break;
    if (!charge.fromData(dataReader_))
      break;
    if (isPassFilter(charge))
      return true;
  }
  return false;
}

bool ChargeFilterByDate::isPassFilter(const Charge &charge) const {
  return startDate_ <= charge.date() && charge.date() <= endDate_;
}
