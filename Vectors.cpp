#include <cmath>

using namespace std;

//Class to make vector manipuilation easy
class Direction_Vector{
    public:
    float speed, Xangle,Yangle,Zangle,Xspeed,Yspeed,Zspeed;
   
    //convert to compenent form
    void find_components(){
        Xspeed = speed * cos(Xangle);
        Yspeed = speed * cos(Yangle);
        Zspeed = speed * cos(Zangle);
    
    }
    //Convert to magnitude angle form with direction cosines
    void find_angle(){
        speed = sqrt(pow(Xspeed,2)+pow(Yspeed,2)+pow(Zspeed,2));
        Xangle = acos(Xspeed/speed);
        Yangle = acos(Yspeed/speed);
        Zangle = acos(Zspeed/speed);
    }
};
//Class to make position manipulation easy
class Position_Vector{
public:
    float Xcoord, Ycoord, Zcoord;
    Position_Vector();
    Position_Vector(float newXcoord, float newYcoord,float newZcoord);



    //overload = to make agjustments more easily
    void operator=(const Position_Vector& vector1){
        Xcoord = vector1.Xcoord;
        Ycoord = vector1.Ycoord;
        Zcoord = vector1.Zcoord;
    }

};
Position_Vector::Position_Vector():Xcoord(0),Ycoord(0),Zcoord(0){}

Position_Vector:: Position_Vector(float newXcoord, float newYcoord,float newZcoord){
     Xcoord = newXcoord;
     Ycoord = newYcoord;
     Zcoord = newZcoord;
}


