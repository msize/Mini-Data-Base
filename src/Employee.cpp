#include "Employee.h"

Employee::Employee() {
}

Employee::~Employee() {
}

void Employee::readFields(DataReader &dataReader) {
  id_ = std::stoi(dataReader.getNext());
  name_ = dataReader.getNext();
  age_ = std::stoi(dataReader.getLast());
}

void Employee::resetFields() {
  id_ = 0;
  name_ = "";
  age_ = 0;
}
