#include "Financial.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <sqlite3.h>
#include <tuple>


Financial::Financial(const std::string& dbPath) : DatabaseHandler(dbPath) {}

bool Financial::addTransaction(const Transaction& transaction) {
    std::string sql = "INSERT INTO FinancialTransaction (amount, date, transaction_type, tournament_id) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_double(stmt, 1, transaction.amount) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, transaction.date.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 3, transaction.transactionType.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_int(stmt, 4, transaction.tournamentId) != SQLITE_OK) {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    return executeStatement(stmt);

    sqlite3_finalize(stmt);
    return true;
}

// 1 запит ////////////////////////////// Вибір з декількох таблиць із сортуванням
std::vector<Transaction> Financial::findTransactionForCashier(double minAmount)
{
    std::vector<Transaction> transactions;

    std::string sql = "SELECT amount, transaction_type, date, tournament_id FROM FinancialTransaction WHERE amount > ?;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_double(stmt, 1, minAmount) != SQLITE_OK)
    {
        std::cerr << "Error binding value: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return transactions;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Transaction transaction;
        transaction.amount = sqlite3_column_double(stmt, 0);
        transaction.transactionType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        transaction.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        transaction.tournamentId = sqlite3_column_int(stmt, 3);
        transactions.push_back(transaction);
    }

    sqlite3_finalize(stmt);
    return transactions;
}

// 2 запит ............................................................................. Завдання умови відбору з використанням предиката LІKE
std::vector<Transaction> Financial::findTransactionsByType(const std::string& type)
{
    std::vector<Transaction> transactions;

    std::string sql = "SELECT * FROM FinancialTransaction WHERE transaction_type LIKE ?;";
    sqlite3_stmt* stmt = prepareStatement(sql);
    std::string likeCondition = type + "%";

    if (sqlite3_bind_text(stmt, 1, likeCondition.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return transactions;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Transaction transaction;
        transaction.transactionId = sqlite3_column_int(stmt, 0);
        transaction.amount = sqlite3_column_double(stmt, 1);
        transaction.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        transaction.transactionType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        transaction.tournamentId = sqlite3_column_int(stmt, 4);
        transactions.push_back(transaction);
    }

    sqlite3_finalize(stmt);
    return transactions;
}

// 3 запит ............................................. завдання умови відбору з предикатом BETWEEN
std::vector<Transaction> Financial::findTransactionsByDateRange(const std::string& startDate, const std::string& endDate)
{
    std::vector<Transaction> transactions;

    std::string sql = "SELECT * FROM FinancialTransaction WHERE date BETWEEN ? AND ?;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, startDate.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, endDate.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return transactions;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Transaction transaction;
        transaction.transactionId = sqlite3_column_int(stmt, 0);
        transaction.amount = sqlite3_column_double(stmt, 1);
        transaction.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        transaction.transactionType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        transaction.tournamentId = sqlite3_column_int(stmt, 4);
        transactions.push_back(transaction);
    }

    sqlite3_finalize(stmt);
    return transactions;
}

// 5 запит ................................................................. агрегатна функція з угрупуванням 
int Financial::getMaxTransactionCountForTournament(int tournamentId)
{
    int maxTransactionCount = 0;

    if (!openDatabase()) {
        std::cerr << "Failed to open database." << std::endl;
        return maxTransactionCount;
    }

    std::string sql =
        "SELECT COUNT(*) AS transaction_count "
        "FROM FinancialTransaction "
        "WHERE tournament_id = ? "
        "GROUP BY tournament_id "
        "ORDER BY transaction_count DESC "
        "LIMIT 1;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_int(stmt, 1, tournamentId) != SQLITE_OK)
    {
        std::cerr << "Error binding value: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        closeDatabase();
        return maxTransactionCount;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        maxTransactionCount = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    closeDatabase();

    return maxTransactionCount;
}

// 6 та 7 запит .................................. Корельований 
std::vector<Transaction> Financial::findTransactionsByAmounts(const std::vector<double>& amounts) {
    std::vector<Transaction> transactions;


    std::ostringstream queryStream;
    queryStream << "SELECT ft.transaction_id, ft.amount, ft.date, ft.transaction_type, "
        << "ft.tournament_id, t.name AS tournament_name, t.tournament_date, ts.venue "
        << "FROM FinancialTransaction ft "
        << "JOIN Tournament t ON ft.tournament_id = t.tournament_id "
        << "JOIN TournamentSchedule ts ON t.tournament_id = ts.tournament_id "
        << "WHERE ft.amount IN (";
    for (size_t i = 0; i < amounts.size(); ++i)
    {
        queryStream << amounts[i];
        if (i < amounts.size() - 1) {
            queryStream << ", ";
        }
    }
    queryStream << ");";
    std::string query = queryStream.str();

    std::cout << "SQL Query: " << query << std::endl;

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("tournament.db", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return transactions;
    }

    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return transactions;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        Transaction transaction;
        transaction.transactionId = sqlite3_column_int(stmt, 0);
        transaction.amount = sqlite3_column_double(stmt, 1);
        transaction.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        transaction.transactionType = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        transaction.tournamentId = sqlite3_column_int(stmt, 4);
        transaction.tournamentName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        transaction.tournamentDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        transaction.venue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        transactions.push_back(transaction);
    }

    if (rc != SQLITE_DONE)
    {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return transactions;
}