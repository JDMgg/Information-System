#pragma once
#include <string>
#include <sqlite3.h>
#include <vector>
#include <tuple>
#include "DataBaseHandler.h"

struct Transaction
{
    double amount;
    std::string transactionType;
    std::string date;
    int tournamentId;
    int transactionId;
    std::string tournamentName;
    std::string tournamentDate;
    std::string venue;
};

class Financial : public DatabaseHandler
{
public:
    Financial(const std::string& dbPath);
    // Додавання транзакції
    bool addTransaction(const Transaction& transaction);
    // 1 запит 
    std::vector<Transaction> findTransactionForCashier(double minAmount);
    // 2 запит
    std::vector<Transaction> findTransactionsByType(const std::string& type);
    // 3 запит
    std::vector<Transaction> findTransactionsByDateRange(const std::string& startDate, const std::string& endDate);
    // 5 запит
    int getMaxTransactionCountForTournament(int tournamentId);
    // 6, 7 запит 
    std::vector<Transaction> findTransactionsByAmounts(const std::vector<double>& amounts);
};