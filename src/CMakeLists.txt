cmake_minimum_required(VERSION 2.6)
project(db-mini)
add_definitions(-std=c++11)
set(SOURCE
Charge.cpp
ChargeFilterByDate.cpp
ChargeSumAggregate.cpp
Data.cpp
DataReader.cpp
Date.cpp
EmployeeChargeHashJoin.cpp
EmployeeChargeJoin.cpp
EmployeeChargeNestedLoop.cpp
Employee.cpp
EmployeeFilterByAge.cpp
main.cpp
Tools.cpp)
add_executable(db-mini ${SOURCE})
