#include "Account.h"
#include <iostream>
#include <sstream>
#include  <vector>
#include <sqlite3.h>
#include <tuple>


Account::Account(const std::string& dbPath) : DatabaseHandler(dbPath) {}


bool Account::login(const std::string& login, const std::string& password)
{
    std::string sql = "SELECT * FROM Account WHERE Login = ? AND Password = ?;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    int result = sqlite3_step(stmt);
    if (result == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        return true;
    }
    else {
        sqlite3_finalize(stmt);
        return false;
    }
}

// метод для отримання типу юзера
std::string Account::getUserType(const std::string& login)
{
    std::string userType;

    std::string sql = "SELECT Type FROM Account WHERE Login = ?;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return userType;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        userType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return userType;
}