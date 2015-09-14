#ifndef __DATE_H__
#define __DATE_H__

#include <string>

class Date {

  static const char kDateSeparator;

public:

  class DateIsInvalid : public std::exception {
  public:
    DateIsInvalid(const std::string &message);
    virtual ~DateIsInvalid() throw ();
    virtual const char *what() const throw();
  private:
    std::string message_;
  };

  Date();
  virtual ~Date();

  void fromString(const std::string &str);
  std::string toString() const;
  void reset();
  bool operator<=(const Date &date) const;
  bool operator<(const Date &date) const;

private:

  int getNextVal(std::istringstream &in, std::string &val) const;
  bool isValid() const;

  int year_;
  int month_;
  int day_;

};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif /* __DATE_H__ */
