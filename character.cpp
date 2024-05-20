#include "character.hpp"

character::character(){};
character::~character(){};

int character::get_health(){
    return health_point;
};

int character::get_mana(){
    return mana_point;
};

int character::get_mind(){
    return mind;
};

int character::get_level(){
    return level;
};

void character::set_health(int health_def){
    health_point += health_def;
};

void character::set_mana(int mana_def){
    mana_point += mana_def;
};

void character::set_mind(int mind_def){
    mind += mind_def;
};

void character::set_name(std::string name_def){
    name = name_def;
};

void character::set_level(int level_def){
    level += level_def;
}