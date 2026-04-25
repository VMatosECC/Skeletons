#pragma once
#include <iostream>
#include <sstream>
#include <string>

class ClassName {
private:
    // -------------------------------------------------------------------------
    // Private member variables
    // -------------------------------------------------------------------------
    int    memberInt;
    double memberDouble;
    std::string memberString;

public:
    // -------------------------------------------------------------------------
    // Mutators (setters)
    // -------------------------------------------------------------------------
    void setMemberInt(int value)            { memberInt    = value; }
    void setMemberDouble(double value)      { memberDouble = value; }
    void setMemberString(const std::string& value) { memberString = value; }

    // -------------------------------------------------------------------------
    // Accessors (getters)
    // -------------------------------------------------------------------------
    int         getMemberInt()    const { return memberInt;    }
    double      getMemberDouble() const { return memberDouble; }
    std::string getMemberString() const { return memberString; }

    // -------------------------------------------------------------------------
    // Constructor – all parameters carry default values
    // -------------------------------------------------------------------------
    ClassName(int    i = 0,
              double d = 0.0,
              const std::string& s = "");

    // -------------------------------------------------------------------------
    // Copy constructor
    // -------------------------------------------------------------------------
    ClassName(const ClassName& other);

    // -------------------------------------------------------------------------
    // Overloaded assignment operator
    // -------------------------------------------------------------------------
    ClassName& operator=(const ClassName& rhs);

    // -------------------------------------------------------------------------
    // toString – appends the object's state to a stringstream and returns it
    // -------------------------------------------------------------------------
    std::string toString() const;

    // -------------------------------------------------------------------------
    // Friend insertion operator
    // -------------------------------------------------------------------------
    friend std::ostream& operator<<(std::ostream& out, const ClassName& obj);
};
