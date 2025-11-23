#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus() = default;

    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = default;

    virtual std::string vardas() const = 0;
    virtual std::string pavarde() const = 0;
};

#endif
