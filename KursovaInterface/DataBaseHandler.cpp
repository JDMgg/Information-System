#include "DataBaseHandler.h"

DatabaseHandler::DatabaseHandler(const std::string& dbPath) : DB(nullptr), dbPath(dbPath) 
{
    openDatabase();
}

DatabaseHandler::~DatabaseHandler() 
{
    closeDatabase();
}

bool DatabaseHandler::openDatabase() 
{
    int exit = sqlite3_open_v2(dbPath.c_str(), &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);
    if (exit) {
        std::cerr << "Error opening DB: " << sqlite3_errmsg(DB) << std::endl;
        return false;
    }
    sqlite3_busy_timeout(DB, 5000);
    return true;
}

void DatabaseHandler::closeDatabase() 
{
    if (DB) {
        sqlite3_close(DB);
        DB = nullptr;
    }
}

sqlite3_stmt* DatabaseHandler::prepareStatement(const std::string& sql) 
{
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << std::endl;
        return nullptr;
    }
    return stmt;
}



void DatabaseHandler::finalizeStatement(sqlite3_stmt* stmt) 
{
    if (stmt) {
        sqlite3_finalize(stmt);
    }
}

bool DatabaseHandler::executeStatement(sqlite3_stmt* stmt) {
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
    sqlite3_finalize(stmt);  // Фіналізуємо запит після успішного виконання
    return true;
}
