#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <algorithm>
#include <map>
#include <string>

namespace grade_school {
    using namespace std;

    class school {
    public:
        school() {}

        school &add(string name, int grade) {
            auto& students = students_by_grade[grade];
            auto range = equal_range(students.begin(), students.end(), name);

            if (range.first == range.second)
                students.insert(range.first, name);

            return *this;
        }

        const map<int, vector<string>> &roster(void) {
            return students_by_grade;
        }

        const vector<string> grade(int grade) {
            auto it = students_by_grade.find(grade);

            return it == students_by_grade.end() ? vector<string>() : (*it).second;
        }
    private:
        map<int, vector<string>> students_by_grade;
    };
}

#endif

//
//  This solution uses equal_range() to avoid adding duplicates and also avoid
//  the need to sort the vector of names over and over.  It also relies on
//  map::[] to insert and return an empty vector first time.
//
//  This result is significantly shorter and less complex.
//
