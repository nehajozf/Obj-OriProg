//
//  OrderBook.hpp
//  OOP
//
//  Created by Neha Joseph on 26/12/22.
//

#ifndef OrderBook_hpp
#define OrderBook_hpp

#include <stdio.h>

#pragma once
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include <string>
#include <vector>

class OrderBook
{
   public:
    /** construct, reading a csv data file*/
    OrderBook(std::string filename);
    /** return vector  of all known products in the dataset*/
    std::vector<std::string> getKnownProducts();
    /**return vector of Orders according to the sent filters*/
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);
    
    /** Returns the earliest time in the orderBook*/
    std::string getEarliestTime();
    
    /** Returns the next time after the sent time in the orderBook
         If there is no next timestamp, wraps around to the start*/
    std::string getNextTime(std::string timestamp);
    
    
    //new code
    std::string getPrevTime(std::string timestamp);
    std::string getPrevTime();
//till here
    
    
    void insertOrder(OrderBookEntry& order);
    
    
    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
    
    
    
    
   static double getHighPrice(std::vector<OrderBookEntry>& orders);
    static double getLowPrice(std::vector<OrderBookEntry>& orders);
    
   private:
    std::vector<OrderBookEntry> orders;
    
    
    
};

#endif /* OrderBook_hpp */

