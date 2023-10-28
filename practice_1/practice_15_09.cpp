
#define T1_5


#ifdef T1_1

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Enter a natural number: ";
    int num = 0, fact = 1;
    std::cin >> num;

    for(int counter = 1; counter <= num; counter++) {
        fact = fact * counter;
    }
    
    std::cout << "Factorial of this number: " << fact << "\n";

    return 0;
}

#endif





#ifdef T1_2

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::cout << "General form of the quadratic equation: a*x^(2) + b*x + c = 0.\n";

    int coef_a = 0, coef_b = 0, coef_c = 0;
    std::cout << "Enter coefficient a: ";
    std::cin >> coef_a;
    std::cout << "Enter coefficient b: ";
    std::cin >> coef_b;
    std::cout << "Enter coefficient c: ";
    std::cin >> coef_c;

    int discriminant = coef_b * coef_b - 4 * coef_a * coef_c;

    if (discriminant < 0) {
        std::cout << "The quadratic equation has no real roots." << "\n";
    }
    else if (discriminant == 0) {
        float x = ((float)(-1) * coef_b) / (2 * coef_a);
        std::cout << "The quadratic equation has a single root: " << x << "\n";
    }
    else {
        float x1 = ((float)(-1) * coef_b + sqrt(discriminant)) / (2 * coef_a), 
              x2 = ((float)(-1) * coef_b - sqrt(discriminant)) / (2 * coef_a);
        std::cout << "The quadratic equation has two roots.\n";
        std::cout << "First root: " << x1 << "\n";
        std::cout << "Second root: " << x2 << "\n";
    }

    return 0;
}

#endif





#ifdef T1_3

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::cout << "Simple numbers in the range of 2 to 99: ";

    for (int number = 2; number < 100; number++) {
        bool flag = true;
        for (int div = 2; div <= sqrt(number); div++) {
            if (number % div == 0 and number != div) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << number << " ";
        }
    }

    return 0;
}

#endif





#ifdef T1_4

#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    std::cout << "Binary representation: ";
    
    if (num == 0) {
        std::cout << 0;
    } else {
        int num_of_dig = 0, binary_rep[32] = {0};
        while (num > 0) {
            binary_rep[num_of_dig] = num % 2;
            num = num / 2;
            num_of_dig++;
        }
        for (int ind = num_of_dig - 1; ind >= 0; ind--) {
            std::cout << binary_rep[ind];
        }
    }

    return 0;
}


#endif





#ifdef T1_5

#include <iostream>
#include <cmath>

int main() {
    double a, q, e;
    std::cout << "Enter the first element of the geometric progression: ";
    std::cin >> a;
    std::cout << "Enter the denominator (less than 1): ";
    std::cin >> q;
    std::cout << "Enter the precision: ";
    std::cin >> e;

    double sum_formula = a / (1 - q);
    std::cout << "Sum using formula: " << sum_formula << "\n";

    double sum_loop = 0, summand = a;
    while (!(sum_loop >= sum_formula - e && sum_loop <= sum_formula + e)) {
        sum_loop += summand;
        summand *= q;
    }

    std::cout << "Sum using loop: " << sum_loop;

    return 0;
}



#endif





#ifdef T1_6

#include <iostream>

int main() {
    std::cout << "Enter a character: ";
    char character;
    std::cin >> character;

    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
        std::cout << "It is a letter of the alphabet.\n";
    } else {
        std::cout << "It is not a letter of the alphabet.\n";
    }

    return 0;
}


#endif