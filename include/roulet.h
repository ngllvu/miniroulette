#ifndef ROULETTE_H
#define ROULETTE_H

#include "stdc++.h"
#include "include.h"
#include "player.h"
#include "listPlayer.h"
#include "bet.h"

class Bet;
class Player;
class ListPlayer;
class Roulette{
    private:
        int N;
        ListPlayer *list;
        std::string username, password;
    public:
        Roulette();
        Roulette(int N);
        ~Roulette();

        void Menu();
        void gotoMenu(char choice);
        void exitMenu();
        void Rules(string located);

        void RegisterMenu();
        void regis_log(char auth);
        void registation();
        void login();
        void forgot();

        void saveInformation();
        void printInformation(string name, bool saved);

        Roulette mainGame();
};

#endif