#ifndef HERO_ct
#define HERO_ct

#include "character.hpp"
#include <string.h>

class hero: public character{
    private:
        std::string story;
        int money;
        int carma;
        int strength;
        int dexterity;
        int intelligence;
        int charm;
        int endurance;
        std::string klas;
        
    public:
        hero();
        ~hero();
        int get_money();
        int get_carma();
        int get_strength();
        int get_dexterity();
        int get_intelligence();
        int get_charm();
        int get_endurance();
        std::string get_story();
        std::string get_klas();
        void set_money(int money_def);
        void set_carma(int carma_def);
        void set_strength(int strength_def);
        void set_dexterity(int dexterity_def);
        void set_intelligence(int intelligence_def);
        void set_charm(int charm_def);
        void set_endurance(int endurance_def);
        void set_story(std::string story_def);
        void set_klas(std::string klas_def);
};

#endif