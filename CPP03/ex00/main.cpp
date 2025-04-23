// #include "ClapTrap.h"

// int main(){
//     ClapTrap a("Luke");
//     a.attack("Ben");
//     a.takeDamage(3);
//     a.beRepaired(3);
// }

#include "ClapTrap.hpp"
#include <limits>
#include <cstdlib> // For system("clear")

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

void waitForUserInput()
{
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    system("clear");
    {
        std::cout << std::endl
                << YELLOW << "=== Testing base case ===" << RESET << std::endl;
        ClapTrap clapTrap("ClapTrap1"); 
        clapTrap.attack("target");
        clapTrap.takeDamage(5);
        clapTrap.beRepaired(2);
    }

    waitForUserInput();
    system("clear");
    // more tests
    // Test for 0 energy points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing 0 energy points behavior ===" << RESET << std::endl;
        ClapTrap energyTest("EnergyTest");
        // Perform 10 attacks to drain all energy points
        for (int i = 0; i < 10; i++)
        {
            energyTest.attack("dummy");
        }
        // These should fail due to no energy points
        std::cout << RED << "Attempting actions with 0 energy points:" << RESET << std::endl;
        energyTest.attack("dummy");
        energyTest.beRepaired(5);
    }

    waitForUserInput();
    system("clear");
    // Test for max health points limit
    {
        std::cout << std::endl
                << YELLOW << "=== Testing max health points limit ===" << RESET << std::endl;
        ClapTrap healthTest("HealthTest");
        std::cout << "Initial state, should have 10 hit points" << std::endl;
        
        // Take some damage first
        std::cout << GREEN << "Taking 5 points of damage:" << RESET << std::endl;
        healthTest.takeDamage(5);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
        
        // Try to repair
        std::cout << GREEN << "Attempting to repair 3 points:" << RESET << std::endl;
        healthTest.beRepaired(3);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;

        // Try to overheal
        std::cout << GREEN << "Attempting to repair 5 points (should be limited to prevent overheal):" << RESET << std::endl;
        healthTest.beRepaired(5);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
    }

    waitForUserInput();
    system("clear");
    // Test for 0 hit points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing 0 hit points behavior ===" << RESET << std::endl;
        ClapTrap healthTest("HealthTest");
        
        // Take damage to reduce hit points to 0
        std::cout << GREEN << "Taking 10 points of damage to reduce hit points to 0:" << RESET << std::endl;
        healthTest.takeDamage(10);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
        
        // These should fail due to 0 hit points
        std::cout << RED << "Attempting actions with 0 hit points:" << RESET << std::endl;
        healthTest.attack("dummy");
        healthTest.beRepaired(5);
        
        // Test taking additional damage when already at 0 hit points
        std::cout << GREEN << "Taking additional damage when already at 0 hit points:" << RESET << std::endl;
        healthTest.takeDamage(15);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
    }
}