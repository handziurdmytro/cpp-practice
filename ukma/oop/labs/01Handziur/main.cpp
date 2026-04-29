// Developed by Handziur Dmytro on 14.02.2026
#include <iostream>
#include "Triangle.h"
#include "Point.h"

using namespace std;
/*  Гандзюр Дмитро, ІПЗ-2, Лабораторна робота №1

    Я досяг ефективної реалізації за допомогою:

    1. Архітектури класу Triangle:

    - володіє трьома точками Point (композиція)
    - вкладений клас Triangle::Segment, який посилається 
    на точки Point через const-відсилки (агрегація посиланням)
    та має розумний вказівник на точку, який слугує центром сегменту
    (асоціація з лінивою ініціалізацією)
    - розумні вказівники(unique_ptr) на сторони та медіани
    (агрегація вказівниками)

    2. Лінива ініціалізація. 

    Я її реалізував за допомогою розумних вказівників
    (unique_ptr) та допоміжних методів для створення 
    1) сторін трикутника 2) медіан 3) основ медіан.

    Об'єкти створюються тільки при пешому виклику метода.
    За допомогою методу update() дані перераховуються, забезпечуючи
    консистентність даних.


    Висновок:
 
    В main я відслідкував життєвий цикл створених об'єктів 
    за допомогою підрахунку створення та видалення, таким чином
    пересвідчившись у справності роботи конструкторів,
    деструкторів та копіювальних конструкторів, відсутності витоків
    пам'яті та ефективному виконанню за допомогою лінивої ініціалізації.

*/
void stats() noexcept;

int main()
{
    cout << "\n---------------\n";
    cout << "** Start **\n\n";
    stats();

    {
        cout << "\n---------------\n";
        cout << "** Points creation **\n\n";

        Point a1(0, 0);
        Point b1(10, 0);
        Point c1(5, 5);

        Point a2(-20, 0);
        Point b2(20, 0);
        Point c2(0, -30);

        {
            Point a3;
            Point b3;
            Point c3;
        }// -3 alive

        stats();

        cout << "\n---------------\n";
        cout << "** Triangles creation **\n\n";

        Triangle t1(a1, b1, c1);
        Triangle t2(a2, b2, c2);
        
        stats();

        cout << "\n* NOTE: for each triangle 3 points were copied(created): 6 + 3 + 3 = 12\n";
        cout << "* NOTE: no segments have been created, because of lazy initialization\n";

        cout << "\n---------------\n";
        cout << "** Triangles data **" << endl;

        cout << "\nTriangle #1: " << t1 << endl;
        cout << "AB: " << t1.side_AB() << ", len: " << t1.length_AB() << endl;
        cout << "BC: " << t1.side_BC() << ", len: " << t1.length_BC() << endl;
        cout << "CA: " << t1.side_CA() << ", len: " << t1.length_CA() << endl;
        cout << "Median from A to BC: " << t1.median_from_A_to_BC() << ", len: " << t1.median_from_A_to_BC_len() << endl;
        cout << "Median from B to CA: " << t1.median_from_B_to_CA() << ", len: " << t1.median_from_B_to_CA_len() << endl;
        cout << "Median from C to AB: " << t1.median_from_C_to_AB() << ", len: " << t1.median_from_C_to_AB_len() << endl;

        cout << "\n---------------\n";
        cout << "** Stats after first call of methods **\n\n";
        stats();
        cout << "\n* NOTE: created 3 POINTS as middle points: 12 + 3 = 15\n";
        cout << "* NOTE: created 6 SEGMENTS: 3(triangle sides) + 3(medians) = 6\n";

        t1.set_b(Point(20, 0)); // +1 point alive, -1 point alive

        cout << "\n---------------\n";
        cout << "** Triangles data after B point change **" << endl;

        cout << "\nTriangle #1: " << t1 << endl;
        cout << "AB: " << t1.side_AB() << ", len: " << t1.length_AB() << endl;
        cout << "BC: " << t1.side_BC() << ", len: " << t1.length_BC() << endl;
        cout << "CA: " << t1.side_CA() << ", len: " << t1.length_CA() << endl;
        cout << "Median from A to BC: " << t1.median_from_A_to_BC() << ", len: " << t1.median_from_A_to_BC_len() << endl;
        cout << "Median from B to CA: " << t1.median_from_B_to_CA() << ", len: " << t1.median_from_B_to_CA_len() << endl;
        cout << "Median from C to AB: " << t1.median_from_C_to_AB() << ", len: " << t1.median_from_C_to_AB_len() << endl;

        cout << "\n---------------\n";
        cout << "** Stats after second call of methods **\n\n";
        stats();
        cout << "\n* NOTE: created 3 PTS: 15 + 3(new) - 3(old) + 1(setter) - 1(old point) = 18 (all time: 22)\n";
        cout << "* NOTE: created 6 SEGMENTS because of point change: 6 + 6(new) - 6(old) = 6 (all time: 12)\n";
    }
    cout << "\n---------------\n";
    cout << "** Stats after leaving visibility scope (Destructors worked) **\n\n";
    stats();
}

void stats() noexcept
{
    cout << "=Points= alive count: " << Point::get_actual_counter() << endl;
    cout << "All time =points= count: " << Point::get_all_time_counter() << endl;

    cout << "=Segments= alive count: " << Triangle::Segment::get_actual_counter() << endl;
    cout << "All time =segments= count: " << Triangle::Segment::get_all_time_counter() << endl;

    cout << "=Triangles= alive count: " << Triangle::get_actual_counter() << endl;
    cout << "All time =triangles= count: " << Triangle::get_all_time_counter() << endl;
}