#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <algorithm>
#include <map>
#include <string>

using namespace std;

namespace grade_school {
    class school {
    public:
        school() {}

        school &add(string name, int grade) {
            auto it = students_by_grade.find(grade);

            if (it == students_by_grade.end()) {
                vector<string> students(1, name);

                students_by_grade.insert(pair<int, vector<string>>(grade, students));
            } else {
                vector<string> &students = (*it).second;

                if (find(students.begin(), students.end(), name) == students.end())
                {
                    students.push_back(name);

                    sort(students.begin(), students.end());
                }
            }

            return *this;
        }

        const map<int, vector<string>> &roster(void) {
            return students_by_grade;
        }

        const vector<string> grade(int which) {
            auto it = students_by_grade.find(which);

            return it == students_by_grade.end() ? vector<string>() : (*it).second;
        }
    private:
        map<int, vector<string>> students_by_grade;
    };
}

#endif

//
//  This solution uses a map to store students by grade.
//
//  My solution is longer than all the others, this is partly because the
//  others use less white space and partly because they use a header and an
//  implementation file and finally because the shorter ones will happily add
//  the same student twice to the same grade.
//
//  Two solutions used sort as I did (and checked for duplicates first).  The
//  others all used insert() with an iterator returned by one of lower_bound(),
//  upper_bound() or equal_bound().  I suspect this last is the only way to be
//  sure of avoiding duplicates.
//
