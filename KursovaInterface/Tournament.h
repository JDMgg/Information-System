#pragma once
#include <string>
#include <sqlite3.h>
#include <vector>
#include <tuple>
#include "DataBaseHandler.h"

struct TournamentInfo
{
    int tournamentId;
    std::string name;
    std::string tournamentDate;
    std::string gameFormat;
    int ticketCount;
    std::string gameCategory;
    int participantId;

    // Конструктор за замовчуванням
    TournamentInfo() : tournamentId(0), ticketCount(0), participantId(0) {}

    // Конструктор з параметрами
    TournamentInfo(int id, const std::string& name, const std::string& date, const std::string& format,
        int count, const std::string& category, int participantId)
        : tournamentId(id), name(name), tournamentDate(date), gameFormat(format),
        ticketCount(count), gameCategory(category), participantId(participantId) {}
};

struct Participant
{
    std::string clubName;
    std::string birthDate;
    std::string lastName;
    std::string playerClass;
    std::string firstName;

};

class Tournament : public DatabaseHandler {
public:
    Tournament(const std::string& dbPath);
    // Метод для додавання турніру
    bool addTournament(const std::string& name, const std::string& tournamentDate, const std::string& gameFormat, int ticketCount, const std::string& gameCategory, const std::string& participantId);
    // Метод для додавання розкладу турніра
    bool addTournamentSchedule(int tournamentId, const std::string& venue);
    // метод для додавання учасників турніру
    bool addParticipant(const Participant& participant);
    // 8 запит Заперечення IN
    std::vector<std::string> findPlayersWithSameClub(const std::string& clubName);
    // метод для Combobox clubs naem
    std::vector<std::string> getClubNames();
    // 4 запит загальна кількість гравців агрегатна без угрупування 
    std::vector<std::string> displayAllPlayerInfo();
    // 8 запит на заперечення з використанням left join
    std::vector<std::vector<std::string>> findTournamentsNotHeldAtVenue(const std::string& venue);
    // 8 запит exists
    std::vector<std::tuple<int, std::string, std::string, std::string>> findParticipantsNotPlayedInCompletedMatches();
    // 9 запит
    std::vector<std::string> unionTournamentsAndMatchesWithComments();
};