#include "Data.h"

Data::Data() {
}

Data::~Data() {
}

bool Data::fromData(DataReader &dataReader) {
  try {
    readFields(dataReader);
    return true;
  } catch (DataReader::EndOfFile &eof) {
    resetFields();
  }
  return false;
}
