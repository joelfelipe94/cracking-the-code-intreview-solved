// Assume you have a method isSubstring which checks if one word is a
// substring of another. Given two strings, si and s2, write code to check if s2 is
// a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rota-
// tion of "erbottlewat").
#include <string>

// check if the second string is a substring of the first one
template <typename T>
bool isSubstring(T && s1, T && s2){
    return s1.find(s2) != std::string::npos;
}

// If both strings have the same size and the second one
// can be found as a substring of the first one concatenated 
// with itself. Then they are rotations.  
bool isRotation(std::string s1, std::string s2){
    if(s1.length()!= s2.length())
        return false;
    else{
        auto doubleS1 = s1 + s1;
        return isSubstring(doubleS1, s2);
    }
}