#pragma once

#include <string>
#include <iostream>

//! Interface for Human child classes
class Human
{
protected:
    std::string firstName, lastName;

public:
    //! Creates default valued Human object
    explicit Human() {}
    //! Creates Human with the given firstName, lastName arguments
    explicit Human(std::string fN, std::string lN) : firstName(fN), lastName(lN) {}
    //! The Human destructor is default
    virtual ~Human() = default;

    //! Human First Name getter
    inline virtual std::string getFirstName() const { return firstName; }
    //! Human Last Name getter
    inline virtual std::string getLastName() const { return lastName; }
    //! Human Full Name getter
    inline virtual std::string getFullName() const { return firstName + " " + lastName; }

    //! Human First Name setter
    inline virtual void setFirstName(std::string fN) { firstName = fN; }
    //! Human Last Name setter
    inline virtual void setLastName(std::string lN) { lastName = lN; }
    //! Human Full Name setter
    inline virtual void setName(std::string fN, std::string lN) { firstName = fN, lastName = lN; }

    //! Pure virtual function for printing credentials of Humans
    virtual std::ostream &printCredentials(std::ostream &) const = 0;
};
