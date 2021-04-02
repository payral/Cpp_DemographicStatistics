#ifndef RATING_H
#define RATING_H

#include <string>
#include <iostream>

using namespace std;

class rating
{
    public:
        // constructor that takes in a number
        rating(double inR) : sum(0.0), count(0), num(true)
        {
            if (inR > 0)
            {
                sum = inR;
                count = 1;
            }
        }

        // constructor that takes in a string
        rating(string inR) : sum(0.0), count(0), num(false)
        {
            if (inR == "Below")
            {
                sum = 1.0;
                count = 1;
            }
            else if (inR == "Same")
            {
                sum = 2.0;
                count = 1;
            }
            else if (inR == "Above")
            {
                sum = 3.0;
                count = 1;
            }
        }

        double getSum() const { return sum; }
        int getCount() const { return count; }

        // a method to return a string based on the current rating
        const string getRating() const;

        double getRatingNum() const
        {
            if (count != 0)
                return sum / count;
            else
                return 0.0;
        }

        friend ostream& operator<<(ostream& out, const rating& r)
        {
            if (r.num)
                out << r.getRatingNum();
            else
                out << r.getRating();
            return out;
        }

        // operator overload
        rating& operator+=(const rating& r)
        {
            sum += r.getSum();
            count += r.getCount();
            return *this;
        }

        const bool operator<(const rating& r) const
        {
            return getRatingNum() < r.getRatingNum();
        }

    private:
        double sum;
        int count;
        const bool num;
};

#endif
