#include "Match.h"
#include <iostream>
#include <sstream>
#include  <vector>
#include <sqlite3.h>
#include <tuple>

Match::Match(const std::string& dbPath) : DatabaseHandler(dbPath) {}

// додавання інформації про матч 
bool Match::addMatchInfo(const MatchInfo& match)
{
    std::string sql = "INSERT INTO Match (result, date, tournament_id, winner) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    if (sqlite3_bind_text(stmt, 1, match.result.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 2, match.date.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
        sqlite3_bind_int(stmt, 3, match.tournamentId) != SQLITE_OK ||
        sqlite3_bind_text(stmt, 4, match.winner.c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
    {
        std::cerr << "Error binding values: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    return executeStatement(stmt);

    sqlite3_finalize(stmt);
    return true;
}

// додавання до таблиці MatchParticipant
bool Match::addParticipantMatch(const ParticipantMatch& participantMatch)
{
    std::string sql = "INSERT INTO MatchParticipants (participant_id, match_id, match_status, participant_status) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt = prepareStatement(sql);

    sqlite3_bind_int(stmt, 1, participantMatch.participantId);
    sqlite3_bind_int(stmt, 2, participantMatch.matchId);
    sqlite3_bind_text(stmt, 3, participantMatch.matchStatus.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, participantMatch.participantStatus.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

// combobox для дати
std::vector<std::string> Match::getTournamentDates()
{
    std::vector<std::string> dates;
    std::string sql = "SELECT DISTINCT tournament_date FROM Tournament;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        dates.push_back(date);
    }

    sqlite3_finalize(stmt);

    return dates;
}

// combobox для id турнірів
std::vector<int> Match::getTournamentIds()
{
    std::vector<int> ids;
    std::string sql = "SELECT DISTINCT tournament_id FROM Tournament;";
    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        ids.push_back(id);
    }

    sqlite3_finalize(stmt);
    return ids;
}

// combobox для id гравців
std::vector<std::string> Match::getParticipantIds()
{
    std::vector<std::string> participantIds;
    std::string sql = "SELECT DISTINCT participant_id FROM Participant;";

    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text != nullptr)
        {
            participantIds.push_back(reinterpret_cast<const char*>(text));
        }
    }

    sqlite3_finalize(stmt);
    return participantIds;
}

// combobox для матч id
std::vector<int> Match::getMatchIds()
{
    std::vector<int> matchIds;
    std::string sql = "SELECT match_id FROM Match;";

    sqlite3_stmt* stmt = prepareStatement(sql);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int matchId = sqlite3_column_int(stmt, 0);
        matchIds.push_back(matchId);
    }

    sqlite3_finalize(stmt);
    return matchIds;
}