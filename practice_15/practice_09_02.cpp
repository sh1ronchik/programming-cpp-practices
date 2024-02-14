#define task_15_2


#ifdef task_15_1


#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm> 
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

int main() {
    std::vector<std::pair<int, Shape*>> shapes;
    int shapeCount;
    std::cout << "Enter the number of shapes: ";
    std::cin >> shapeCount;

    for (int i =   0; i < shapeCount; ++i) {
        int shapeType;
        std::cout << "Enter shape type (1 - Rectangle, 2 - Circle, 3 - Triangle): ";
        std::cin >> shapeType;

        switch (shapeType) {
            case 1: {
                double width, height;
                std::cout << "Enter rectangle width and height(w h): ";
                std::cin >> width >> height;
                shapes.emplace_back(i, new Rectangle(width, height));
                break;
            }
            case 2: {
                double radius;
                std::cout << "Enter circle radius(r): ";
                std::cin >> radius;
                shapes.emplace_back(i, new Circle(radius));
                break;
            }
            case 3: {
                double x1, y1, x2, y2, x3, y3;
                std::cout << "Enter triangle vertices coordinates (x1 y1 x2 y2 x3 y3): ";
                std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                double side1 = std::sqrt(std::pow(x2 - x1,   2) + std::pow(y2 - y1,   2));
                double side2 = std::sqrt(std::pow(x3 - x2,   2) + std::pow(y3 - y2,   2));
                double side3 = std::sqrt(std::pow(x1 - x3,   2) + std::pow(y1 - y3,   2));
                shapes.emplace_back(i, new Triangle(side1, side2, side3));
                break;
            }
            default:
                std::cout << "Invalid shape type!" << std::endl;
                return 1;
        }
    }

    std::sort(shapes.begin(), shapes.end(), [](const auto& a, const auto& b) {
        return a.second->calculatePerimeter() > b.second->calculatePerimeter();
    });

    std::cout << "Shapes sorted by decreasing perimeter:" << std::endl;
    for (const auto& shapePair : shapes) {
        std::cout << "Shape " << shapePair.first << ": ";
        shapePair.second->displayInfo();
        std::cout << "Perimeter = " << shapePair.second->calculatePerimeter() << std::endl;
    }

    for (auto& shapePair : shapes) {
        delete shapePair.second;
    }

    return 0;
}


#endif


#ifdef task_15_2


#include <iostream>
#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Board.h"

int main() {
    Board chessBoard;
    chessBoard.display();
}

#endif