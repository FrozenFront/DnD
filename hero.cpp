#include "hero.hpp"

hero::hero(){
    health_point = 100;
    mana_point = 10;
    mind = 100;
    level = 1;
    name = "";
    money = 10;
    carma = 100;
    strength = 0;
    dexterity = 0;
    intelligence = 0;
    charm = 0;
    endurance = 0;
    klas = "";
    story = "";
};

hero::~hero(){};

int hero::get_money(){
    return money;
};

int hero::get_carma(){
    return carma;
}; 

int hero::get_strength(){
    return strength;
};

int hero::get_dexterity(){
    return dexterity;
};

int hero::get_intelligence(){
    return intelligence;
};

int hero::get_charm(){
    return charm;
};

int hero::get_endurance(){
    return endurance;
};

void hero::set_money(int money_def){
    money += money_def;
};

void hero::set_carma(int carma_def){
    carma += carma_def;
};

void hero::set_strength(int strength_def){
    strength += strength_def;
};

void hero::set_dexterity(int dexterity_def){
    dexterity += dexterity_def;
};

void hero::set_intelligence(int intelligence_def){
    intelligence += intelligence_def;
};

void hero::set_charm(int charm_def){
    charm += charm_def;
};

void hero::set_endurance(int endurance_def){
    endurance += endurance_def;
};

void hero::set_story(std::string story_def){
    story = story_def;
};

void hero::set_klas(std::string klas_def){
    klas = klas_def;
};

std::string hero::get_story(){
    return story;
};

std::string hero::get_klas(){
    return klas;
};