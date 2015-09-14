#include "Date.h"
#include "DataReader.h"
#include "EmployeeFilterByAge.h"
#include "ChargeFilterByDate.h"
#include "EmployeeChargeNestedLoop.h"
#include "ChargeSumAggregate.h"
#include "Tools.h"
#include <iostream>

static const std::string kEmployeeFile = "employee.txt";
static const std::string kChargeFile = "charge.txt";
static const std::string kChargeByEmployeeIndexFile = "charge_by_employee.idx";
static const std::string kChargeByDateIndexFile = "charge_by_date.idx";
static const std::string kEmployeeByAgeIndexFile = "employee_by_age.idx";
static const std::string kMakeChargeIndexParam = "make_index";

void printUsage(const char *program) {
  std::cout << "Usage: "
            << program
            << " min_age max_age start_date end_date"
            << "\nor "
            << program
            << " "
            << kMakeChargeIndexParam
            << std::endl;
}

struct Filter {
  int minAge;
  int maxAge;
  Date startDate;
  Date endDate;
};

void readParams(char **argv, Filter &filter) {
  filter.minAge = std::stoi(argv[1]);
  filter.maxAge = std::stoi(argv[2]);
  filter.startDate.fromString(argv[3]);
  filter.endDate.fromString(argv[4]);
}

int main(int argc, char **argv) {
  if (2 == argc && kMakeChargeIndexParam == argv[1]) {
    tools::makeChargeIndexByEmployeeId(kChargeFile, kChargeByEmployeeIndexFile);
    tools::makeChargeIndexByDateId(kChargeFile, kChargeByDateIndexFile);
    tools::makeEmployeeIndexByAgeId(kEmployeeFile, kEmployeeByAgeIndexFile);
    return 0;
  }
  if (5 > argc) {
    printUsage(argv[0]);
    return 1;
  }

  try {
    Filter filter;
    readParams(argv, filter);
    DataReader employeeData(kEmployeeFile);
    DataReader chargeData(kChargeFile, kChargeByEmployeeIndexFile);
    EmployeeFilterByAge employeeFilterByAge(filter.minAge, filter.maxAge, employeeData);
    ChargeFilterByDate chargeFilterByDate(filter.startDate, filter.endDate, chargeData);
    EmployeeChargeNestedLoop employeeChargeNestedLoop(employeeFilterByAge, chargeFilterByDate);
    ChargeSumAggregate chargeSumAggregate(employeeChargeNestedLoop);
    std::cout << "Result: " << chargeSumAggregate.result() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
