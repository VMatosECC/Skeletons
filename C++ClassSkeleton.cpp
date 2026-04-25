#include "C++ClassSkeleton.h"

// -------------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------------
ClassName::ClassName(int i, double d, const std::string& s)
    : memberInt(i), memberDouble(d), memberString(s)
{
}

// -------------------------------------------------------------------------
// Copy constructor
// -------------------------------------------------------------------------
ClassName::ClassName(const ClassName& other)
    : memberInt(other.memberInt),
      memberDouble(other.memberDouble),
      memberString(other.memberString)
{
}

// -------------------------------------------------------------------------
// Overloaded assignment operator
// -------------------------------------------------------------------------
ClassName& ClassName::operator=(const ClassName& rhs)
{
    if (this != &rhs) {
        memberInt    = rhs.memberInt;
        memberDouble = rhs.memberDouble;
        memberString = rhs.memberString;
    }
    return *this;
}

// -------------------------------------------------------------------------
// toString
// -------------------------------------------------------------------------
std::string ClassName::toString() const
{
    std::stringstream ss;
    ss << "memberInt: "    << memberInt
       << ", memberDouble: " << memberDouble
       << ", memberString: " << memberString;
    return ss.str();
}

// -------------------------------------------------------------------------
// Friend insertion operator
// -------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const ClassName& obj)
{
    out << obj.toString();
    return out;
}
