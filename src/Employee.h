#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Data.h"

class Employee : public Data {

public:

  Employee();
  virtual ~Employee();

  int id() const {
    return id_;
  }
  std::string name() const {
    return name_;
  }
  int age() const {
    return age_;
  }

private:

  virtual void readFields(DataReader &dataReader);
  virtual void resetFields();

  int id_ = 0;
  std::string name_;
  int age_ = 0;

};

#endif /* __EMPLOYEE_H__ */
