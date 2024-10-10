#pragma once
#include "DataBaseHandler.h"
#include <string>
#include <sqlite3.h>
#include <vector>
#include <tuple>

struct MatchInfo {
    std::string result;
    std::string date;
    int tournamentId;
    std::string winner;
};

struct ParticipantMatch {
    int participantId;
    int matchId;
    std::string matchStatus;
    std::string participantStatus;
};


class Match : public DatabaseHandler
{
public:
    Match(const std::string& dbPath);
    // додавання інформації про матч 
    bool addMatchInfo(const MatchInfo& match);
    // combobox для дати
    std::vector<std::string> getTournamentDates();
    // combobox для id турнірів
    std::vector<int> getTournamentIds();
    // combobox для id гравців
    std::vector<std::string> getParticipantIds();
    // combobox для матч id
    std::vector<int> getMatchIds();
    // додавання до таблиці MatchParticipant
    bool addParticipantMatch(const ParticipantMatch& participantMatch);
};