#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <string>

namespace tools {

void makeChargeIndexByEmployeeId(const std::string &file, const std::string &index);
void makeChargeIndexByDateId(const std::string &file, const std::string &index);
void makeEmployeeIndexByAgeId(const std::string &file, const std::string &index);

} /* namespace tools */
#endif /* __TOOLS_H__ */
