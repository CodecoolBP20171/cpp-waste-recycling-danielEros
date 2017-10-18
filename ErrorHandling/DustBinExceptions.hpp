//
// Created by eros on 17/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_DUSTBINEXCEPTIONS_HPP
#define CPP_WASTE_RECYCLING_DANIELEROS_DUSTBINEXCEPTIONS_HPP

#include <exception>

class DustbinContentError : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "This garbage cannot be put in the dustbin in this form!";
    }
};

class DustbinIsFull : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "The dustbin is full!";
    }
};

#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBINEXCEPTIONS_HPP
