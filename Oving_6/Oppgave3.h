#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
private:
    map<string, string> courses;
public:
    void addCourse(string emnekode, string emnenavn);
    void addCourseWithOperator(string emnekode, string emnenavn);
    void removeCourse(string emnekode);
    string getcourse(string emnekode);
    friend ostream& operator<<(ostream&, const CourseCatalog&);
    void addToFile(string filename, CourseCatalog emnekatalog);
    void getFromFile(string filename);
};

