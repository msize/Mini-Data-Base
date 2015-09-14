#ifndef __CHARGE_H__
#define __CHARGE_H__

#include "Data.h"
#include "Date.h"

class Charge : public Data {

public:

  Charge();
  virtual ~Charge();

  Date date() const {
    return date_;
  }
  int employeeId() const {
    return employeeId_;
  }
  double amount() const {
    return amount_;
  }

private:

  virtual void readFields(DataReader &dataReader);
  virtual void resetFields();

  Date date_;
  int employeeId_ = 0;
  double amount_ = 0.0;

};

#endif /* __CHARGE_H__ */
