#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other){
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){
    if(this != &other)
        (void)other;
    return *this;
}


 double get_time_microseconds() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (tv.tv_sec * 1000000.0 + tv.tv_usec) / 100000.0;
    }

void PmergeMe::execute(int ac, char **av){
    final_flag = 0;
    digit_check(ac, av);
    // print_container(deq);

    /////////////////// deque sorting /////////////////////////////
    //main idea => keep the pending seprate (untouched)

    double start_time_deq = get_time_microseconds();
    //get_original_pairs before ford-johnson (larger element first in the pair)
    
    get_original_pairs(deq);

    //separate the pairs into two chaine (maine will be applied recursive for ford-johnson, pending will be left untouched)
    separate_pairs(pairs);
    // print_container(pending_chaine);

    //retain the orignal pending since pending will be changed later in the ford recursion
    original_pending = pending_chaine;
    original_main = main_chaine;

    // print_pair(pairs);

    pairs.clear();
    pending_chaine.clear();

    //apply recursive ford-johnson on the main chaine
    sorted_main_chaine = ford_johnson(original_main);


    // std::cout << "Sorted main chain after ford" << std::endl;
    // print_container(sorted_main_chaine);

    // std::cout << std::endl;
    // std::cout << "Original pending chaine remaining" << std::endl;
    // print_container(original_pending);

    // std::cout << "Pair count << " << _pair_count << std::endl;

    ///////////////jacobsthal implementation//////////////////////
    jacobsthal(sorted_main_chaine);

    double end_time_deq = get_time_microseconds();
    double duration_deq = end_time_deq - start_time_deq;
    // std::cout << "Time taken by jacobsthal for deq " << end_time - start_time << " us" << std::endl;

    /////////////////// vector sorting /////////////////////////////

    
    pairs.clear();
    sorted_pairs.clear();
    main_chaine.clear();
    pending_chaine.clear();
    original_pending.clear();
    original_main.clear();
    sorted_main_chaine.clear();

    double start_time_vec = get_time_microseconds();
    // //main idea => keep the pending seprate (untouched)
    // //get_original_pairs before ford-johnson (larger element first in the pair)
    get_original_pairs(vec);    

    // //separate the pairs into two chaine (maine will be applied recursive for ford-johnson, pending will be left untouched)
    separate_pairs(pairs);
    // print_container(pending_chaine);

    // //retain the orignal pending since pending will be changed later in the ford recursion
    original_pending = pending_chaine;
    original_main = main_chaine;

    // print_pair(pairs);

    // // clear globals before using
    pairs.clear();
    pending_chaine.clear();

    // //apply recursive ford-johnson on the main chaine
    sorted_main_chaine = ford_johnson(original_main);

    // // print_container(original_main);
    // // print_container(original_pending);
    // std::cout << "Sorted main chain after ford" << std::endl;
    // print_container(sorted_main_chaine);

    // std::cout << std::endl;
    // std::cout << "Original pending chaine remaining" << std::endl;
    // print_container(original_pending);

    // std::cout << "Pair count << " << _pair_count << std::endl;

    // ///////////////jacobsthal implementation//////////////////////
    jacobsthal(sorted_main_chaine);
    double end_time_vec = get_time_microseconds();
    double duration_vec = end_time_vec - start_time_vec;
    

    //////////////////////// final output time comparisons //////////////////////
    // std::cout << "finale " << std::endl;
    print_container(input_vec);
    final_flag = 1;
    print_container(sorted_main_chaine);
    time_comparision_output(duration_deq, duration_vec);
    
}

void PmergeMe::time_comparision_output(double duration_deq, double duration_vec){

    std::cout << std::fixed << std::setprecision(5);

    std::cout << "Time to process a range of "<< 
    input_vec.size() << " elements with std::deque : " <<
     duration_deq << " us" << std::endl;

    std::cout << "Time to process a range of "<< 
    input_vec.size() << " elements with std::vector : " <<
    duration_vec << " us" << std::endl;
}

//need to check for the duplicate number also
void PmergeMe::digit_check(int ac, char **av){
    // duplicate_check(ac, av); // check for number duplicates in the av
        for(int count = 1; count < ac; ++count){
            std::string str = av[count];
            int length = str.length() - 1;
            int i = 0;

            if(str[0] == '+')
                i++;
            while(i <= length)
                if(!isdigit(str[i++])) throw NotANumberException();
            if(strtod(str.c_str(), NULL) > INT_MAX) throw NotAnIntException();
            if(strtod(str.c_str(), NULL) < 0) throw PositiveNumberException();
            input_vec.push_back(strtod(str.c_str(), NULL));
            vec.push_back(strtod(str.c_str(), NULL));
            // vec = input_vec;
            deq.push_back(strtod(str.c_str(), NULL));
        }
}

int calculation(int n){
    int numerator = (std::pow(2, n))-(std::pow(-1, n));
    int temp = numerator / 3;
    return temp;
}

// Fixed generate_sequence method
std::vector<int> PmergeMe:: generate_sequence() {
    // std::cout << "Generating jacobsthal sequence for " << original_pending.size() << " pending elements" << std::endl;
    std::vector<int> jacobsthal_sequence_vec;
    
    if (original_pending.empty()) {
        return jacobsthal_sequence_vec;
    }
    
    // Generate jacobsthal numbers until we cover all pending elements
    for (int n = 1; n <= 30; ++n) {
        int current = calculation(n);
        
        if (current <= 0) continue; // Skip invalid values
        
        // Add all numbers from previous jacobsthal + 1 to current jacobsthal
        int start = jacobsthal_sequence_vec.empty() ? 1 : jacobsthal_sequence_vec.back() + 1;
        
        for (int j = start; j <= current && j <= (int)original_pending.size(); ++j) {
            jacobsthal_sequence_vec.push_back(j);
        }
        
        // If we've covered all pending elements, break
        if (current >= (int)original_pending.size()) {
            break;
        }
    }
    
    // std::cout << "Generated jacobsthal sequence: ";
    // print_container(jacobsthal_sequence_vec);
    
    return jacobsthal_sequence_vec;
}
// void PmergeMe::print_vec(){
//     std::cout << "Before: " << std::endl;
//     std::vector<int>::iterator it;
//     for(it = vec.begin(); it != vec.end(); it++){
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// void PmergeMe::print_deq(){
//     std::cout << "Before: " << std::endl;
//     std::deque<int>::iterator it;
//     for(it = deq.begin(); it != deq.end(); it++){
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// void PmergeMe::get_sorted_pairs(){
//     std::vector<std::pair<int, int> >::iterator it; 

//     //only one number in the container
//     //iterate the original pairs and put the matched pairs into sorted_pairs
//     for(it = pairs.begin(); it != pairs.end(); ++it){

//         //for the remaining element of deque(which is largest)
//         int pos_pair = get_pos_pair(deq);
//         if(pos_pair != -1){
//             sorted_pairs.push_back(pairs[pos_pair]);
//             pairs.erase(pairs.begin() + pos_pair);
//             deq.erase(deq.begin());
//         }

//         if (!pending_chaine.empty()) {
//             // Case 1: pending matches the second of the pair
//             int pos = get_pos_chaine(it->second);
//             if (pos != -1) {
//                 sorted_pairs.push_back(*it);
//                 pending_chaine.erase(pending_chaine.begin() + pos);
//             }

//             // Case 2: pending matches the first of the pair
//             else if (pending_chaine.back() == it->first) {
//                 sorted_pairs.push_back(*it);
//                 pending_chaine.pop_back();
//             }
//         }
//     }
//     pending_chaine.clear();
// }



// int PmergeMe::get_pos_chaine(int val){
//     for(size_t i = 0; i < pending_chaine.size(); ++i){
//         if(pending_chaine[i] == val) return i;
//     }
//     return -1;
// }