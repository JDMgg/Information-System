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
    // ��������� ���������� ��� ���� 
    bool addMatchInfo(const MatchInfo& match);
    // combobox ��� ����
    std::vector<std::string> getTournamentDates();
    // combobox ��� id ������
    std::vector<int> getTournamentIds();
    // combobox ��� id �������
    std::vector<std::string> getParticipantIds();
    // combobox ��� ���� id
    std::vector<int> getMatchIds();
    // ��������� �� ������� MatchParticipant
    bool addParticipantMatch(const ParticipantMatch& participantMatch);
};