#if !defined(MEETUP_H)
#define MEETUP_H

#include <iostream>
#include <boost/date_time/gregorian/gregorian_io.hpp>

namespace meetup {
    using namespace boost::gregorian;

    class scheduler {
    public:
        explicit scheduler(date::month_type month, date::year_type year):
            month(month), year(year) {}

        date monteenth       () const { return teenth(Monday);        };
        date tuesteenth      () const { return teenth(Tuesday);       };
        date wednesteenth    () const { return teenth(Wednesday);     };
        date thursteenth     () const { return teenth(Thursday);      };
        date friteenth       () const { return teenth(Friday);        };
        date saturteenth     () const { return teenth(Saturday);      };
        date sunteenth       () const { return teenth(Sunday);        };

        date first_monday    () const { return firstWeek(Monday);     };
        date first_tuesday   () const { return firstWeek(Tuesday);    };
        date first_wednesday () const { return firstWeek(Wednesday);  };
        date first_thursday  () const { return firstWeek(Thursday);   };
        date first_friday    () const { return firstWeek(Friday);     };
        date first_saturday  () const { return firstWeek(Saturday);   };
        date first_sunday    () const { return firstWeek(Sunday);     };

        date second_monday   () const { return secondWeek(Monday);    };
        date second_tuesday  () const { return secondWeek(Tuesday);   };
        date second_wednesday() const { return secondWeek(Wednesday); };
        date second_thursday () const { return secondWeek(Thursday);  };
        date second_friday   () const { return secondWeek(Friday);    };
        date second_saturday () const { return secondWeek(Saturday);  };
        date second_sunday   () const { return secondWeek(Sunday);    };

        date third_monday    () const { return thirdWeek(Monday);     };
        date third_tuesday   () const { return thirdWeek(Tuesday);    };
        date third_wednesday () const { return thirdWeek(Wednesday);  };
        date third_thursday  () const { return thirdWeek(Thursday);   };
        date third_friday    () const { return thirdWeek(Friday);     };
        date third_saturday  () const { return thirdWeek(Saturday);   };
        date third_sunday    () const { return thirdWeek(Sunday);     };

        date fourth_monday   () const { return fourthWeek(Monday);    };
        date fourth_tuesday  () const { return fourthWeek(Tuesday);   };
        date fourth_wednesday() const { return fourthWeek(Wednesday); };
        date fourth_thursday () const { return fourthWeek(Thursday);  };
        date fourth_friday   () const { return fourthWeek(Friday);    };
        date fourth_saturday () const { return fourthWeek(Saturday);  };
        date fourth_sunday   () const { return fourthWeek(Sunday);    };

        date last_monday     () const { return lastWeek(Monday);      };
        date last_tuesday    () const { return lastWeek(Tuesday);     };
        date last_wednesday  () const { return lastWeek(Wednesday);   };
        date last_thursday   () const { return lastWeek(Thursday);    };
        date last_friday     () const { return lastWeek(Friday);      };
        date last_saturday   () const { return lastWeek(Saturday);    };
        date last_sunday     () const { return lastWeek(Sunday);      };
    private:
        date::month_type month;
        date::year_type year;

        date firstAfter (boost::date_time::weekdays weekday, long earliest) const {
            date meeting(year, month, earliest + 1);

            while(meeting.day_of_week() != weekday)
                meeting += date_duration(1);

            return meeting;
        };

        date teenth     (boost::date_time::weekdays weekday) const { return firstAfter(weekday, 12); };
        date firstWeek  (boost::date_time::weekdays weekday) const { return firstAfter(weekday,  0); };
        date secondWeek (boost::date_time::weekdays weekday) const { return firstAfter(weekday,  7); };
        date thirdWeek  (boost::date_time::weekdays weekday) const { return firstAfter(weekday, 14); };
        date fourthWeek (boost::date_time::weekdays weekday) const { return firstAfter(weekday, 21); };

        date lastWeek   (boost::date_time::weekdays weekday) const {
            date meeting(year, month, 1);

            const long daysInMonth = (meeting.end_of_month() - meeting).days();

            return firstAfter(weekday, daysInMonth + 1 - 7);
        };
    };
}

#endif

//
//  This solution has a lot of very small functions.  Can anyone do better ?
//
//  I implemented firstAfter() and lastWeek() from scratch.  Apparently there
//  are functions in the boost Gregorian library to do this for you.  All,
//  except one, used these although the uses of `using` helped obscure these.
//  The exception used a `map` set up in the constructor.
//
//  Note `using` may be used to not just alias namespace/classes but functions
//  as well.
//
//  Half of the solutions used #define to shorten their implementation:  one
//  macro invocation generated four-six functions.  One used boost to generate
//  7 macro invocations from one invocation.
//
//  In some cases two macros were need:  one for declaration, the other for
//  definition.  I am not convinced these did not detract from 'readability'
//  particularly for the 'header file' declarations.
//
