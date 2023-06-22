//
//  MerkelMain.hpp
//  OOP
//
//  Created by Neha Joseph on 26/12/22.
//

#ifndef MerkelMain_hpp
#define MerkelMain_hpp

#include <stdio.h>

#pragma once
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"

class MerkelMain
{
   public:
    MerkelMain();
    void init();
    
   private:
    void printMenu();
    void printHelp();
    void printHelpcmd();
    void printProd();
    void printMin();
    void printMax();
    void printAvg();
    void printPredict();
    void printTime();
    void printStep();
    
    //new code
    void removeTerminalOutputs();
    
    //till here
    
    std::string getUserOption();
    void processUserOption(std::string cmd);
    
    
    
    std::string currentTime;
    
    //new code
    //std::string getNextTime;
    //till here
    
    //OrderBook orderBook{"/Users/nehajoseph/Downloads/Obj Ori sample copy/Currency Trading Exchange Simulation/abc.csv"};
    
    OrderBook orderBook{"/Users/nehajoseph/Downloads/Midterm OOP Draft/OOP/20200601.csv"};
    
    
    
};

#endif /* MerkelMain_hpp */
