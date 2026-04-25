#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ClassName {
private:
    // -------------------------------------------------------------------------
    // Private member variables
    // -------------------------------------------------------------------------
    int    memberInt;
    double memberDouble;
    string memberString;
    int*   memberIntPtr; // A shared resource (requires special handling)  

public:
    // -------------------------------------------------------------------------
    // Mutators (setters) - This is the preferred way to modify member variables, 
    // as it allows for encapsulation and validation of input values.
    // -------------------------------------------------------------------------
    void setMemberInt(int value) { memberInt = value; }
    void setMemberDouble(double value) { memberDouble = value; }
    void setMemberString(const string& value) { memberString = value; }
    void setMemberIntPtr(int* ptr) { memberIntPtr = ptr; }

    // -------------------------------------------------------------------------
    // Accessors (getters)
    // -------------------------------------------------------------------------
    int    getMemberInt()    const { return memberInt; }
    double getMemberDouble() const { return memberDouble; }
    string getMemberString() const { return memberString; }
    int*   getMemberIntPtr() const { return memberIntPtr; }

    // -------------------------------------------------------------------------
    // Constructor – all parameters carry default values
    // -------------------------------------------------------------------------
    ClassName(int    i = 0, double d = 0.0, const string& s = "", int* ptr = nullptr)
    {
        setMemberInt(i);
        setMemberDouble(d);
        setMemberString(s);
        setMemberIntPtr(ptr); // Initialize pointer to provided value or null
    }   

    // -------------------------------------------------------------------------
    // Copy constructor 
    // Caution when using shared resources such as pointers, file handles, etc.
    // -------------------------------------------------------------------------
    ClassName(const ClassName& other);

    // -------------------------------------------------------------------------
    // Overloaded assignment operator
    // -------------------------------------------------------------------------
    ClassName& operator=(const ClassName& rhs);

    // -------------------------------------------------------------------------
    // toString – appends the object's state to a stringstream and returns it
    // -------------------------------------------------------------------------
    string toString() const;

    // -------------------------------------------------------------------------
    // Friend insertion operator
    // -------------------------------------------------------------------------
    friend ostream& operator<<(ostream& out, const ClassName& obj);
};

// IMPLEMENTATION ===============================================================
// Note: In practice, the implementation would typically be in a separate 
// .cpp file, but for this example, it's included here for completeness.
//=============================================================================



// -------------------------------------------------------------------------
// Copy constructor
// -------------------------------------------------------------------------
ClassName::ClassName(const ClassName& other)
{
    // Deep copy of member variables    
    setMemberInt(other.memberInt);
    setMemberDouble(other.memberDouble);
    setMemberString(other.memberString);
    // Make a deep copy of the pointer if it's not null, otherwise set to null
    if (other.memberIntPtr != nullptr) {
        setMemberIntPtr(new int(*other.memberIntPtr));
    } else {
        setMemberIntPtr(nullptr);
    }
}

// -------------------------------------------------------------------------
// Overloaded assignment operator
// -------------------------------------------------------------------------
ClassName& ClassName::operator=(const ClassName& rhs)
{
    if (this != &rhs) {
        setMemberInt(rhs.memberInt);
        setMemberDouble(rhs.memberDouble);
        setMemberString(rhs.memberString);
        if (rhs.memberIntPtr != nullptr) {
            setMemberIntPtr(new int(*rhs.memberIntPtr));
        } else {
            setMemberIntPtr(nullptr);
        }
    }
    return *this;
}

// -------------------------------------------------------------------------
// toString
// -------------------------------------------------------------------------
string ClassName::toString() const
{
    stringstream sout;
    sout << "memberInt: " << memberInt
        << ", memberDouble: " << memberDouble
        << ", memberString: " << memberString;
    return sout.str();
}

// -------------------------------------------------------------------------
// Friend insertion operator
// -------------------------------------------------------------------------
ostream& operator<<(ostream& sout, const ClassName& obj)
{
    sout << obj.toString();
    return sout;
}
