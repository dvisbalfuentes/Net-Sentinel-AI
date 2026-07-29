# Net-Sentinel AI
**A polymorphic C++ network threat detection engine validated against custom Python-scripted automated attack simulations.**

## Abstract:
Net-Sentinel AI is an enterprise-grade telemetry ingestion engine. Built in C++ to maximize throughput, it utilizes strict Object-Oriented principles (Interfaces, Polymorphism, and Dynamic Dispatch) to route simulated network traffic through tiered anomaly detection scanners. A complementary Python script generates the randomized telemetry data, simulating both brute-force credential stuffing and malware payload injections.

## Key Features:
* **Polymorphic Architecture:** Employs a core `ITelemetryMonitor` interface, allowing dynamic memory allocation of unique child scanners (`ConnectionMonitor`, `MalwareScanner`) without Object Slicing.
* **Data Normalization:** Translates distinct network events (rapid failed logins vs. rare malware signatures) into a universal 0-100 Risk Score algorithm.
* **Tiered Alert System:** Implements dynamic Control Flow to translate raw risk scores into actionable security conditions (Green, Purple, Orange, Red).
* **Automated Python Telemetry:** Includes a custom `traffic_generator.py` script that utilizes probability weighting to generate 1,000+ lines of localized IPv4 test data.
* **Unit Tested:** Includes a dedicated `tests/` environment utilizing `cassert` to mathematically verify the integrity of the Threat Scoring algorithms.

## Tech Stack:
* **C++11:** Core engine, Object-Oriented design, File I/O stream parsing.
* **Python 3:** Data generation and probability simulation.

## Architecture:
```text
Net-Sentinel-AI/
│
├── .gitignore                # Git exclusion rules
├── README.md                 # Project documentation
├── traffic_generator.py      # Python script to generate mock telemetry
├── traffic_log.txt           # Generated dataset (1,000+ localized logs)
│
├── src/                      # Core C++ Engine Source Code
│   ├── main.cpp              # Engine entry point and File I/O loop
│   ├── ITelemetryMonitor.h   # Abstract Interface (The Parent)
│   ├── ConnectionMonitor.h   # Implementation Header 
│   ├── ConnectionMonitor.cpp # Logic for failed login tracking
│   ├── MalwareScanner.h      # Implementation Header
│   └── MalwareScanner.cpp    # Logic for critical payload tracking
│
└── tests/                    # Unit Testing Environment
    └── test_scanners.cpp     # cassert verification of scoring logic