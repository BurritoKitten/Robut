#include <math.h>    /* cos */
#include <algorithm> /* max */

#define PI 3.14159265

using namespace vex;


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

    //void moveDistance(int dist, int direction, double speed)
    //void moveDistance(int dist, int direction)

    void move(int direction, double speed, int turnSpeed)
    {
        m0_ = speed * cos((direction + 210) * PI / 180);
        m1_ = speed * cos((direction + 330) * PI / 180);
        m2_ = speed * cos((direction + 90) * PI / 180);
        m0_ = (m0_+turnSpeed)*0.5;
        m1_ = (m1_+turnSpeed)*0.5;
        m2_ = (m2_+turnSpeed)*0.5;
        this -> updateMovement();
    }

    void move(int direction, double speed)
    {
        // written in radians bc degrees don't exist. Input in degrees bc it's convenient.
        m0_ = speed * cos((direction + 210) * PI / 180);
        m1_ = speed * cos((direction + 330) * PI / 180);
        m2_ = speed * cos((direction + 90) * PI / 180);
        this -> updateMovement();
    }

    void move(int direction)
    {
        m0_ = cos((direction + 210) * PI / 180);
        m1_ = cos((direction + 330) * PI / 180);
        m2_ = cos((direction + 90) * PI / 180);
        double speed = 100 / std::max(m0_, std::max(m1_, m2_));
        m0_ *= speed;
        m1_ *= speed;
        m2_ *= speed;
        this -> updateMovement();
    }

    //void turn(double speed, int degrees)

    void turn(double speed)
    {
        m0_ = speed;
        m1_ = speed;
        m2_ = speed;
        this -> updateMovement();
    }

    void turn(turnType direction)
    {
        m0_ = 100;
        m1_ = 100;
        m2_ = 100;
        if (direction == left)
        {
            m0_ *= -1;
            m1_ *= -1;
            m2_ *= -1;
        }
        this -> updateMovement();
    }


    void stop()
    {
        m0_ = 0;
        m1_ = 0;
        m2_ = 0;
        this -> updateMovement();
    }

    void updateMovement()
    {
        motor0.spin(fwd, -m0_, pct);
        motor1.spin(fwd, -m1_, pct);
        motor2.spin(fwd, -m2_, pct);
    }
};