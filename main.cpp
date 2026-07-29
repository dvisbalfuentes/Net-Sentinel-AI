#include <iostream>
#include <fstream>
#include "ConnectionMonitor.h"
#include "MalwareScanner.h"
//*********************************************************************************************/
int main()
{
    ITelemetryMonitor* scanners[2];
    scanners[0] = new ConnectionMonitor;
    scanners[1] = new MalwareScanner;

    std::ifstream logFile("traffic_log.txt");
    if(!logFile.is_open())
    {
        std::cout << "ERROR: Could not open traffic_log.txt. Did you run the Python script?" << std::endl;
        return 1; 
    }
    std::cout << "Ingesting Netowrk Traffic..." << std::endl;
    std::string currentLine; 
    while(std::getline(logFile, currentLine))
    {
        for(int i = 0; i < 2; i++)
        {
            scanners[i]->ingestData(currentLine);
        }
    }
    logFile.close();
    std::cout << "Traffic Analysis Completed.\n" << std::endl;

for(int i = 0; i < 2; i++)
    {
        double score = scanners[i]->calculateRiskScore();
        std::string name = scanners[i]->getScannerName();
        if(score <= 10)
        {
            std::cout << name << " // Threat Level: GREEN - System Secure\n";
        }
        else if(score <= 30)
        {
            std::cout << name << " // Threat Level: PURPLE - Low Level Activity Detected\n";
        }
        else if(score <=60)
        {
            std::cout << name << " // Threat Level: ORANGE - for Scanner " << i+1 << "! - Action Required\n";
        }
        else
        {
            std::cout << name << " // **CRITICAL ALERT** // Threat Level: RED - System Under Heavy Attack!\n";
        }
    }

    for(int i = 0; i < 2; i++)
    {
        delete scanners[i];
    }

    return 0;
}
//*********************************************************************************************/