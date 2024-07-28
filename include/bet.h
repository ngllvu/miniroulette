#pragma once
#include "stdc++.h"
#include "include.h"

class Bet{
    private:
        int const Min = 1, Max = 36;
        int number, random;
        double money, bet;
        char *stop;
        friend class Roulette;
    public:
        Bet();
        Bet(int number, double money, double bet);
        ~Bet();

        void gametype();
        void numbers();
        void even_odd();
        void color();

        void mix();
};