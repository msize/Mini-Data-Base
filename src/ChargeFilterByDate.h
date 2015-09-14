#ifndef __CHARGEFILTERBYDATE_H__
#define __CHARGEFILTERBYDATE_H__

#include "DataReader.h"
#include "Date.h"
#include "Charge.h"

class ChargeFilterByDate {

public:

  ChargeFilterByDate(const Date &startDate, const Date &endDate, DataReader &dataReader);
  virtual ~ChargeFilterByDate();

  bool nextCharge(Charge &charge);
  bool nextCharge(int employeeId, Charge &charge);

private:

  bool isPassFilter(const Charge &charge) const;

  Date startDate_;
  Date endDate_;
  DataReader &dataReader_;

};

#endif /* __CHARGEFILTERBYDATE_H__ */
