//
//  main.cpp
//  OOP
//
//  Created by Neha Joseph on 21/12/22.
//

#include <iostream>
#include "MerkelMain.hpp"

using namespace std;

int main(int arg, const char * argv[]) {
    
    
    MerkelMain app{};
    
    app.init();
    
    //double price = 0.02482611;
    //double amount = 24;
    //std::string timestamp{"2020/06/01 11:57:30.328127"};
    //std::string product{"ETH/BTC"};
    //std::string orderType{"anything"};
    
    //enum class OrderBookType{bid,ask};
    
   // OrderBookType orderType = OrderBookType::ask;
    
    
   /*
    while(true)
    {
        // 1 print help
        std::cout <<"1:help" << std::endl;
        
        
        // help <cmd>
        std::cout <<"2:help <cmd>" << std::endl;
        
        
        
        // prod
        std::cout <<"3:prod" << std::endl;
        
        
        
        //min
        std::cout <<"4:min" << std::endl;
        
        
        // max
        std::cout <<"5:max" << std::endl;
        
        
        // avg
        std::cout <<"6:avg" << std::endl;
        
        // predict
        std::cout <<"7:predict" << std::endl;
        
        
        // time
        std::cout <<"8:time" << std::endl;
        
        
        // step
        std::cout <<"9:step" << std::endl;
        
        std::cout <<"==========" << std::endl;
        
        //char cmd[20];
        string cmd;
        std::cin >> cmd;
        std::cout << "You chose: " << cmd << std::endl;
        
        if(cmd == "help" )
        {
            std::cout <<"The available commands are help, help <cmd>,prod,min, max, avg, predict, time, step" <<std::endl;
        }
        
        if(cmd == "help<cmd>")
        {
            std::cout << "output help for the specified command" <<std::endl;
        }
        
        if(cmd == "prod")
        {
            std::cout << "list available products" <<std::endl;
        }
        
        if(cmd == "min")
        {
            std::cout << "find minimum bid or ask for product in current time step" <<std::endl;
        }
        
        if(cmd == "max")
        {
            std::cout << "find maximum bid or ask for product in current time step" <<std::endl;
        }
        
        if(cmd == "avg")
        {
            std::cout << "compute average ask or bid for the sent product over the sent number of time steps." <<std::endl;
        }
        
        if(cmd == "predict")
        {
            std::cout << "predict max or min ask or bid for the sent product for the next time step" <<std::endl;
        }
        
        if(cmd == "time")
        {
            std::cout << "state current time in dataset, i.e. which timeframe are we looking at" <<std::endl;
        }
        
        if(cmd == "step")
        {
            std::cout << "move to next time step" <<std::endl;
        }
        
        
        
    }
 */
    
    return 0;
}
