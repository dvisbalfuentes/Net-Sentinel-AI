#ifndef ITELEMETRYMONITOR_H
#define ITELEMETRYMONITOR_H
#include <string>

class ITelemetryMonitor{
    public:
    virtual ~ITelemetryMonitor() = default; 
    virtual void ingestData (std::string dataPacket) = 0;
    virtual double calculateRiskScore() = 0;
    virtual std::string getScannerName() = 0;
};

#endif