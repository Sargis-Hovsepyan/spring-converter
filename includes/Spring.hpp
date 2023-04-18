#ifndef SPRING_HPP
#define SPRING_HPP


#include <vector>
#include <cmath>

using std::vector;

class Spring
{
    private:
        double _k;
    
    public:
        Spring();
        Spring(const double k);
        Spring(const Spring& other);
        ~Spring();

        Spring&             operator=(const Spring& other);

        void                setK(double k);
        double              setK(double k) const;

        vector<double>      move(double t, double dt, double x0);
        vector<double>      move(double t, double dt, double x0, double v0);

        vector<double>      move(double t0, double t1, double dt, double x0, double v0);
        vector<double>      move(double t0, double t1, double dt, double x0, double v0, double m);

        Spring&             operator+(const Spring& s); // in parallel
        Spring&             operator*(const Spring& s); // in series


    /* UTILITY METHODS */
    
    private:
        vector<double>      get_coordinates(double t0, double t1, double dt, double x0, double v0,  double mass);
        double              simple_harmonic_motion(double t, double omega, double c1, double c2);
};

#endif
