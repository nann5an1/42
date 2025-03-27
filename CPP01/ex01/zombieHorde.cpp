#include "Zombie.hpp"
Zombie* zombieHorde( int N, std::string name){
    Zombie *horde = new Zombie[N]; //N number of zombies object inside single allocation 
    for(int i=0; i<N; i++){
        horde[i].setname(name);
        horde[i].announce();
    }
    return (horde);
}