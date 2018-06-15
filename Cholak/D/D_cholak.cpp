#include <iostream>
#include<stdio.h>
#include<vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct robot {
    
    int x0, y0;
    bool hiden; // flag to mark if robot is hiden
    
};

int main(){
  bool debug = false;
  bool hor_line = false; // if line that connects two robots is horiaontal?
  bool ver_line = false; // if line that connects two robots is vertical?
  bool on_line = false;  // if three points are on the same line?
  int R,N, buff_x, buff_y;
  double A,B,dist_min,d_ij,d_ik, dir;
  cin>>R>>N;
  robot robot_temp; 
  vector<robot> robots; // vector of robots 
  robot rob_mass[N];
  for(int i=0; i<N; i++){  
    cin>>buff_x>>buff_y; // reading of coordinats
    robot_temp.x0 = buff_x;
    robot_temp.y0 = buff_y;
    robot_temp.hiden = false;
    rob_mass[i] = robot_temp;
    robots.push_back(robot_temp); // fillig of robots by a robot_temp  
    
  }
  if(debug) cout<<robots[0].hiden+robots[1].hiden<<endl;
  if(debug) cout<<rob_mass[0].hiden+rob_mass[1].hiden<<endl;
  
//   for(int i=0; i<N; i++){  
//     cout<<i<<" "<<robots[i].x0<<" "<<robots[i].y0<<endl;
//     
//   }
  
  for(int i=0; i<N; i++){                                              // loop over robots
   if(0) cout<<"x0= "<<rob_mass[i].x0<<endl;
   for(int j=0; (j<(N)); j++){                                // loop over lines that connect them
     if(j==i) continue;
     d_ij = sqrt((rob_mass[i].x0-rob_mass[j].x0)*(rob_mass[i].x0-rob_mass[j].x0)+(rob_mass[i].y0-rob_mass[j].y0)*(rob_mass[i].y0-rob_mass[j].y0));
     dist_min = d_ij;
     for(int k=0; (k<(N)); k++ ){                        // loop over the rest of robots
       if(k==i || k==j) continue;
       d_ik = sqrt((rob_mass[i].x0-rob_mass[k].x0)*(rob_mass[i].x0-rob_mass[k].x0)+(rob_mass[i].y0-rob_mass[k].y0)*(rob_mass[i].y0-rob_mass[k].y0));
       dir = ((rob_mass[j].x0-rob_mass[i].x0)*(rob_mass[k].x0-rob_mass[i].x0)+(rob_mass[j].y0-rob_mass[i].y0)*(rob_mass[k].y0-rob_mass[i].y0))/d_ij/d_ik; // direction cosine
//        cout<<"direction= "<<dir<<endl;
       if(abs(rob_mass[j].x0 - rob_mass[i].x0)==0){                           // check if connection line is vertical
         ver_line = true;
         if(rob_mass[k].x0==rob_mass[i].x0){ cout<<"robot N= "<<k+1<<" is on the vertical line with robots "<<i+1<<" "<<j+1<<endl; on_line = true;}
         
       }
       else {A = (rob_mass[k].x0 - rob_mass[i].x0)/double(rob_mass[j].x0 - rob_mass[i].x0); // left part of equation
       
         
      }
       
       if(abs(rob_mass[j].y0 - rob_mass[i].y0)==0){                           // check if connection line is horizontal
         hor_line = true;
         if(rob_mass[k].y0==rob_mass[i].y0){ cout<<"robot N= "<<k+1<<" is on the horizontal line with robots "<<i+1<<" "<<j+1<<endl; on_line = true;}
         
       }
       else{ B = (rob_mass[k].y0 - rob_mass[i].y0)/double(rob_mass[j].y0 - rob_mass[i].y0);
//          cout<<"B "<<rob_mass[k].y0<<" - "<<rob_mass[i].y0<<"   "<<B<<endl;
//          cout<<rob_mass[j].y0<<" - "<<rob_mass[i].y0<<endl;
       }
       
       if(A==B && (1-ver_line) && (1-hor_line)){
//          cout<<A<<" "<<B<<endl;
//          cout<<k+1<<" "<<rob_mass[k].x0<<" "<<rob_mass[k].y0<<endl;
//          cout<<i+1<<" "<<rob_mass[i].x0<<" "<<rob_mass[i].y0<<endl;
//          cout<<j+1<<" "<<rob_mass[j].x0<<" "<<rob_mass[j].y0<<endl;
//          cout<<ver_line<<" "<<hor_line<<endl;
         cout<<"robot N= "<<k+1<<" is on the line with robots "<<i+1<<" "<<j+1<<endl;
         on_line = true;
       }
       if(on_line)
         if(dir == 1){
           if(d_ik < d_ij ) cout<<"robot "<<k+1<<"is hiden for rob "<<i+1<<"by rob "<<j+1<<endl;
         }
       
       
       A = 0.1789;
       B = 0.156;
       on_line = false;
     }
   
       hor_line = false;
       ver_line = false;
       
       
    }
  }
  
  
//   cout<<robots[0].hiden+robots[1].hiden<<endl; // test
  
  
  
  
}