#ifndef ROULETTE_H
#define ROULETTE_H

#include "stdc++.h"
#include "include.h"
#include "player.h"
#include "listPlayer.h"


class Player;
class ListPlayer;
class Roulette{
    private:
        int N;
        ListPlayer *list;
        std::string username, password;

        int const Min = 1, Max = 36;
        int number, random;
        double money = 200, bet;
        char stop;
        
    public:
        Roulette();
        //Roulette(int N);
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
        void Profile();


        void mainGame();
        void numbers();
        void even_odd();
        void color();
        void mix();

};

#endif