#define A

#include <iostream>
#include <vector>
#include <deque> 

#ifdef A
void rotate(std::vector<int> &v, int d) {
    int n = v.size();
    std::vector<int> temp = v;
    for (int i = 0; i < n; ++i) {
        v[i] = temp[(i + d) % n];
    }
}

void print_v(const std::vector<int> &v) {
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    print_v(v);
    rotate(v, 4);
    print_v(v);
}
#endif


#ifdef B

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int x, a, b;
    std::cin >> x >> a >> b;
    v.erase(v.begin() + x - 1);
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    std::cout << v.size() << "\n";
    for (auto e : v) {
        std::cout << e << " ";
    }
}

#endif


#ifdef C

void printKMax(int arr[], int n, int k){
	std::deque<int> mydeque;
    for (int i = 0; i < n; ++i) mydeque.push_back(arr[i]);
    int a = 0;
    if (n == 1) {
        std::cout << mydeque.front();
    }
    for (int i = 0; i < n - 1; ++i) {
        a = mydeque.front();
        mydeque.pop_back();
        std::cout << std::max(a, mydeque.front()) << " ";
    }
}

int main(){
	int t;
	std::cin >> t;
	while(t>0) {
		int n,k;
    	std::cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		std::cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

#endif
