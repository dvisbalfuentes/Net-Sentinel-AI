import random
#*********************************************************************************************/
with open("traffic_log.txt", "w") as file:
    for i in range(1000):
        ip_end = random.randint(1, 255) 
        ip_address = "192.168.1." + str(ip_end) 
        attack_types = ["Failed Login", "Failed Login", "Malware Detected", "Safe Traffic", "Safe Traffic"] # weighed by probability
        current_attack = random.choice(attack_types)
        file.write(ip_address + " - " + current_attack + "\n")
print("1,000 Network Logs Succesfully Generated!")
#*********************************************************************************************/