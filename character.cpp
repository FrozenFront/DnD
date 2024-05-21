#include "character.hpp"

Character::Character(){
};

int Character::get_health(){
    return health_point;
};

int Character::get_mana(){
    return mana_point;
};

int Character::get_mind(){
    return mind;
};

int Character::get_level(){
    return level;
};

void Character::set_health(int health_def){
    health_point += health_def;
};

void Character::set_mana(int mana_def){
    mana_point += mana_def;
};

void Character::set_mind(int mind_def){
    mind += mind_def;
};

void Character::set_name(std::string name_def){
    name = name_def;
};

void Character::set_level(int level_def){
    level += level_def;
}