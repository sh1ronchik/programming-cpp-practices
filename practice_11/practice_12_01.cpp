#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <deque>


#define B

#ifdef A

class Solution {
public:
   static std::vector<std::vector<std::string>> displayTable(std::vector<std::vector<std::string>> & orders) {
       std::unordered_map<std::string, std::unordered_map<int, int>> counter;
       std::set<std::string> foods;
       std::set<int> tables;

       for (auto& order : orders) {
           int table = std::stoi(order[1]);
           foods.insert(order[2]);
           tables.insert(table);
           counter[order[2]][table]++;
       }

       std::vector<std::vector<std::string>> result(tables.size() + 1);
       result[0] = {"Table"};
       for (auto& food : foods) {
           result[0].push_back(food);
       }

       int row = 1;
       for (auto& table : tables) {
           result[row] = {std::to_string(table)};
           for (auto& food : foods) {
               result[row].push_back(std::to_string(counter[food][table]));
           }
           row++;
       }

       return result;
   }
};

int main() {
    std::vector<std::vector<std::string>> input{
        {"David","3","Ceviche"}, {"Corina","10","Beef Burrito"},
        {"David","3","Fried Chicken"}, {"Carla","5","Water"},
        {"Carla","5","Ceviche"}, {"Rous","3","Ceviche"}
    };
    auto res = Solution::displayTable(input);
}

#endif

#ifdef B

class UndergroundSystem {
public:
   std::unordered_map<std::string, std::pair<long long, int>> stationTimes;
   std::unordered_map<int, std::pair<std::string,int>> inTransit;

   void checkIn(int id, std::string stationName, int t) {
       inTransit.try_emplace(id, stationName, t);
   }
   
   void checkOut(int id, std::string stationName, int t) {
       auto it = inTransit.find(id);
       if (it == inTransit.end()) return;

       std::string startStation = it->second.first;
       int startTime = it->second.second;
       std::string key = startStation + ":" + stationName;
       int time = t - startTime;

       stationTimes.try_emplace(key, 0, 0).first->second.first += time;
       stationTimes.try_emplace(key, 0, 0).first->second.second++;

       inTransit.erase(it);
   }
   
   double getAverageTime(std::string startStation, std::string endStation) {
       std::string key = startStation + ":" + endStation;
       auto& info = stationTimes[key];
       double avg = (double)info.first / (double)info.second;
       return avg;
   }
};

int main() {
    UndergroundSystem us;
    us.checkIn(45,"Leyton",3);
    us.checkIn(32,"Paradise",8);
    us.checkIn(27,"Leyton",10);
    us.checkOut(45,"Waterloo",15);
    us.checkOut(27,"Waterloo",20);
    us.checkOut(32,"Cambridge",22);
    std::cout << us.getAverageTime("Paradise","Cambridge") << "\n";
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
    us.checkIn(10,"Leyton",24);
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
    us.checkOut(10,"Waterloo",38);
    std::cout << us.getAverageTime("Leyton","Waterloo") << "\n";
}

#endif

#ifdef C

class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution {
public:
    static int getImportance(const std::vector<Employee*> &employees, int id) {
        std::unordered_map<int, Employee*> employee_index;
        for (auto emp : employees) {
            employee_index[emp->id] = emp;
        }
        int out = 0;
        std::deque<int> ids{id};
        while (not ids.empty()) {
            int cur = ids.front();
            ids.pop_front();

            out += employee_index[cur]->importance;

            for (auto e : employee_index[cur]->subordinates) {
                ids.push_back(e);
            }
        }
        return out;
    }
};

int main() {
    std::vector<Employee *> employees{
        new Employee{1, 5, {2, 3}}, 
        new Employee{2, 3, {}}, 
        new Employee{3, 3, {}}
    };
    
    std::cout << Solution::getImportance(employees, 1);
    
    std::cout << std::endl;
    return 0;
}

#endif