#include "Charge.h"

Charge::Charge() {
}

Charge::~Charge() {
}

void Charge::readFields(DataReader &dataReader) {
  date_.fromString(dataReader.getNext());
  employeeId_ = std::stoi(dataReader.getNext());
  amount_ = std::stod(dataReader.getLast());
}

void Charge::resetFields() {
  date_.reset();
  employeeId_ = 0;
  amount_ = 0.0;
}
