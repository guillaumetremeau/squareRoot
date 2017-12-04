#include <iostream>

using namespace std;

const float ACCURACY = 0.0001;

//Can also be code as a recursive function
float squareRootOf(float area){
    //The basic idea is that we have a rectangle with the area, we progressively transform the rectangle into a square, then the sides of this square will give us the square root of the area
    float length = 1;
    float width = area;
    if(area <= 0){
        throw "Need a positive number";
    }

    while(width - length > ACCURACY || width - length < -(ACCURACY)){//Until it's a square, depending on the desired accuracy of the estimation
        length = (length + width) /2;//We take the average between length and width
        width = area / length;//We make it keeping the same area
        cout << length << ":" <<width<< endl;
    }
    return length;
}

int main()
{
    float x;
    float result;
    cout << "Give me a number" << endl;
    cin >> x;

    try {
        result = squareRootOf(x);
        cout << "Square root of " << x << " is (+/-)" << result << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
