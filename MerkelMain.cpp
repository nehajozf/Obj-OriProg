//
//  MerkelMain.cpp
//  OOP
//
//  Created by Neha Joseph on 26/12/22.
//


#include "MerkelMain.hpp"
#include <iostream>
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
#include "CSVReader.hpp"


MerkelMain::MerkelMain()
{
    
}

void MerkelMain::init()
{
    std::string input;
    
    
    currentTime = orderBook.getEarliestTime();
    
    //new code
    //getNextTime = orderBook.getPrevTime();
    //till here
    
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}


void MerkelMain::printMenu(){
    
    std::cout<<"Welcome to advisorbot. I will help you with the following commands" << std::endl;
    
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
    
    std::cout<<"10:exit" <<std::endl;
    
    std::cout <<"==========" << std::endl;
}


// the help function
void MerkelMain::printHelp()
{
    std::cout <<"The available commands are help, help <cmd>,prod,min, max, avg, predict, time, step" <<std::endl;
    
}

//the help command function
void MerkelMain::printHelpcmd()
{
    std::cout << "Choose command you need help with" <<std::endl;
    std::string input;
    
    std::getline(std::cin, input);
    std::cout << "You typed:help "<< input << std::endl;
    
    if(input == "help" )
    {
        std::cout <<"The available commands are help, help <cmd>,prod,min, max, avg, predict, time, step" <<std::endl;
    }
    if(input == "help<cmd>")
    {
        std::cout << "output help for the specified command" <<std::endl;
    }


    
    if(input == "prod")
    {
      //  std::cout << "list available products" <<std::endl;
        printProd();
    }
    
    if(input == "min")
    {
       // std::cout << "find minimum bid or ask for product in current time step" <<std::endl;
        printMin();
    }
    
    if(input == "max")
    {
       // std::cout << "find maximum bid or ask for product in current time step" <<std::endl;
        printMax();
    }
    
    if(input == "avg")
    {
       // std::cout << "compute average ask or bid for the sent product over the sent number of time steps." <<std::endl;
        printAvg();
    }
    
    if(input == "predict")
    {
       // std::cout << "predict max or min ask or bid for the sent product for the next time step" <<std::endl;
        printPredict();
    }
    
    if(input == "time")
    {
       // std::cout << "state current time in dataset, i.e. which timeframe are we looking at" <<std::endl;
        printTime();
    }
    
    if(input == "step")
    {
       // std::cout << "move to next time step" <<std::endl;
        printStep();
    }
    
}

// the product command
void MerkelMain::printProd()
{
    std::cout << "list available products" <<std::endl;
    
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        //std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
         //                                                       p, currentTime);
        //std::cout << "Asks seen: " << entries.size() << std::endl;
       // std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        //std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;



    }
}

//the minimum asks or bid function
void MerkelMain::printMin()
{
    std::cout << "find minimum bid or ask for product in current time step" <<std::endl;
    
//    for(std::string const& p : orderBook.getKnownProducts())
//    {
//        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
//                                                                  p,currentTime );
//        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
//    }
    
    std::string line;
    std::getline(std::cin, line);
    
    for(std::string const& p : orderBook.getKnownProducts())
    {
        if(line== "ask")
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                      p,currentTime );
            std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
        }
        
        if(line== "bid")
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid,
                                                                      p,currentTime );
            std::cout << "Min bid: " << OrderBook::getLowPrice(entries) << std::endl;
        }
    }
}

//the maximum asks or bid function
void MerkelMain::printMax()
{
    std::cout << "find maximum bid or ask for product in current time step" <<std::endl;
    
//    for(std::string const& p : orderBook.getKnownProducts())
//    {
//        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
//                                                                  p,currentTime );
//        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
//    }
    
    std::string line;
    std::getline(std::cin, line);
    
    for(std::string const& p : orderBook.getKnownProducts())
    {
        if(line== "ask")
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                      p,currentTime );
            std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        }
        
        if(line== "bid")
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid,
                                                                      p,currentTime );
            std::cout << "Max bid: " << OrderBook::getHighPrice(entries) << std::endl;
        }
    }
}

// the average function to compute average ask or bid for the sent product over the sent number of time steps
void MerkelMain::printAvg()
{
    std::cout << "compute average ask or bid for the sent product over the sent number of time steps." <<std::endl;
    
//    for(std::string const& p : orderBook.getKnownProducts())
//    {
//        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
//                                                                  p,currentTime );
//        //std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
//        //std::cout << "Avg"
//    }
    
    
    std::string line;
    std::getline(std::cin, line);
    
    if(line == "ask")
    {
        std::cout <<"within the timesteps" << std::endl;
        int num;
        std::cin>>num;
        double sum =0, avg;
        int count = 0;
        
        // to get price of previous timestep
        for(std::string const& p : orderBook.getKnownProducts())
        {
            for(int i = 1; i<= num ;i++)
            {
                
                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                          p,currentTime );
                double price = OrderBook::getHighPrice(entries);
                
                //if current time is already on earliest time , then we have to break loop
                if(currentTime =="")
                {
                    price = 0;
                    break;
                }
                std::cout << "product price is : " << price<< std::endl;
                sum += price;
                count += 1;
                currentTime = orderBook.getPrevTime(currentTime);
            }
            //resetting to original timestep
            for(int i = 1; i<=count; i++)
            {
                currentTime = orderBook.getNextTime(currentTime);
            }
            std::cout << "The sum of all products is : " << sum << std::endl;
            avg = sum / count;
            
            std::cout << "The average " << line << "price over the last " << num<< "step was " << avg << std::endl;
        }
    }
    
    if( line == "bid")
    {
        std::cout <<"within the timesteps" << std::endl;
        int num;
        std::cin>>num;
        double sum =0, avg;
        int count = 0;
        
        for(std::string const& p : orderBook.getKnownProducts())
        {
            for(int i = 1; i<= num ;i++)
            {
                
                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid,
                                                                          p,currentTime );
                double price = OrderBook::getHighPrice(entries);
                
                if(currentTime =="")
                {
                    price = 0;
                    break;
                }
                std::cout << "product price is : " << price<< std::endl;
                sum += price;
                count += 1;
                currentTime = orderBook.getPrevTime(currentTime);
            }
            
            for(int i = 1; i<=count; i++)
            {
                currentTime = orderBook.getNextTime(currentTime);
            }
            std::cout << "The sum of all products is : " << sum << std::endl;
            avg = sum / count;
            
            std::cout << "The average " << line << " price over the last " << num<< "step was " << avg << std::endl;
        }
        
    }
}

// the predict function to predict max or min ask or bid for the sent product for the next time step
void MerkelMain::printPredict()
{
    std::cout << "predict max or min ask or bid for the sent product for the next time step" <<std::endl;
    

    currentTime = orderBook.getNextTime(currentTime);
    std::cout << " min or max ? " << std::endl;
    std::string k;
    std::getline(std::cin, k);
    
    if(k == "min")
    {
        std::cout<<"Select the product you want. eg: BTC/USDT" << std::endl;
        std::string line;
        
        std::getline(std::cin, line);
        std::cout <<"You typed: " << line << std::endl;
        
        for(std::string const& p : orderBook.getKnownProducts())
        {
            if(line == p)
            {
                std::cout << "Select : ask or bid "<< std::endl;
                std::string line;
                
                std::getline(std::cin, line);
                std::cout<< "You typed: "<<line<<std::endl;
                if(line == "bid")
                {
                    std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid,
                                                                              p,currentTime );
                    std::cout << "The prediction for next time bid" << line << "is" << std::endl;
                }
                
                if(line == "ask")
                {
                    std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                              p,currentTime );
                    std::cout << "The prediction for next time ask" << line << "is" << std::endl;
                }
            }
        }
    }
    
    currentTime = orderBook.getPrevTime(currentTime);

    
    
    
    
    
    
    
    
}



// the time function to state current time in dataset
void MerkelMain::printTime()
{
    std::cout << "state current time in dataset, i.e. which timeframe are we looking at" <<std::endl;
    std::cout <<"Current time is: " << currentTime <<std::endl;
}

// the step function to move to next time step
void MerkelMain::printStep()
{
    std::cout << "move to next time step" <<std::endl;
    currentTime = orderBook.getNextTime(currentTime);
    std::cout<< "Next time is: " << currentTime<<std::endl;
}



//new code

void MerkelMain::removeTerminalOutputs()
{
    std::cout <<" Exit from command" << std::endl;
    system("cls");
    
}

//till here





std::string MerkelMain::getUserOption()
{
   std::string cmd;
    std::string line;
    std::cin >> cmd;
    //std::cout << "You chose: " << cmd << std::endl;
    std::getline(std::cin, line);
    try{
        cmd = std::stoi(line);
    }catch(const std::exception& e)
    {
        //
    }
    std::cout << "You chose: " << cmd << std::endl;
    
    return cmd;
}

void MerkelMain::processUserOption(std::string cmd)
{
    if(cmd == "help" )
    {
        printHelp();
    }
    
    if(cmd == "help<cmd>")
    {
        printHelpcmd();
//        std::string input;
//        std::getline(std::cin, input);
//        std::cout << "You typed: " << input << std::endl;
    }
    
    if(cmd == "prod")
    {
        printProd();
    }
    
    if(cmd == "min")
    {
        printMin();
    }
    
    if(cmd == "max")
    {
        printMax();
    }
    
    if(cmd == "avg")
    {
        printAvg();
    }
    
    if(cmd == "predict")
    {
        printPredict();
    }
    
    if(cmd == "time")
    {
        printTime();
       // std::cout <<"Current time is: " << currentTime <<std::endl;
    }
    
    if(cmd == "step")
    {
        printStep();
    }
    
    //new code
    
    if(cmd == "exit")
    {
        removeTerminalOutputs();
    }
    
    //till here
    
}

