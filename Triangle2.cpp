#include <iostream>
#include <cmath>
using namespace std;
 
bool triangleEx(double a, double b, double c);
double trianglePerimeter(double a, double b, double c);
double triangleAreaHrn(double a, double b, double c);
bool isrb(double a, double b, double c);
 
int main() {
    int key = 0;
    cout << "Введите то, что вам нужно:" << endl
         << "1 - проверка существования треугольника" << endl
         << "2 - периметр треугольника" << endl
         << "3 - площадь (формула Герона)" << endl
	 << "4 - проверка на равнобедренность(2 стороны равны друг другу)" << endl;
    cin >> key;
 
    double a = 0, b = 0, c = 0;
    cout << "Введите длины трёх сторон (a b c):" << endl;
    cin >> a >> b >> c;
 
    switch (key) {
    case 1: {
        bool exist = triangleEx(a, b, c);
        if (exist)
            cout << "Треугольник с такими сторонами существует." << endl;
        else
            cout << "Треугольник с такими сторонами НЕ существует." << endl;
        break;
    }
    case 2: {
        if (!triangleEx(a, b, c)) {
            cout << "Невозможно вычислить периметр — треугольника нет." << endl;
        } else {
            double p = trianglePerimeter(a, b, c);
            cout << "Периметр треугольника: " << p << endl;
        }
        break;
    }
    case 3: {
        if (!triangleEx(a, b, c)) {
            cout << "Невозможно вычислить площадь — треугольника нет." << endl;
        } else {
            double area = triangleAreaHrn(a, b, c);
            cout << "Площадь треугольника (по Герону): " << area << endl;
        }
        break;
    }
    case 4: {
        if (!triangleEx(a, b, c)) {
            cout << "Невозможно проверить равнобедренность — треугольника нет." << endl;
        } else {
            bool is = isrb(a, b, c);
            if (is)
                cout << "Треугольник является равнобедренным." << endl;
            else
                cout << "Треугольник НЕ равнобедренный." << endl;
        }
        break;
    }
    default: {
        cout << " Вы ввели что-то не то " << endl;
        break;
    }
    }
 
    cout << endl << "Дополнительный общий вывод:" << endl;
    if (triangleEx(a, b, c)) {
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Периметр: " << trianglePerimeter(a, b, c) << endl;
        cout << "Площадь (Герон): " << triangleAreaHrn(a, b, c) << endl;
        cout << "Равнобедренный: " << (isrb(a, b, c) ? "Да" : "Нет") << endl;
    } else {
        cout << "Треугольник с такими сторонами НЕ существует, остальные вычисления недоступны." << endl;
    }
 
    return 0;
}
 
bool triangleEx(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    return (a + b > c) && (a + c > b) && (b + c > a);
}
 
double trianglePerimeter(double a, double b, double c) {
    return a + b + c;
}
 
double triangleAreaHrn(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    double under = s * (s - a) * (s - b) * (s - c);
    if (under <= 0) return 0.0;
    return sqrt(under);
}
 
bool isrb(double a, double b, double c) {
    const double EPS = 1e-9;
    return (fabs(a - b) < EPS) || (fabs(b - c) < EPS) || (fabs(a - c) < EPS);
}
