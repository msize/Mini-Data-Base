#include "Date.h"
#include <sstream>

const char Date::kDateSeparator = '-';

Date::DateIsInvalid::DateIsInvalid (const std::string &message) : message_("Date is invalid: " + message) {
}

Date::DateIsInvalid::~DateIsInvalid() throw () {
}

const char *Date::DateIsInvalid::what() const throw() {
  return message_.c_str();
}

Date::Date() {
  reset();
}

Date::~Date() {
}

void Date::fromString(const std::string &str) {
  std::istringstream in(str);
  std::string val;
  year_ = getNextVal(in, val);
  month_ = getNextVal(in, val);
  day_ = getNextVal(in, val);
  if(!isValid())
    throw DateIsInvalid(str);
}

std::string Date::toString() const {
  std::ostringstream out;
  out << year_ << '-' << month_ << '-' << day_;
  return out.str();
}

void Date::reset() {
  year_ = 1;
  month_ = 1;
  day_ = 1;
}

bool Date::operator<=(const Date &date) const {
  return !(year_ == date.year_ ? (month_ == date.month_ ? (day_ == date.day_ ?
      false : day_ > date.day_) : (month_ > date.month_)) : (year_ > date.year_));
}

bool Date::operator<(const Date &date) const {
  return !(date <= *this);
}

int Date::getNextVal(std::istringstream &in, std::string &val) const {
  std::getline(in, val, kDateSeparator);
  return std::stoi(val.c_str());
}

bool Date::isValid() const {
  if (0 >= year_)
    return false;
  if (0 >= month_)
    return false;
  if (12 < month_)
    return false;
  if (0 >= day_)
    return false;
  if (2 == month_) {
    bool isLeapYear = !(year_ % 4) && (year_ % 100 || !(year_ % 400));
    if (isLeapYear) {
      if (29 < day_)
        return false;
    } else {
      if (28 < day_)
        return false;
    }
  } else if (4 == month_ || 6 == month_ || 9 == month_ || 11 == month_) {
    if (30 < day_)
      return false;
  } else {
    if (31 < day_)
      return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.toString();
  return os;
}
