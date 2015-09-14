#ifndef __DATAREADER_H__
#define __DATAREADER_H__

#include <fstream>
#include <map>

class DataReader {

  static const char kDataDelimiter;
  static const char kLineDelimiter;

public:

  class CantOpenFile : public std::exception {
  public:
    CantOpenFile(const std::string &message);
    virtual ~CantOpenFile() throw ();
    virtual const char *what() const throw();
  private:
    std::string message_;
  };

  class EndOfFile : public std::exception {
  };

  DataReader(const std::string &file);
  DataReader(const std::string &file, const std::string &index);
  virtual ~DataReader();

  int getPos();
  bool bumpReadingIndex(int index);
  std::string getNext();
  std::string getLast();

private:

  std::string getField(const char delimeter);
  void loadIndexes();

  std::ifstream inFile_;
  std::string fileName_;
  std::ifstream inIndex_;
  std::string indexName_;
  int readingIndex_;
  std::multimap<int, int> indexes_;
  std::multimap<int, int>::const_iterator indexesIterator_;

};

#endif /* __DATAREADER_H__ */
