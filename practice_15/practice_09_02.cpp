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


void drawChessBoard(const std::vector<std::vector<Piece*>>& board) {
    std::cout << "  A  B  C  D  E  F  G  H" << std::endl;

    for (int row =  0; row <  8; ++row) {
        std::cout << (char)('8' - row);

        for (int col =  0; col <  8; ++col) {
            if (board[row][col] != nullptr) {
                board[row][col]->display();
            } else {
                bool isBlackCell = (row + col) %  2 ==  1;
                if (isBlackCell) {
                    std::cout << " # ";
                } else {
                    std::cout << " . ";
                }
            }
        }

        std::cout << std::endl;
    }
}


int main() {
    std::vector<std::vector<Piece*>> board(8, std::vector<Piece*>(8, nullptr));

    for (int col =  0; col <  8; ++col) {
        board[1][col] = new Pawn(Color::Black, 1, col);
        board[6][col] = new Pawn(Color::White, 6, col);
    }

    board[0][0] = new Rook(Color::Black, 0, 0);
    board[0][7] = new Rook(Color::Black, 0, 7);

    board[0][1] = new Knight(Color::Black, 0, 1);
    board[0][6] = new Knight(Color::Black, 0, 6);

    board[0][2] = new Bishop(Color::Black, 0, 2);
    board[0][5] = new Bishop(Color::Black, 0, 5);

    board[0][3] = new Queen(Color::Black, 0, 3);
    board[0][4] = new King(Color::Black, 0, 4);

    board[7][0] = new Rook(Color::White, 7, 0);
    board[7][7] = new Rook(Color::White, 7, 7);

    board[7][1] = new Knight(Color::White, 7, 1);
    board[7][6] = new Knight(Color::White, 7, 6);

    board[7][2] = new Bishop(Color::White, 7, 2);
    board[7][5] = new Bishop(Color::White, 7, 5);

    board[7][3] = new Queen(Color::White, 7, 3);
    board[7][4] = new King(Color::White, 7, 4);

    drawChessBoard(board);

    for (auto &row : board) {
        for (auto &piece : row) {
            delete piece;
        }
    }

    return  0;
}

#endif