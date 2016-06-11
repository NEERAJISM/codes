#include<iostream>
using namespace std;
struct Sailor {
   int sailorID;
   int onBoard;
   int vesselID;
};

struct BreezeShipping {
   int vesselID;
   int totalCrewMembers;
};

void assignSailorToVessel(Sailor &sail, BreezeShipping &ship, int vid) {
   if(sail.onBoard==1) {
      cout<<"Sailor is already on board"<<endl;
   }
   else {
      sail.onBoard = 1;
      sail.vesselID = vid;
      ship.totalCrewMembers++;
      cout<<"Sailor assiged to ship";
   }

   cout<<ship.totalCrewMembers;
}
void releaseSailorFromVessel(Sailor &sail, BreezeShipping &ship) {
   if(sail.onBoard==0) {
      cout<<"Sailor is already offshore"<<endl;
   }
   else {
      sail.onBoard = 0;
      sail.vesselID = 0;
      ship.totalCrewMembers--;
      cout<<"Sailor sent home. Enjoy your holidays";
   }
}

int main() {

   Sailor sail[100];
   BreezeShipping ship[5];
   int counter=0, sid, vid, sfoundat, vfoundat;

   //Enter ship details (i)
   for(counter=0;counter<5;counter++) {
      cin>>ship[counter].vesselID;
      cin>>ship[counter].totalCrewMembers;
   }

   //Enter sailor Details (ii)
   for(counter=0;counter<5;counter++){
      cin>>sail[counter].sailorID;
      cin>>sail[counter].onBoard;
      cin>>sail[counter].vesselID;
   }

   // Point (iii)
   cout<<"Enter sailor ID of Sailor to be assigned"<<endl;
   cin>>sid;
   cout<<"Enter vessel ID"<<endl;
   cin>>vid;

   for(counter=0;counter<5;counter++) {
      if(sid == sail[counter].sailorID) {
         sfoundat = counter;
         break;
      }
   }

   for(counter=0;counter<5;counter++) {
      if(vid == ship[counter].vesselID) {
         vfoundat = counter;
         break;
      }
   }
   assignSailorToVessel(sail[sfoundat], ship[vfoundat], vid);

   //Point (iv)
   cout<<"Enter sailor ID of Sailor to be released"<<endl;
   cin>>sid;
   for(counter=0;counter<5;counter++) {
      if(sid == sail[counter].sailorID) {
         sfoundat = counter;
         break;
      }
   }
   for(counter=0;counter<5;counter++) {
      if(sail[sfoundat].vesselID == ship[counter].vesselID) {
         vfoundat = counter;
         break;
      }
   }
   releaseSailorFromVessel(sail[sfoundat], ship[vfoundat]);

   return 0;
}
/*
1 0
2 0
3 0
4 0
5 0
11 0 0
12 1 0
13 0 0
14 0 0
15 0 0
*/
