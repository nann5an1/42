

// ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (ScavTrap)

// int main(){
//     DiamondTrap c("Rex");
//     c.whoAmI();
//     c.attack("Ben");  
//     c.highFivesGuys();
//     c.takeDamage(10);
//     c.beRepaired(2);
//     c.guardGate();
// }


#include "DiamondTrap.hpp"

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"


#include <limits>
#include <cstdlib> // For system("clear")

void waitForUserInput()
{
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    system("clear");
    // Test ClapTrap
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ClapTrap ===" << RESET << std::endl;
        ClapTrap clapTrap("ClapTrap1");
        clapTrap.attack("target");
        clapTrap.takeDamage(5);
        clapTrap.beRepaired(2);
    } // clapTrap is destroyed here

    waitForUserInput();
    system("clear");
    // Test for max health points limit
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ClapTrap max health points limit ===" << RESET << std::endl;
        ClapTrap healthTest("HealthTest");
        std::cout << "Initial state, should have 10 hit points" << std::endl;

        // Try to repair for more than max health
        std::cout << GREEN << "Attempting to repair 5 points (should work fully):" << RESET << std::endl;
        healthTest.beRepaired(5);

        // Take some damage
        std::cout << GREEN << "Taking 15 points of damage (should not go below 0):" << RESET << std::endl;
        healthTest.takeDamage(15);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
    } // healthTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 hit points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ClapTrap 0 hit points behavior ===" << RESET << std::endl;
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
        healthTest.takeDamage(5);
        std::cout << "HealthTest current hit points: " << healthTest.getHitPoints() << std::endl;
    } // healthTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test ScavTrap
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ScavTrap ===" << RESET << std::endl;
        ScavTrap scavTrap("ScavTrap1");
        scavTrap.attack("target");
        scavTrap.takeDamage(5);
        scavTrap.beRepaired(2);
        scavTrap.guardGate();
    } // scavTrap is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 energy points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ScavTrap 0 energy points behavior ===" << RESET << std::endl;
        ScavTrap scavEnergyTest("ScavEnergyTest");
        for (int i = 0; i < 50; i++)
        {
            scavEnergyTest.attack("dummy");
        }
        std::cout << RED << "Attempting actions with 0 energy points:" << RESET << std::endl;
        scavEnergyTest.attack("dummy");
        scavEnergyTest.beRepaired(5);
    } // scavEnergyTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for max health points limit
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ScavTrap max health points limit ===" << RESET << std::endl;
        ScavTrap scavHealthTest("ScavHealthTest");
        std::cout << "Initial state, should have 100 hit points" << std::endl;

        // Take some damage first
        std::cout << GREEN << "Taking 50 points of damage:" << RESET << std::endl;
        scavHealthTest.takeDamage(50);
        std::cout << "ScavHealthTest current hit points: " << scavHealthTest.getHitPoints() << std::endl;

        // Try to repair
        std::cout << GREEN << "Attempting to repair 30 points:" << RESET << std::endl;
        scavHealthTest.beRepaired(30);
        std::cout << "ScavHealthTest current hit points: " << scavHealthTest.getHitPoints() << std::endl;

        // Take more damage
        std::cout << GREEN << "Taking 100 points of damage (should not go below 0):" << RESET << std::endl;
        scavHealthTest.takeDamage(100);
        std::cout << "ScavHealthTest current hit points: " << scavHealthTest.getHitPoints() << std::endl;
    } // scavHealthTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 hit points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing ScavTrap 0 hit points behavior ===" << RESET << std::endl;
        ScavTrap scavHealthTest("ScavHealthTest");
        
        // Take damage to reduce hit points to 0
        std::cout << GREEN << "Taking 100 points of damage to reduce hit points to 0:" << RESET << std::endl;
        scavHealthTest.takeDamage(100);
        std::cout << "ScavHealthTest current hit points: " << scavHealthTest.getHitPoints() << std::endl;
        
        // These should fail due to 0 hit points
        std::cout << RED << "Attempting actions with 0 hit points:" << RESET << std::endl;
        scavHealthTest.attack("dummy");
        scavHealthTest.beRepaired(5);
        scavHealthTest.guardGate();
        
        // Test taking additional damage when already at 0 hit points
        std::cout << GREEN << "Taking additional damage when already at 0 hit points:" << RESET << std::endl;
        scavHealthTest.takeDamage(50);
        std::cout << "ScavHealthTest current hit points: " << scavHealthTest.getHitPoints() << std::endl;
    } // scavHealthTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test FragTrap
    {
        std::cout << std::endl
                << YELLOW << "=== Testing FragTrap ===" << RESET << std::endl;
        FragTrap fragTrap("FragTrap1");
        fragTrap.attack("target");
        fragTrap.takeDamage(5);
        fragTrap.beRepaired(2);
        fragTrap.highFivesGuys();
    } // fragTrap is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 energy points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing FragTrap 0 energy points behavior ===" << RESET << std::endl;
        FragTrap fragEnergyTest("FragEnergyTest");
        for (int i = 0; i < 100; i++)
        {
            fragEnergyTest.attack("dummy");
        }
        std::cout << RED << "Attempting actions with 0 energy points:" << RESET << std::endl;
        fragEnergyTest.attack("dummy");
        fragEnergyTest.beRepaired(5);
    } // fragEnergyTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for max health points limit
    {
        std::cout << std::endl
                << YELLOW << "=== Testing FragTrap max health points limit ===" << RESET << std::endl;
        FragTrap fragHealthTest("FragHealthTest");
        std::cout << "Initial state, should have 100 hit points" << std::endl;

        // Take some damage first
        std::cout << GREEN << "Taking 50 points of damage:" << RESET << std::endl;
        fragHealthTest.takeDamage(50);
        std::cout << "FragHealthTest current hit points: " << fragHealthTest.getHitPoints() << std::endl;

        // Try to repair
        std::cout << GREEN << "Attempting to repair 30 points:" << RESET << std::endl;
        fragHealthTest.beRepaired(30);
        std::cout << "FragHealthTest current hit points: " << fragHealthTest.getHitPoints() << std::endl;

        // Take more damage
        std::cout << GREEN << "Taking 100 points of damage (should not go below 0):" << RESET << std::endl;
        fragHealthTest.takeDamage(100);
        std::cout << "FragHealthTest current hit points: " << fragHealthTest.getHitPoints() << std::endl;
    } // fragHealthTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 hit points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing FragTrap 0 hit points behavior ===" << RESET << std::endl;
        FragTrap fragHealthTest("FragHealthTest");
        
        // Take damage to reduce hit points to 0
        std::cout << GREEN << "Taking 100 points of damage to reduce hit points to 0:" << RESET << std::endl;
        fragHealthTest.takeDamage(100);
        std::cout << "FragHealthTest current hit points: " << fragHealthTest.getHitPoints() << std::endl;
        
        // These should fail due to 0 hit points
        std::cout << RED << "Attempting actions with 0 hit points:" << RESET << std::endl;
        fragHealthTest.attack("dummy");
        fragHealthTest.beRepaired(5);
        fragHealthTest.highFivesGuys();
        
        // Test taking additional damage when already at 0 hit points
        std::cout << GREEN << "Taking additional damage when already at 0 hit points:" << RESET << std::endl;
        fragHealthTest.takeDamage(50);
        std::cout << "FragHealthTest current hit points: " << fragHealthTest.getHitPoints() << std::endl;
    } // fragHealthTest is destroyed here


    waitForUserInput();
    system("clear");
    // Test DiamondTrap
    {
        std::cout << std::endl
                << YELLOW << "=== Testing DiamondTrap ===" << RESET << std::endl;
        DiamondTrap diamondTrap("DiamondTrap1");
        diamondTrap.attack("target");
        diamondTrap.takeDamage(5);
        diamondTrap.beRepaired(2);
        diamondTrap.guardGate();
    } // scavTrap is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 energy points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing DiamondTrap 0 energy points behavior ===" << RESET << std::endl;
        DiamondTrap diamondEnergyTest("DiamondEnergyTest");
        for (int i = 0; i < 50; i++)
        {
            diamondEnergyTest.attack("dummy");
        }
        std::cout << RED << "Attempting actions with 0 energy points:" << RESET << std::endl;
        diamondEnergyTest.attack("dummy");
        diamondEnergyTest.beRepaired(5);
    } // scavEnergyTest is destroyed here

    waitForUserInput();
    system("clear");
    // Test for max health points limit
    {
        std::cout << std::endl
                << YELLOW << "=== Testing DiamondTrap max health points limit ===" << RESET << std::endl;
        DiamondTrap diamondHealthTest("diamondHealthTest");
        std::cout << "Initial state, should have 100 hit points" << std::endl;

        // Take some damage first
        std::cout << GREEN << "Taking 50 points of damage:" << RESET << std::endl;
        diamondHealthTest.takeDamage(50);
        std::cout << "diamondHealthTest current hit points: " << diamondHealthTest.getHitPoints() << std::endl;

        // Try to repair
        std::cout << GREEN << "Attempting to repair 30 points:" << RESET << std::endl;
        diamondHealthTest.beRepaired(30);
        std::cout << "diamondHealthTest current hit points: " << diamondHealthTest.getHitPoints() << std::endl;

        // Take more damage
        std::cout << GREEN << "Taking 100 points of damage (should not go below 0):" << RESET << std::endl;
        diamondHealthTest.takeDamage(100);
        std::cout << "diamondHealthTest current hit points: " << diamondHealthTest.getHitPoints() << std::endl;
    } // DiamondTrap is destroyed here

    waitForUserInput();
    system("clear");
    // Test for 0 hit points behavior
    {
        std::cout << std::endl
                << YELLOW << "=== Testing DiamondTrap 0 hit points behavior ===" << RESET << std::endl;
        DiamondTrap diamondHealthTest("diamondHealthTest");
        
        // Take damage to reduce hit points to 0
        std::cout << GREEN << "Taking 100 points of damage to reduce hit points to 0:" << RESET << std::endl;
        diamondHealthTest.takeDamage(100);
        std::cout << "diamondHealthTest current hit points: " << diamondHealthTest.getHitPoints() << std::endl;
        
        // These should fail due to 0 hit points
        std::cout << RED << "Attempting actions with 0 hit points:" << RESET << std::endl;
        diamondHealthTest.attack("dummy");
        diamondHealthTest.beRepaired(5);
        diamondHealthTest.guardGate();
        
        // Test taking additional damage when already at 0 hit points
        std::cout << GREEN << "Taking additional damage when already at 0 hit points:" << RESET << std::endl;
        diamondHealthTest.takeDamage(50);
        std::cout << "ScavHealthTest current hit points: " << diamondHealthTest.getHitPoints() << std::endl;
    } // diamondHealthTest is destroyed here

    return 0;
}