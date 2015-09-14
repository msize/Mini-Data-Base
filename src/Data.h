#ifndef __DATA_H__
#define __DATA_H__

#include "DataReader.h"

class Data {

public:

  Data();
  virtual ~Data();

  bool fromData(DataReader &dataReader);

private:

  virtual void readFields(DataReader &dataReader) = 0;
  virtual void resetFields() = 0;

};

#endif /* __DATA_H__ */
