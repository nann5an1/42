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


int PmergeMe::duplicate_check(std::vector<int> &input_vec){
    std::vector<int> temp_vec = input_vec;
    std::sort(temp_vec.begin(), temp_vec.end());

    for(size_t i = 1; i < temp_vec.size(); i++)
        if(temp_vec[i] == temp_vec[i-1]) return 1;
    return 0;
}

//need to check for the duplicate number also
void PmergeMe::digit_check(int ac, char **av){
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
            
            if(duplicate_check(input_vec)) throw DuplicateNumberException();

            vec.push_back(strtod(str.c_str(), NULL));
            deq.push_back(strtod(str.c_str(), NULL));
        }
}

 double get_time_microseconds() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (tv.tv_sec * 1000000.0 + tv.tv_usec) / 100000.0;
    }

void PmergeMe::execute(int ac, char **av){
    // final_flag = 0;
    digit_check(ac, av);
    // print_container(deq);

    /////////////////// deque sorting /////////////////////////////
    
    //main idea => keep the pending seprate (untouched)

    // double start_time_deq = get_time_microseconds();
    sort_container(deq);
    // double end_time_deq = get_time_microseconds();
    // double duration_deq = end_time_deq - start_time_deq;

    /////////////////// vector sorting /////////////////////////////


    // double start_time_vec = get_time_microseconds();
    // sort_container(vec);
    // double end_time_vec = get_time_microseconds();
    // double duration_vec = end_time_vec - start_time_vec;
    

    //////////////////////// final output time comparisons //////////////////////
    // print_container(input_vec);
    // final_flag = 1;
    // print_container(sorted_main_chaine);
    // time_comparision_output(duration_deq, duration_vec);
    
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
    return jacobsthal_sequence_vec;
}
