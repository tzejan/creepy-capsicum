#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

void BiggestPlot(const unsigned int S, const vector<unsigned short>& prices, size_t& startIndex, unsigned int& count);

void main() {
        // Part 5
    int simoleon = 12;
    const int pricesArray[] = {2,1,3,4,5};
    vector<unsigned short> prices(pricesArray, pricesArray + sizeof(pricesArray) / sizeof(pricesArray[0]));
    size_t startIndex = 0;
    unsigned int count = 0;

    BiggestPlot(simoleon, prices, startIndex, count);
    cout << "Part 5" << endl;
    cout << "Land prices = ";
    for (size_t i = 0; i < prices.size(); ++i)
    {
        cout << prices[i] << " ";
    }
    cout << endl;
    cout << simoleon << " simoleons can get you " << count << " plots of land starting from " << startIndex  << endl;
    cout << "Land bought = ";
    for (size_t i = startIndex; i < startIndex + count && i < prices.size(); ++i)
    {
        cout << prices[i] << " ";
    }
    cout << endl << endl;
}

void BiggestPlot(const unsigned int S, const vector<unsigned short>& prices, size_t& startIndex, unsigned int& count)
{
    int money = S;
    size_t anotherIndex = startIndex;
    size_t count2 = count;

    if ( S > 0 ) {
        for ( size_t a = 0; a < prices.size(); ++a) {
            for ( size_t b = 0; b < prices.size(); ++b) {
                if ( (money - prices[b]) < 0 ) {
                    break;
                }
                money -= prices[b];
                ++count;
            }
            if ( money == 0) {

                break;
            }

        }
    }
    // Refer to Part 5 of Assignment 02
    else {
        startIndex = 0;
        count = 0;
    }
}
