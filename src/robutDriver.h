#include <math.h>    /* cos */
#include <algorithm> /* max */

#define PI 3.14159265

class robutMovement
{
private:
    double m0_ = 0;
    double m1_ = 0;
    double m2_ = 0;
    motor motor0, motor1, motor2;

public:
    robutMovement(motor motor0in, motor motor1in, motor motor2in) : motor0(motor0in), motor1(motor1in), motor2(motor2in) {}

    double m0() { return m0_; }
    double m1() { return m1_; }
    double m2() { return m2_; }

    void vectorToControl(double speed, int direction)
    {
        m0_ = speed * cos((direction + 210) * PI / 180);
        m1_ = speed * cos((direction + 330) * PI / 180);
        m2_ = speed * cos((direction + 90) * PI / 180);
    }

    void vectorToControl(int direction)
    {
        m0_ = cos((direction + 210) * PI / 180);
        m1_ = cos((direction + 330) * PI / 180);
        m2_ = cos((direction + 90) * PI / 180);
        double speed = 100 / std::max(m0_, m1_, m2_);
        m0_ *= speed;
        m1_ *= speed;
        m2_ *= speed;
    }

    void steerToControl(double speed, turnType direction)
    {
        m0_ = 100 * speed;
        m1_ = 100 * speed;
        m2_ = 100 * speed;
        if (direction == right)
        {
            m0_ *= -1;
            m1_ *= -1;
            m2_ *= -1;
        }
    }

    void stop()
    {
        m0_ = 0;
        m1_ = 1;
        m2_ = 2;
    }

    void updateMovement()
    {
        motor0.spin(fwd, m0_, pct);
        motor1.spin(fwd, m1_, pct);
        motor2.spin(fwd, m2_, pct);
    }
};