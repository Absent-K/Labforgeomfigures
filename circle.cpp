#include <iostream>
using namespace std;
const float PI = 3.141592653589793;

float circumferenceLength(float radius);
float circleArea(float radius);
float areaCircularSector(float radius, int corner);

int main()
{
    int key = 0;
    cout << "Введите то, что вам нужно:" << endl <<
        "1 - длина окружности" << endl <<
        "2 - площадь круга" << endl <<
        "3 - площадь кругового сектора" << endl;
    cin >> key;
    switch (key)
    {
    case 1: 
        {
            float radius = 0;
            cout << "Введите радиус круга" << endl;
            cin >> radius;
            float leight = circumferenceLength(radius);
            cout << "Ваша длина окружности:" << leight;
            break;
        }
    case 2:
        {
            float radius = 0;
            cout << "Введите радиус круга" << endl;
            cin >> radius;
            float area = circleArea(radius);
            cout << "Ваша площадь круга:" << area;
            break; 
        }
    case 3:
        {
            float radius = 0;
            cout << "Введите радиус круга" << endl;
            cin >> radius;
            int corner = 0;
            cout << "Введите  угол" << endl;
            cin >> corner;
            float area = areaCircularSector(radius, corner);
            cout << "Ваша площадь круга:" << area;
            break; 
        }    
    
    default:
        {
            cout << "Упс, вы ввели что-то не то";
            break; 
        }
    }
}

float circumferenceLength(float radius)
{
    return 2*radius*PI;
}

float circleArea(float radius)
{
    return PI * radius * radius;
}

float areaCircularSector(float radius, int corner)
{
    return PI * radius * radius * corner / 360;
}