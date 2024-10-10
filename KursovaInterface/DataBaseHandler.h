#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include <functional>
#include <iostream>

class DatabaseHandler 
{
public:
    DatabaseHandler(const std::string& dbPath);
    virtual ~DatabaseHandler();
protected:
    sqlite3* DB;
    bool openDatabase();
    void closeDatabase();
    sqlite3_stmt* prepareStatement(const std::string& sql);
    void finalizeStatement(sqlite3_stmt* stmt);
    bool executeStatement(sqlite3_stmt* stmt);

private:
    std::string dbPath;
};
