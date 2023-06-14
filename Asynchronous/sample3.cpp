#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <vector>
#include<algorithm>
std::mutex mt;


int main()
{
    std::vector<int> vector;
    auto f = [&vector](int number)
    {std::lock_guard lg(mt);
        int ans=0;
        vector.push_back(number *number);
        number++; 
    };

    std::thread arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = std::thread(f,i+1);
    }
    for (int i = 0; i < 100; i++)
    {
        arr[i].join();
    }
    // for (auto &it : vector)
    // {
    //     std::cout << it << " ";
    // }
    std::for_each(vector.begin(),vector.end(),[](int n){
        std::cout<<n<<" ";
    });
}