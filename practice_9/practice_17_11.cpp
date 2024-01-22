#define task_9_3

#ifdef task_9_1

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

int main() {
    const int N = 100000;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, N);

    auto start = std::chrono::system_clock::now();

    std::vector<int> vec;
    for (int i = 0; i < N; ++i) {
        vec.push_back(dis(gen));
    }

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = end - start;


    auto start2 = std::chrono::system_clock::now();

    std::vector<int> vec2;
    for (int i = 0; i < N; ++i) {
        vec2.insert(vec2.begin(), dis(gen));
    }

    auto end2 = std::chrono::system_clock::now();

    std::chrono::duration<double> diff2 = end2 - start2;



    std::uniform_int_distribution<> dis2(0, N-1);

    auto start3 = std::chrono::system_clock::now();

    std::vector<int> vec3(N);
    vec3.reserve(N);
    vec3.insert(vec3.begin() + dis2(gen), dis(gen));

    auto end3 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;

    std::cout << "----------------------------------------\n";
    std::cout << "Vector creation and insertion timings\n";
    std::cout << "----------------------------------------\n";

    std::cout << "Method: push_back\n";
    std::cout << "Time to fill a vector of " << N << " elements: " << diff.count() << " s\n";
    std::cout << "----------------------------------------\n";

    std::cout << "Method: insert at beginning\n";
    std::cout << "Time to fill a vector of " << N << " elements: " << diff2.count() << " s\n";
    std::cout << "----------------------------------------\n";

    std::cout << "Method: insert at random position\n";
    std::cout << "Time to insert an element at a random position in a vector of " << N << " elements: " << diff3.count() << " s\n";
    std::cout << "----------------------------------------\n";

    return 0;
}

#endif


#ifdef task_9_2

#include <iostream>
#include <chrono>
#include <random>
#include "SinglyLinkedList.h"

int main() {
    const int N = 100000;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, N);
    std::uniform_int_distribution<> dis2(0, N-1);

    auto start1 = std::chrono::system_clock::now();

    SinglyLinkedList<int> list1;
    for (int i = 0; i < N; ++i) {
        list1.push_back(dis(gen));
    }

    auto end1 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;

    std::cout << "----------------------------------------\n";
    std::cout << "SinglyLinkedList creation and insertion timings\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Method: push_back\n";
    std::cout << "Time to fill a SinglyLinkedList of " << N << " elements: " << diff1.count() << " s\n";
    std::cout << "----------------------------------------\n";

    auto start2 = std::chrono::system_clock::now();

    SinglyLinkedList<int> list2;
    for (int i = 0; i < N; ++i) {
        list2.insert(dis(gen));
    }

    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff2_1 = end2 - start2;

    std::cout << "Method: insert at beginning\n";
    std::cout << "Time to fill a SinglyLinkedList of " << N << " elements: " << diff2_1.count() << " s\n";
    std::cout << "----------------------------------------\n";

    auto start3 = std::chrono::system_clock::now();

    SinglyLinkedList<int> list3(N);
    list3.insert_at_random_position(dis(gen), dis2(gen));

    auto end3 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff4 = end3 - start3;

    std::cout << "Method: insert at random position\n";
    std::cout << "Time to insert an element at a random position in a SinglyLinkedList of " << N << " elements: " << diff4.count() << " s\n";
    std::cout << "----------------------------------------\n";
    return 0;
}

#endif


#ifdef task_9_3

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    double x = 0.0;

    double d = 0.0;
    std::cout << "Enter the pin spacing (d): ";
    std::cin >> d;

    int M = 0;
    std::cout << "Enter the height (M): ";
    std::cin >> M;

    double K = 0;
    std::cout << "Enter the number of cells (K): ";
    std::cin >> K;

    double w = 0.0;
    std::cout << "Enter the width of a cell (w): ";
    std::cin >> w;

    std::vector<int> cells(K, 0);

    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(0, 1);

    for (int j = 0; j < 10000; ++j) {
        x = 0.0;
        for (int i = 0; i < M; ++i) { 
            if (x == K * w / 2.0) {           
                x -= d;               
            } else if (x == -K * w / 2.0) {
                x += d;
            } else {
                x += (dis1(gen) * 2 - 1) * d; 
            }                                
        }

        int cellIndex = floor((x + K * w / 2.0) / w);
        if (cellIndex >= 0 && cellIndex < K) {
            cells[cellIndex]++;
        }
    }

    double mean = std::accumulate(cells.begin(), cells.end(), 0.0) / cells.size();
    
    double sq_sum = std::inner_product(cells.begin(), cells.end(), cells.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / cells.size() - mean * mean);
    
    std::normal_distribution<> dis(mean, stdev);

    std::vector<int> dis_values;
    for (int i = 0; i < cells.size(); ++i) {
        dis_values.push_back(std::round(dis(gen)));
    }

    double totalDeviation = 0.0;
    for (int i = 0; i < cells.size(); ++i) {
        double deviation = abs(cells[i] - dis_values[i]) / static_cast<double>(dis_values[i]) * 100;
        totalDeviation += deviation;
    }
    double averageDeviation = totalDeviation / cells.size();

    std::cout << "Average deviation: " << averageDeviation << "%" << std::endl;

    return 0;
}

#endif