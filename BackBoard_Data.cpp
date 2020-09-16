using namespace std;

//Include Vectors
#include "Vectors.cpp"

//convert inches to metres
float inchesToMetres(float inches){
   return inches*0.0254;
}

class Backboard_Section
{
private:
   Position_Vector Segment;
   float angleX,angleY,angleZ;
   
public:
   Position_Vector BoardCenterPos;
   float Hoop_radius;
   Position_Vector HoopPos;

   Backboard_Section();

   Backboard_Section(Position_Vector new_Pos, float new_angleX, float new_angleY, float new_angleZ);

   Backboard_Section adjustAngle(float new_angleX, float new_angleY, float new_angleZ);

   Position_Vector getPos();

   //get X angle
   float getXangle(){
      return angleX;
   }

   //get Y angle
   float getYangle(){
      return angleY;
   }

   //get Z angle
   float getZangle(){
      return angleZ;
   }
};
Backboard_Section::Backboard_Section(){}

Backboard_Section::Backboard_Section(Position_Vector new_Pos, float new_angleX, float new_angleY, float new_angleZ):Segment(new_Pos),
   angleX(new_angleX),angleY(new_angleY),angleZ(new_angleZ),Hoop_radius(3){}  


Backboard_Section Backboard_Section::adjustAngle(float new_angleX, float new_angleY, float new_angleZ){
   angleX = new_angleX;
   angleY = new_angleY;
   angleZ = new_angleZ;
   return *this;
}

Position_Vector Backboard_Section::getPos(){
   return Segment;
}


