#include "Tournament.h"
#include <iostream>
#include <sstream>
#include  <vector>
#include <sqlite3.h>
#include <tuple>

Tournament::Tournament(const std::string& dbPath) : DatabaseHandler(dbPath) {}


// Додавання турніру до таблиці 
bool Tournament::addTournament(const std::string& name, const std::string& tournamentDate, const std::string& gameFormat, int ticketCount, const std::string& gameCategory, const std::string& participantId) {
    std::string sql = "INSERT INTO Tournament (name, tournament_date, game_format, ticket_count, game_category, participant_id) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (!stmt) {
        return false;  
    }

    if (sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, tournamentDate.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 3, gameFormat.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_int(stmt, 4, ticketCount) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 5, gameCategory.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 6, participantId.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    return executeStatement(stmt);

    sqlite3_finalize(stmt);
    return true;
}

// Метод для додавання розкладу турніра
bool Tournament::addTournamentSchedule(int tournamentId, const std::string& venue) {
    std::string sql = "SELECT COUNT(*) FROM TournamentSchedule WHERE tournament_id = ?;";
    sqlite3_stmt* stmt;
    int count = 0;

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, tournamentId);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            count = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }

    if (count > 0)
    {
        return false;
    }

    std::string sql_insert = "INSERT INTO TournamentSchedule (tournament_id, venue) VALUES (?, ?);";
    sqlite3_stmt* stmt_insert;

    if (sqlite3_prepare_v2(DB, sql_insert.c_str(), -1, &stmt_insert, nullptr) != SQLITE_OK)
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(DB) << std::endl;
        return false;
    }

    if (sqlite3_bind_int(stmt_insert, 1, tournamentId) != SQLITE_OK ||
        sqlite3_bind_text(stmt_insert, 2, venue.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt_insert);
        return false;
    }

    if (sqlite3_step(stmt_insert) != SQLITE_DONE)
    {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt_insert);
        return false;
    }

    sqlite3_finalize(stmt_insert);
    return true;
}

// метод для додавання учасників турніру
bool Tournament::addParticipant(const Participant& participant) 
{
    std::string sql = "INSERT INTO Participant (club_name, birth_date, last_name, player_class, first_name) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, participant.clubName.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, participant.birthDate.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 3, participant.lastName.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 4, participant.playerClass.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 5, participant.firstName.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    return executeStatement(stmt);

    sqlite3_finalize(stmt);
    return true;
}

// 8 запит знайти всіх кто не належить до клубу
std::vector<std::string> Tournament::findPlayersWithSameClub(const std::string& clubName)
{
    std::vector<std::string> players;

    if (!openDatabase())
    {
        std::cerr << "Failed to open database." << std::endl;
        return players;
    }

    std::string sql =
        "SELECT first_name || ' ' || last_name "
        "FROM Participant "
        "WHERE club_name NOT IN (SELECT club_name FROM Participant WHERE club_name = ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, clubName.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding value: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        closeDatabase();
        return players;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* playerName = sqlite3_column_text(stmt, 0);
        players.push_back(reinterpret_cast<const char*>(playerName));
    }

    sqlite3_finalize(stmt);
    closeDatabase();

    return players;
}

// 4 запит загальна кількість гравців
std::vector<std::string> Tournament::displayAllPlayerInfo()
{
    std::vector<std::string> playersInfo;

    if (!openDatabase())
    {
        std::cerr << "Failed to open database." << std::endl;
        return playersInfo;
    }

    std::string sql = "SELECT * FROM Participant;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int playerId = sqlite3_column_int(stmt, 0);
        std::string clubName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string birthDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string playerClass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

        std::string playerInfo;
        playerInfo += "Player ID: " + std::to_string(playerId) + "\n";
        playerInfo += "Club Name: " + clubName + "\n";
        playerInfo += "Birth Date: " + birthDate + "\n";
        playerInfo += "Last Name: " + lastName + "\n";
        playerInfo += "Player Class: " + playerClass + "\n";
        playerInfo += "First Name: " + firstName + "\n\n";

        playersInfo.push_back(playerInfo);
    }

    sqlite3_finalize(stmt);
    closeDatabase();

    return playersInfo;
}

// 8 запит з використанням left join на заперечення
std::vector<std::vector<std::string>> Tournament::findTournamentsNotHeldAtVenue(const std::string& venue)
{
    std::vector<std::vector<std::string>> tournaments;

    if (!openDatabase())
    {
        std::cerr << "Failed to open database." << std::endl;
        return tournaments;
    }

    std::string sql =
        "SELECT t.tournament_id, t.name, t.tournament_date, t.game_format, t.ticket_count, t.game_category, t.participant_id "
        "FROM Tournament t "
        "LEFT JOIN TournamentSchedule ts ON t.tournament_id = ts.tournament_id AND ts.venue = ? "
        "WHERE ts.tournament_id IS NULL;";

    sqlite3_stmt* stmt = prepareStatement(sql);

    sqlite3_bind_text(stmt, 1, venue.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::vector<std::string> tournament;
        tournament.push_back(std::to_string(sqlite3_column_int(stmt, 0)));
        tournament.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        tournament.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        tournament.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        tournament.push_back(std::to_string(sqlite3_column_int(stmt, 4)));
        tournament.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        tournament.push_back(std::to_string(sqlite3_column_int(stmt, 6)));

        tournaments.push_back(tournament);
    }

    sqlite3_finalize(stmt);
    closeDatabase();

    return tournaments;
}

// 8 запит використання предикату exists ....................
std::vector<std::tuple<int, std::string, std::string, std::string>> Tournament::findParticipantsNotPlayedInCompletedMatches() {
    std::vector<std::tuple<int, std::string, std::string, std::string>> participants;
    std::string query =
        "SELECT p.participant_id, p.first_name, p.last_name, p.club_name "
        "FROM Participant p "
        "WHERE NOT EXISTS ("
        "    SELECT 1 "
        "    FROM MatchParticipants mp "
        "    WHERE mp.participant_id = p.participant_id AND mp.match_status = 'end' AND mp.participant_status = 'Played'"
        ");";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(DB) << std::endl;
        return participants;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int participantId = sqlite3_column_int(stmt, 0);
        std::string firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string clubName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        participants.emplace_back(participantId, firstName, lastName, clubName);
    }

    if (rc != SQLITE_DONE)
    {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(DB) << std::endl;
    }

    sqlite3_finalize(stmt);
    return participants;
}

std::vector<std::string> Tournament::unionTournamentsAndMatchesWithComments()
{
    std::vector<std::string> results;

    if (!openDatabase())
    {
        std::cerr << "Failed to open database." << std::endl;
        return results;
    }

    std::string sql =
        "SELECT tournament_id AS ID, name || ' (' || tournament_date || ')' AS Info, 'Tournament' AS Comment "
        "FROM Tournament "
        "UNION "
        "SELECT match_id AS ID, 'Match on ' || date || ' with result ' || result AS Info, 'Match' AS Comment "
        "FROM Match;";

    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string result;
        result += "ID: " + std::to_string(sqlite3_column_int(stmt, 0)) + "\n";
        result += "Info: " + std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) + "\n";
        result += "Comment: " + std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))) + "\n\n";
        results.push_back(result);
    }

    sqlite3_finalize(stmt);
    closeDatabase();

    return results;
}

// метод для Combobox clubs naem
std::vector<std::string> Tournament::getClubNames()
{
    std::vector<std::string> ClubNamesIds;
    std::string sql = "SELECT club_name FROM Participant;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text != nullptr)
        {
            ClubNamesIds.push_back(reinterpret_cast<const char*>(text));
        }
    }

    sqlite3_finalize(stmt);
    return ClubNamesIds;
}