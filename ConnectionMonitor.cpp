#include "ConnectionMonitor.h"
#include <iostream> //We include iostream in case we want to print to the console later 
//*********************************************************************************************/
 std::string ConnectionMonitor::getScannerName()
 {
    return "Connection Monitor";
 }
//*********************************************************************************************/
void ConnectionMonitor::ingestData(std::string dataPacket) 
 {
    if(dataPacket.find("Failed Login") != std::string::npos)
    {
    failedConnections++;
    }
 }
//*********************************************************************************************/
 double ConnectionMonitor::calculateRiskScore()
 {
    if (failedConnections <= 5) 
    {
        return 10.0;
    }
    else if(failedConnections <= 10)
    {
        return 30.0;
    }
    else if(failedConnections <= 20)
    {
        return 60.0;
    }
    else
    {
    return 100.0;
    }
 }
//*********************************************************************************************/
