// don't try this in C#
// by2 is where the array by array idea starts to get real
// suppose you'd like to track months worth of stuff for a few years
#include <iostream>

int x;
int y;

struct xtimeframe
{
    int xtime;
    char xframe;
};

struct yevents
{
    int id;                   // here we have a identifier for the 5 items
    xtimeframe xy_array[5];   // here were declaring an array of arrays - just wait
};

yevents yevents_array[5];     // now we have an array 5 id/arrays

int main()
{
    std::cout << "greetings from by2" << std::endl;

    x = 0;
    y = 0;
//  as is the routine we start from the inside and move out
// starting with the first entry
    for (x = 0; x < 5; x++)                          // the unavoidable 5 assignments (10  actually)
    {
        yevents_array[0].xy_array[x].xtime = 0;
        yevents_array[0].xy_array[x].xframe = '0';
    }

    yevents_array[0].id = 0; //initialize

    for (y = 1; y < 5; y++) //initialize all the entries to the first
    {
        yevents_array[y] = yevents_array[0];   // don't be tempted to flip these two lines around - the result will mortify you
        yevents_array[y].id = y;               // resist the urge to perform the assignments in the order of the struct
    }

//  so we have initialized a 5 x 5 (25)) element array with 9 assignments (5 + 4)
// btw looking back to Cby2 this xevent[1] = xevent[2] is not allowed - this is an error: invalid array assignment

    std::cout << "Before " << std::endl;

    for (x = 0; x < 5; x++)
    {
        std::cout << " id " << yevents_array[x].id ;
        for (y = 0; y < 5; y++)
        {
            std::cout << " t " << yevents_array[x].xy_array[y].xtime << " f " << yevents_array[x].xy_array[y].xframe;
        }
        std::cout << std::endl;
    }

    // lets prove that this really works

    yevents_array[0].id = 1;

    yevents_array[0].xy_array[0].xtime = 1;

    yevents_array[0].xy_array[0].xframe = '1';

    std::cout << "After " << std::endl;

    for (x = 0; x < 5; x++)
    {
        std::cout << " id " << yevents_array[x].id ;
        for (y = 0; y < 5; y++)
        {
            std::cout << " t " << yevents_array[x].xy_array[y].xtime << " f " << yevents_array[x].xy_array[y].xframe;
        }
        std::cout << std::endl;
    }

    std::cin >> x;

    return 0;
}
// the results are nice
