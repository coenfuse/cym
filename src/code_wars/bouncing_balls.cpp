// A child is playing with a ball on the nth floor of a tall building. The hei-
// ght of this floor, h, is known. He drops the ball out of the window. The ba-
// ll bounces (for example), to two-thirds of its height (a bounce of 0.66).
// His mother looks out of a window 1.5 meters from the ground.
// How many times will the mother see the ball pass in front of her window (in-
// cluding when it's falling and bouncing?
// Three conditions must be met for a valid experiment:
// Float parameter "h" in meters must be greater than 0
// Float parameter "bounce" must be greater than 0 and less than 1
// Float parameter "window" must be less than h.
// If all three conditions above are fulfilled, return a positive integer, oth-
// erwise return -1.

// Note:
// The ball can only be seen if the height of the rebounding ball is strictly 
// greater than the window parameter.

// Example :
// - h = 3, bounce = 0.66, window = 1.5, result is 3
// - h = 3, bounce = 1, window = 1.5, result is -1 

#include <iostream>

// The following is the boilerplate code given in the question

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window){

        if(h > 0 && bounce > 0 && bounce < 1 && window < h){

            int visible_count = 1;          // During the first drop, mother will see the ball.

            while( h > window){             // Here we'll count the rebounce visibility.
                visible_count++;
                h = h * bounce;
            }

            return visible_count;

        }

        return -1;
    }
};

// Just for local test purposes

int main(){

    Bouncingball BouncyBaby;
    std::cout << BouncyBaby.bouncingBall(503,0.66,1.5);
    return 0;

}
