#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include "database.h"

bool registerUser(Database& db, const std::string& username, const std::string& password, const std::string& role, const std::string& email);
bool loginUser(Database& db, const std::string& username, const std::string& password, std::string& role, int& studentId);

#endif // LOGIN_H