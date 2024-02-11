
#include <iostream>

using namespace std;

int main()
{
    // Symbolic constant
    const unsigned short MIN_DISTANCE = 15,
                         MAX_DISTANCE = 100,
                         LEAP_CHANCE = 3, 
                         LEAP_MAX = 4,
                         LEAP_MIN = 2;
    
    // Variable declarations
    short distance; // we didn't use unsigned because if user enter negative value it will be huge value
    unsigned short tortoise, hare;
    unsigned short hareLeaps, leapDistance;
    unsigned int counter, runNumber;
    unsigned short hareWins, tortoiseWins;
    
    
    // Seed the random generator
    srand(time(NULL));
    
    // Input the length of the course
    do
    {
        cout << "Enter the distance of the course (" << MIN_DISTANCE
             << " - " << MAX_DISTANCE << ")" << endl;
        cin >> distance;
    }while( !( distance <= MAX_DISTANCE && distance >= MIN_DISTANCE ) );
    
    
    
    // Initialize accumulator variables
    tortoiseWins = 0;
    hareWins = 0;
    for ( runNumber = 1; runNumber <= 100 ; runNumber ++ )
    {
        // Initialize accumulator variables 
        tortoise = 0;
        hare = 0;
        
        
        do
        {
            // Tortoise moves ahead by one unit
            tortoise ++;
            
            // Print the distance covered by the tortoise
            for (counter = 1 ; counter <= tortoise ; counter ++ )
            {
                cout << "T";
            }
            cout << endl;
            
            
            
            // Hare randomly decides whether to sleep or leap
            hareLeaps= rand() % LEAP_CHANCE + 1;
            
            
            // If hare leaps, leap by a random distance
            if ( 1== hareLeaps )
            {
                // Randomly decide the length of leap 
                leapDistance = rand() % LEAP_MAX + LEAP_MIN;
                hare += leapDistance;
                
                
                
            }
            
            // Print the distance covered by the tortoise
            for (counter = 1 ; counter <= hare ; counter ++ )
            {
                cout << "H";
            }
            cout << endl;
            
            
        }while( !(tortoise >= distance || hare >= distance) );
        
        if ( tortoise > hare )
        {
            tortoiseWins ++;
        }
        else
        {
            if(hare > tortoise)
            {
                hareWins ++;
            }
        }
    }    
    
    cout << "Out of " << ( runNumber - 1 ) << " runs, "
         << " tortoise won " << tortoiseWins << " times "
         << " and hare won " << hareWins << " times " << endl;
    return 0;
}



 

