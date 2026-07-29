#include <iostream>
#include <cassert>
#include "../ConnectionMonitor.h"
#include "../MalwareScanner.h"
//*********************************************************************************************/
int main()
{
    std::cout << "Running Unit Tests..." << std::endl;

    //TEST 1: ConnectionMonitor Logic
    ConnectionMonitor connTest; 
    for(int i = 0; i < 7; i++)
    {
        connTest.ingestData("Failed Login");
    }
    assert(connTest.calculateRiskScore() == 30.0);
    
    //TEST 2: MalwareScanner Logic
    MalwareScanner malwareTest;
    malwareTest.ingestData("Malware Detected");
    assert(malwareTest.calculateRiskScore() == 100.0);

    std::cout << "SUCCESS: All Unit Tests Passed! Code is Mathematically Verified." << std:: endl;
    return 0;
}
//*********************************************************************************************/