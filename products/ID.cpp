#pragma once
#include <unordered_map>
enum class ID { CAT = 1, DOG, ACQUAIRIUM,FISH };

std::unordered_map<ID, std::string> ClassNames{
    std::pair<ID, std::string>(ID::CAT, "cat price name"),
    std::pair<ID, std::string>(ID::DOG, "dog price name breed"),
    std::pair<ID, std::string>(ID::FISH, "fis price color breed"),
    std::pair<ID, std::string>(ID::ACQUAIRIUM, "acq price volume m^3")
};