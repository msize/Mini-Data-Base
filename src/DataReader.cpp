#include "DataReader.h"

const char DataReader::kDataDelimiter = '\t';
const char DataReader::kLineDelimiter = '\n';

DataReader::CantOpenFile::CantOpenFile(const std::string &message)
    : message_("Can't open file: " + message) {
}

DataReader::CantOpenFile::~CantOpenFile() throw () {
}

const char *DataReader::CantOpenFile::what() const throw() {
  return message_.c_str();
}

DataReader::DataReader(const std::string &file)
    : inFile_(file), fileName_(file), readingIndex_(0) {
}

DataReader::DataReader(const std::string &file, const std::string &index)
    : inFile_(file), fileName_(file), inIndex_(index), indexName_(index), readingIndex_(0) {
}

DataReader::~DataReader() {
  inFile_.close();
  inIndex_.close();
}

int DataReader::getPos() {
  return inFile_.tellg();
}

bool DataReader::bumpReadingIndex(int index) {
  if (0 == readingIndex_)
    loadIndexes();
  if (readingIndex_ != index) {
    indexesIterator_ = indexes_.find(index);
    readingIndex_ = index;
  } else {
    ++indexesIterator_;
  }
  if(indexes_.end() != indexesIterator_ && readingIndex_ == indexesIterator_->first) {
    inFile_.seekg(indexesIterator_->second);
    return true;
  }
  return false;
}

std::string DataReader::getNext() {
  return getField(kDataDelimiter);
}

std::string DataReader::getLast() {
  return getField(kLineDelimiter);
}

std::string DataReader::getField(const char delimeter) {
  if(!inFile_.is_open())
    throw CantOpenFile(fileName_);
  std::string result;
  if (!std::getline(inFile_, result, delimeter))
    throw EndOfFile();
  return result;
}

void DataReader::loadIndexes() {
  if (!inIndex_.is_open())
    throw CantOpenFile(indexName_);
  int idx = 0;
  int pos = 0;
  while(inIndex_) {
    idx = 0;
    inIndex_ >> idx;
    inIndex_ >> pos;
    if (idx)
      indexes_.insert(std::pair<int, int>(idx, pos));
  }
}
