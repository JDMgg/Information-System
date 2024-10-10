#pragma once
#include <string>
#include <sqlite3.h>
#include <vector>
#include <tuple>
#include "DataBaseHandler.h"

class Account : public DatabaseHandler
{
public:
    Account(const std::string& dbPath);

    // ����� ��� �����
    bool login(const std::string& login, const std::string& password);
    // ���� ��� ��������� ���� �����
    std::string getUserType(const std::string& login);
};