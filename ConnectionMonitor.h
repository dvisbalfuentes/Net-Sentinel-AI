#ifndef CONNECTIONMONITOR_H
#define CONNECTIONMONITOR_H
#include "ITelemetryMonitor.h"
#include <string>

class ConnectionMonitor : public ITelemetryMonitor{
    private:
    int failedConnections = 0;
    public:
    ConnectionMonitor() = default; 
    void ingestData (std::string dataPacket) override; 
    double calculateRiskScore() override;
    std::string getScannerName() override;
};

#endif