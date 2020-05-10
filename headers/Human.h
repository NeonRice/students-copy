#pragma once

#include <string>
#include <string>

class Human
{
protected:
    std::string firstName, lastName;

public:
    explicit Human() {}
    explicit Human(std::string fN, std::string lN) : firstName(fN), lastName(lN) {}

    virtual ~Human() = default;

    inline virtual std::string getFirstName() const {return firstName; }
    inline virtual std::string getLastName() const {return lastName; }
    inline virtual std::string getFullName() const {return firstName + " " + lastName; }

    inline virtual std::string setFirstName(std::string fN) {firstName = fN; }
    inline virtual std::string setLastName(std::string lN) {lastName = lN; }
    inline virtual std::string setName(std::string fN, std::string lN) {firstName = fN, lastName = lN; }

    virtual std::ostream& printCredentials(std::ostream&) const = 0; 
};


