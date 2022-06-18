#ifndef PR_1_POLYNOM_HPP
#define PR_1_POLYNOM_HPP

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// полином
class Polynom {
private:
    vector<double> coefs;

public:
    Polynom() : coefs({0}) {}

    Polynom(vector<double> c) : coefs(c) {}

    Polynom(initializer_list<double> c) : coefs(c) {}

    Polynom(const Polynom &p) : coefs(p.coefs) {}

    Polynom &operator=(const Polynom &rhs) {
        coefs = rhs.coefs;
        return *this;
    }

    friend bool operator==(const Polynom &lhs, const Polynom &rhs) {
        return lhs.coefs == rhs.coefs;
    }

    friend bool operator!=(const Polynom &lhs, const Polynom &rhs) {
        return !(lhs == rhs);
    }

    Polynom &operator+=(const Polynom &rhs) {
        for (int i = 0; i < coefs.size() && i < rhs.coefs.size(); ++i) {
            coefs[i] += rhs.coefs[i];
        }
        if (rhs.coefs.size() > coefs.size()) {
            for (int i = coefs.size(); i < rhs.coefs.size(); ++i) {
                coefs.push_back(rhs.coefs[i]);
            }
        }

        return *this;
    }

    Polynom &operator-=(const Polynom &rhs) {
        for (int i = 0; i < coefs.size() && i < rhs.coefs.size(); ++i) {
            coefs[i] -= rhs.coefs[i];
        }
        if (rhs.coefs.size() > coefs.size()) {
            for (int i = coefs.size(); i < rhs.coefs.size(); ++i) {
                coefs.push_back(-rhs.coefs[i]);
            }
        }

        return *this;
    }

    Polynom &operator*=(double multiplier) {
        for (auto &coef: coefs) {
            coef *= multiplier;
        }
        return *this;
    }

    Polynom &operator/=(double multiplier) {
        for (auto &coef: coefs) {
            coef /= multiplier;
        }
        return *this;
    }


    Polynom operator-() {
        Polynom neg(*this);
        for (auto &coef: neg.coefs) {
            coef = -coef;
        }

        return neg;
    }

    friend Polynom operator+(const Polynom &lhs, const Polynom &rhs) {
        Polynom res(lhs);
        res += rhs;
        return res;
    }

    friend Polynom operator-(const Polynom &lhs, const Polynom &rhs) {
        Polynom res(lhs);
        res -= rhs;
        return res;
    }

    friend Polynom operator*(const Polynom &lhs, double rhs) {
        Polynom res(lhs);
        res *= rhs;
        return res;
    }

    friend Polynom operator/(const Polynom &lhs, double rhs) {
        Polynom res(lhs);
        res /= rhs;
        return res;
    }

    double &operator[](size_t index) {
        if (index >= coefs.size()) {
            coefs.resize(coefs.size() + (index - coefs.size() + 1));
        }
        return coefs[index];
    }

    double operator[](size_t index) const {
        if (index >= coefs.size()) {
            return 0;
        }
        return coefs[index];
    }

    double operator()(double x) const {
        double result = coefs.front();
        for (size_t power = 1; power < coefs.size(); ++power) {
            result += pow(x, power) * coefs[power];
        }
        return result;
    }

    friend ostream &operator<<(ostream &os, const Polynom &rhs) {
        if (rhs.coefs.back() != 1 || rhs.coefs.size() <= 2) {
            os << rhs.coefs.back();
        }
        if (rhs.coefs.size() >= 2) {
            os << "x";
        }
        if (rhs.coefs.size() >= 3) {
            os << "^" << rhs.coefs.size() - 1;
        }

        if (rhs.coefs.size() < 2) {
            return os;
        }

        for (size_t i = rhs.coefs.size() - 2; i != 0; --i) {
            if (rhs.coefs[i] == 0)
                continue;

            os << (rhs.coefs[i] < 0 ? " - " : " + ");
            if (rhs.coefs[i] != 1) {
                os << abs(rhs.coefs[i]);
            }
            os << "x";
            if (i != 1) {
                os << "^" << i;
            }
        }

        if (rhs.coefs.front() != 0) {
            os << (rhs.coefs.front() < 0 ? " - " : " + ") << abs(rhs.coefs.front());
        }

        return os;
    }

    friend istream &operator>>(istream &is, Polynom &rhs) {
        rhs.coefs.clear();
        while (!is.eof()) {
            double coef;
            is >> coef;
            if (is.fail()) {
                break;
            }
            rhs.coefs.push_back(coef);
        }

        return is;
    }
};

#endif //PR_1_POLYNOM_HPP
