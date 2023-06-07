#include<vector>
#include<algorithm>
#include<iostream>

std::vector<int> v{1,2,3,4,5};

int findElement(){
    auto f1 = [](int n){return n % 3 == 0;};

    // auto itr = std::find_if(
    //     v.begin(),
    //     v.end(),
    //     f1
    // );
    //modern way 
    if(auto itr = std::find_if(     //if-initializers --remain in scope until if else block only;
        v.begin(),                  // if(initialization; condition)
        v.end(),
        f1
    );itr == v.end()){
        return -1;
    }else{
        return *itr;
    }
}


// char input ='A';
// while(input != '0'){
//         if(auto itr = std::find_if(
//         v.begin(),                  
//         v.end(),
//         f1
//     );itr == v.end()){
//         return -1;
//     }else{
//         return *itr;
//     }
//     std::cout<<"Press 0 to stop\n";
//     std::cin>>input;
// }