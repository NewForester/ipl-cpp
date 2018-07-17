#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    class space_age {
        public:
            explicit space_age(long seconds): s(seconds) {}

            long seconds() const {
                return s;
            }

            double on_mercury() const {
                return planet_years(0.2408467);
            }

            double on_venus() const {
                return planet_years(0.61519726);
            }

            double on_earth() const {
                return planet_years(1.00);
            }

            double on_mars() const {
                return planet_years(1.8808158);
            }

            double on_jupiter() const {
                return planet_years(11.862615);
            }

            double on_saturn() const {
                return planet_years(29.447498);
            }

            double on_uranus() const {
                return planet_years(84.016846);
            }

            double on_neptune() const {
                return planet_years(164.79132);
            }
    private:
            const long s;

            static constexpr double earthYearInSeconds = 31557600.0;

            double planet_years(double orbitalPeriod) const {
                return s / earthYearInSeconds / orbitalPeriod;
            }
    };
}

#endif

//
//  The class within a namespace solution was required by the tests.
//
//  This is a simple exercise but the tests required 8 callable methods.
//  There are only two choices.
//
//  The first is how 'self-explanatory' the 8 methods are.  I think mine are
//  good.  One chap went for a map.  It adds complexity but little else.
//
//  The other is how to deal with the repetition.  I went for a classic helper
//  function, which many did not.  Two used lambdas.  This way you declare
//  variables of func_type.  I don't think, overall, this helped much with this
//  exercise but for the record ...
//
//    func_type planet_years(double orbitalPeriod) {
//        return [this, orbitalPeriod] this->s / this->earthYearInSeconds / orbitalPeriod;
//    }
//
//    on_mercury = planet_years(0.2408467);
//
