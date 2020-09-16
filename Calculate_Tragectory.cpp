
using namespace std;
#define _USE_MATH_DEFINES

#include "BackBoard_Data.cpp"
#include <iostream>
#include <vector>
#include <cmath>

bool Calculate_Tragectory(Direction_Vector D, Backboard_Section B){
    Position_Vector Ball = B.getPos();
    Ball.Ycoord+= inchesToMetres(3);
    float t=0.01;//Time Interval
    
    //find angle of deflection
    D.Xangle = B.getXangle()-2*D.Xangle;
    D.Yangle = B.getXangle()-2*D.Yangle;
    D.Zangle = B.getXangle()-2*D.Zangle;

    D.find_components();

    //iterate height until ball is below hoop
    while(Ball.Zcoord > 0)
    {
        Ball.Zcoord = D.Zspeed*t - t*t*4.905;
        Ball.Xcoord = D.Xspeed*t + Ball.Xcoord;
        Ball.Ycoord = D.Yspeed*t + Ball.Ycoord;
        D.Zspeed = D.Zspeed-9.81*t;
        cout << Ball.Xcoord << " " << Ball.Ycoord << " " << Ball.Zcoord << " "<< endl;
    }    
    //compare position to centre of hoop
    if(pow(Ball.Xcoord,2)+pow(Ball.Ycoord,2) > pow(B.Hoop_radius,2))
        return false;
    return true;
}
//test Initial speeds and Angles
int intialSpeedTests(Backboard_Section B)
{
    int Successes;
    Direction_Vector D;
    //test speeds
    for(int speed = 0; speed+= 0.5;speed < 10)
    {
        for(float Xangle = 0; Xangle+=0.01; Xangle < M_PI)
        {
            for(float Yangle = 0; Yangle+=0.01; Yangle < M_PI)
            {
                for(float Zangle = 0; Zangle+=0.01; Zangle < M_PI)
                {   
                    D.speed = speed;
                    D.Xangle = Xangle;
                    D.Yangle = Yangle;
                    D.Zangle = Zangle;
                    if(Calculate_Tragectory(D,B))
                        Successes++;
                }
            }   
        }
    }
    return Successes;
}

//test Xangles, Yangles and Zangles
Backboard_Section testAngles(Position_Vector Board){
    float TestXangle,TestYangle,TestZangle;
    Backboard_Section BoardPart(Board,TestXangle,TestYangle,TestZangle);
    vector <Backboard_Section> Sections;
    vector <int> Successes;
    for(float TestXangle = 0; TestXangle+=0.01; TestXangle < M_PI)
        {
            for(float TestYangle = 0; TestYangle+=0.01; TestYangle < M_PI)
            {
                for(float TestZangle = 0; TestZangle+=0.01; TestZangle < M_PI)
                {
                    BoardPart.adjustAngle(TestXangle,TestYangle,TestZangle);
                    Sections.push_back(BoardPart);
                    Successes.push_back(intialSpeedTests(BoardPart));
                }
            }   
        }
    int mostSuccesses = 0;
    int bestIndex = 0;
    for(int i=0;i<Successes.size();i++)
    {
        if(!(Successes[i] < mostSuccesses)){
            //Favor smaller angles in a tie
            if(Successes[i] == mostSuccesses){
                (Sections[i].getXangle() - M_PI / 2) > abs(Sections[bestIndex].getXangle() - M_PI / 2);
            }
            else
            {
                mostSuccesses = Successes[i];
                bestIndex = i;
            }
        }
    }
    return Sections[bestIndex];
}



//Compile and output the angles
void BuildBackboard(){
    int BoardHeight = 300,BoardWidth = 100,curZ = 150;//In pieces
    float pieceSize = 0.01;


    Backboard_Section Backboard [BoardHeight][BoardWidth];
    Position_Vector CurrentPos(0.5,-0.5,1);
    while(curZ < BoardHeight)
    {
        for(int curY = 0; curY< BoardWidth; curY++)
        {
             
        }
        if(curZ>150)
        {
            curZ = 300-curZ;
            curZ--;
        }
        else
        {
            curZ = 300-curZ;
        }    
    }
    
    
}


int main(){
    const int HoopRad = 5;
    Position_Vector board(-3,2,5);
    Backboard_Section B(board,0,0,0); 
    B.Hoop_radius = HoopRad;
    Direction_Vector D;
    D.speed = 5;
    D.Xangle = 1;
    D.Yangle = 1;
    D.Zangle = 1;
    D.find_components();
    cout<< D.Xspeed << " " << D.Yspeed << " " << D.Zspeed <<endl;
    cout << "Hoop hit = " << Calculate_Tragectory(D,B) << endl;
    return 0;
}

