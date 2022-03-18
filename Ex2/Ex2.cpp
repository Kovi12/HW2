#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Planet {
    int distance; // Distance between this planet and the one before it;
    int id; 
};

struct Cargo {
    int timeBegin;
    int timeEnd;
    Planet arrive;
    Planet destination;
    int distance = 0; //distance travelled by the cargo
};

struct Enterprise {
    vector<Cargo> C;
};
// function to verify if all the cargo on the ship can go to the next planet
bool canGo (vector<Cargo> C , int time , int PlanetCounter) {
    bool OK = 0;
    for (int i = 0; i < C.size(); i++)
    {
        if (C[i].arrive.id == PlanetCounter)
        {
            if (time < C[i].timeBegin)
            {
                OK = 0;
                break;
            } else 
            {
                OK = 1;
            }
            
        }
            
            
        
    }
    
    return OK;
}


//functions not finished , would have been used to  calculate the best use of after burner(between which planets) and how much would remain 

/*int UseOfFuel (vector<Cargo> C,vector<Planet> P, int PlanetCounter, int K) {
    int Max = -1;
    int CargoCount;
    int pos;
    for (int i = PlanetCounter; i < P.size() - 1; i++)
    {
        CargoCount = 0;
        for (int j = 0; j < C.size(); j++)
            if (C[j].arrive.id == P[i].id)
            {
                CargoCount++;
            }
            
        if (Max < max((P[i + 1].distance - K) * CargoCount , 0))
        {
            Max = max((P[i + 1].distance - K) * CargoCount , 0);
            pos = P[i].id;
        }
        
    }
    if (pos == PlanetCounter)
    {
        return Max;
    }
    
    return 0;

}


/*int TimeReduced (vector<Cargo> C,vector<Planet> P, int PlanetCounter, int K) {
    int Min = 200;
    int CargoCount;
    int pos;
    for (int i = PlanetCounter; i < P.size() - 1; i++)
    {
        CargoCount = 0;
        for (int j = 0; j < C.size(); j++)
            if (C[j].arrive.id == P[i].id)
            {
                CargoCount++;
            }
            
        if (Min > max((P[i + 1].distance - K) * CargoCount , 0))
        {
            Min = max((P[i + 1].distance - K) * CargoCount , 0);
            pos = P[i].id;
        }
        
    }
    
  
    if (canGo(C , time , PlanetCounter));
    {
        return Min;
    }
    
    return 0;

}*/
//function to calculate the total time spent by the cargo on the ship
int CalculateSum (vector<Cargo> Carg , int nrPlanets , vector<Planet> Plans ,int K) {
    int time = 0;
    int PlanetCounter = 0; // starting from the first planet
    Enterprise ship;
    vector<Cargo> aux = Carg;
    bool OK;
    int sum = 0;
    // iterate untul we are at the last planet
    while ( PlanetCounter != nrPlanets - 1)
    {
        for (int i = 0; i < Carg.size(); i++)
        {
            OK = 0;
            if (Carg[i].arrive.id == PlanetCounter ) // put cargo on ship 
            {
                ship.C.push_back(Carg[i]);
                Carg.erase(Carg.begin() + i);
                OK = 1;
            }
            
            
            if (OK)
                i--;
        }
        //unload cargo if they arrived at their destination and add their time spent to the total sum
        for (int j = 0; j < ship.C.size(); j++)
            {
                if (ship.C[j].destination.id == PlanetCounter)
                {
                    sum += ship.C[j].distance;
                    ship.C.erase(ship.C.begin() + j);
                    
                }
                
            }
        //if the ship can go then time + distance between planets , if not the the cargo is not all ready and time + 1
        if (canGo(aux , time , PlanetCounter))
        {
            
            time += Plans[PlanetCounter + 1].distance;// - TimeReduced(aux, Plans, PlanetCounter, K); //here i would have used the function to reduce the time
            for (int k = 0; k < ship.C.size(); k++)
                    {
                        ship.C[k].distance += Plans[PlanetCounter + 1].distance;// - TimeReduced(aux, Plans, PlanetCounter, K);
                    }
            PlanetCounter++;
        } else
        {
            time++;
            for (int k = 0; k < ship.C.size(); k++)
                    {
                        if (ship.C[k].timeBegin < time)
                        {
                            ship.C[k].distance++;
                        }
                        
                        
                    }
        }
        
    }
    //adding the time for the cargo that had the destination at the last planet
    for (int j = 0; j < ship.C.size(); j++)
            {
                if (ship.C[j].destination.id == PlanetCounter)
                {
                    sum += ship.C[j].distance;
                    ship.C.erase(ship.C.begin() + j);
                    j--;
                }
                
            }

    return sum;
}

int main () {
    ifstream in ("input.in.txt");
    ofstream out ("output.out.txt");
    
    int n,m, K;

    in >> n >> m >> K;
    vector<Planet> Planets;
    Planet Planet;
    Planet.distance = 0;
    Planet.id = 0;
    Planets.push_back(Planet);
    for (int i = 1; i < n; i++)
    {
        in >> Planet.distance;
        Planet.id = i;
        Planets.push_back(Planet); 
    }
    
    vector<Cargo> AllCargo;
    Cargo Cargo;
    for (int i = 0; i < m; i++)
    {
        in >> Cargo.timeBegin >> Cargo.arrive.id >> Cargo.destination.id;
        AllCargo.push_back(Cargo);
    }

    for (int i = 0; i < m; i++)
    {
        AllCargo[i].arrive.id--;
        AllCargo[i].destination.id--;
    }
    


    
    for (int i = 0; i < m; i++)
    {
        
        AllCargo[i].arrive.distance = Planets[AllCargo[i].arrive.id].distance;
        AllCargo[i].destination.distance = Planets[AllCargo[i].destination.id].distance;
    }

    out<<CalculateSum(AllCargo , n , Planets, K);


}