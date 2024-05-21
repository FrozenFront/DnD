#ifndef ch_ct
#define ch_ct

#include <iostream>

class Character{
    private:
        int health_point = 0;
        int mana_point = 0;
        int mind = 10;
        int level = 1;
        std::string name = "NONe";
    public:
        Character();
        int get_health();
        int get_mana();
        int get_mind();
        int get_level();
        void set_mind(int mind_def);
        void set_health(int health_def);
        void set_mana(int mana_def);
        void set_name(std::string name_def);
        void set_level(int level_def);
};

#endif