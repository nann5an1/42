#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <limits.h>
#include <utility>
#include <cmath>
#include <sys/time.h>

class PmergeMe{
    private:
        int _pair_count, final_flag; //final_flag indication just for output purposes
        std::vector<std::pair<int, int> > pairs, sorted_pairs;
        std::vector<int> vec, input_vec,
        main_chaine, pending_chaine, original_pending, 
        original_main, sorted_main_chaine;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void digit_check(int ac, char **av);
        void execute(int ac, char **av);
        std::vector<int> generate_sequence();
        void time_comparision_output(double duration_deq, double duration_vec);
        int duplicate_check(std::vector<int> &input_vec);

    //print_container_template
    template <typename T>
    void print_container(T& container){
        final_flag ? std::cout << "After: " : std::cout << "Before: ";
        
        // if(container.size() > 5){
        //     for(size_t it = 0; it != container.size() - (container.size() - 5); it++)
        //         std::cout << container[it] << " ";
        // }
        // else{
            for(size_t it = 0; it != container.size(); it++)
                std::cout << container[it] << " ";
        // }
        // std::cout << "[...]" << std::endl;
    }

    template <typename T>
    void print_pair(T& container) {
        typename T::iterator it;
        std::cout << "Print pair: ";
        for (it = container.begin(); it != container.end(); ++it) {
            std::cout << "[" << it->first << ", " << it->second << "]";
            if (it + 1 != container.end()) {   // works only for random-access (vector)
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }


    // recursive Ford–Johnson working on pairs
    // template <typename T>
    // std::vector<std::pair<int,int> > ford_johnson_pairs(std::vector<std::pair<int,int> > &pairs) {
    //     if (pairs.size() <= 1)
    //         return pairs;

    //     // extract main (large elements only)
    //     T local_main;
    //     for (size_t i = 0; i < pairs.size(); ++i)
    //         local_main.push_back(pairs[i].first);

    //     // recurse on the main (large values)
    //     T sorted_main = ford_johnson(local_main);

    //     // now rebuild the pair list in the sorted order
    //     std::vector<std::pair<int,int> > reordered_pairs;
    //     for (size_t i = 0; i < sorted_main.size(); ++i) {
    //         int large = sorted_main[i];
    //         // find the matching pair (large, small)
    //         for (size_t j = 0; j < pairs.size(); ++j) {
    //             if (pairs[j].first == large) {
    //                 reordered_pairs.push_back(pairs[j]);
    //                 break;
    //             }
    //         }
    //     }
    //     return reordered_pairs;
    // }

// Recursive Ford–Johnson wrapper for normal containers
// template <typename T>
// T ford_johnson(T& container) {
//     if (container.size() <= 1)
//         return container;

//     // Step 1. Make pairs
//     std::vector<std::pair<int,int> > local_pairs;
//     ford_original_pairs(container, local_pairs);

//     // Step 2. Recurse with pairs carried along
//     std::vector<std::pair<int,int> > sorted_pairs = ford_johnson_pairs<T>(local_pairs);

//     // Step 3. Extract main/pending in the *new* order
//     T main_chain;
//     T pending_chain;
//     ford_separate_pairs(sorted_pairs, main_chain, pending_chain);

//     // Step 4. Insert pending into sorted main (Jacobsthal later)
//     for (typename T::iterator it = pending_chain.begin(); it != pending_chain.end(); ++it) {
//         typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), *it);
//         main_chain.insert(pos, *it);
//     }
//     return main_chain;
// }

////////mine////////////
    // //ford johnson applilcation on the main chain (recursive)
    template <typename T>
    T ford_johnson(T& container) {
        if (container.size() <= 1)
            return container;

        //make pairs
        std::vector<std::pair<typename T::value_type, typename T::value_type> > local_pairs;
        ford_original_pairs(container, local_pairs);

        // split into main/pending
        T local_main;
        T local_pending;
        ford_separate_pairs(local_pairs, local_main, local_pending);

        std::cout << "<< Local Main chain >>" << std::endl;
        print_container(local_main);
        std::cout << std::endl;

        std::cout << "<< Local Pending chain >>" << std::endl;
        print_container(local_pending);
        std::cout << std::endl;

        // recurse on main chaine(no need on the pending)
        T sorted_main = ford_johnson(local_main);

        // insert pending into final sorted_main
        for (typename T::iterator it = local_pending.begin(); it != local_pending.end(); ++it) {
            typename T::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), *it);
            sorted_main.insert(pos, *it);
        }
        return sorted_main;
    }

    template <typename T>
    void separate_pairs(T& container){
        typename T::iterator it;

        for(it = container.begin(); it != container.end(); ++it){
            if(it->second != -1)
                main_chaine.push_back(it->first);
            if(it->second == -1)
                pending_chaine.push_back(it->first);
            else
                pending_chaine.push_back(it->second);
        }
    }

    //getting original pairs before ford-johnson [15, 2], [12, 3], [4, 5]
    template <typename T>
    void get_original_pairs(T& container){
        typename T::iterator it;
        T main_chaine;
        _pair_count = 0;
        
        std::vector<std::pair<int, int> >::iterator it_paired;

        //make into pairs, larger element first
        for(it = container.begin(); it != container.end(); ++it){
            if((it + 1) != container.end()){
                if(*it < *(it + 1))
                    std::swap(*it, *(it + 1));

                pairs.push_back(std::make_pair(*it, *(it + 1)));
                ++it;
            }
            else{
                pairs.push_back(std::make_pair(*it, -1));
                break;
            }
            _pair_count++;
        }
    }

    // make pairs from container → output into `paired`
    template <typename T>
    void ford_original_pairs(const T& container, std::vector<std::pair<int,int> >& paired) {
        typename T::const_iterator it;

        for (it = container.begin(); it != container.end(); ++it) {
            if ((it + 1) != container.end()) {
                int a = *it;
                int b = *(it + 1);
                if (a < b)
                    std::swap(a, b);

                paired.push_back(std::make_pair(a, b));
                ++it;
            } else {
                paired.push_back(std::make_pair(*it, -1));
                break;
            }
        }
    }

    // split pairs into main/pending
    template <typename T>
    void ford_separate_pairs(
        const std::vector<std::pair<int,int> >& paired,
        T& main_chain,
        T& pending_chain
    ) {
        typename std::vector<std::pair<int,int> >::const_iterator it;
        for (it = paired.begin(); it != paired.end(); ++it) {
            if(it->second != -1)
                main_chain.push_back(it->first);
            if(it->second == -1)
                pending_chain.push_back(it->first);
            else
                pending_chain.push_back(it->second);
        }
    }

    template <typename T>
    void jacobsthal(T& sorted_main) {
    if (original_pending.empty()) return; // base case

    // std::cout << "Starting jacobsthal round with " << original_pending.size() << " pending elements" << std::endl;
    // print_container(original_pending);
    
    std::vector<int> jacobsthal_sequence = generate_sequence();
    
    // Collect indices to insert this round (in reverse order for optimal insertion)
    std::vector<int> indices_to_insert;
    
    // Process jacobsthal sequence in reverse order
    for (int i = jacobsthal_sequence.size() - 1; i >= 0; --i) {
        int idx = jacobsthal_sequence[i];
        
        // Check bounds - jacobsthal indices are 1-based
        if (idx >= 1 && idx <= (int)original_pending.size()) 
            indices_to_insert.push_back(idx - 1); // Convert to 0-based index
    }
    
    // Sort indices in descending order to avoid index shifting issues when erasing
    std::sort(indices_to_insert.rbegin(), indices_to_insert.rend());
    
    // Insert each element and remove from original_pending
    for (size_t k = 0; k < indices_to_insert.size(); ++k) {
        int idx = indices_to_insert[k];
        if (idx >= 0 && idx < (int)original_pending.size()) {
            int value_to_insert = original_pending[idx];
            
            // Binary search and insert
            binary_insertion_sort(sorted_main, value_to_insert);
            
            // Remove the inserted element from original_pending
            original_pending.erase(original_pending.begin() + idx);
        }
    }
    
    // Recurse with remaining elements
    jacobsthal(sorted_main);
}

    template <typename T>
    void binary_insertion_sort(T& container, int value_to_insert) {
        // std::cout << "Inserting " << value_to_insert << " into sorted chain" << std::endl;
        
        // Binary search to find insertion point
        typename T::iterator pos = std::lower_bound(container.begin(), container.end(), value_to_insert);
        
        // Insert at the found position
        container.insert(pos, value_to_insert);
        
        // std::cout << "Updated chain after inserting " << value_to_insert << ":" << std::endl;
        // print_container(container);
    }
    // Inside your PmergeMe class

// template <typename T>
// void sort_container(T& container){
//     //clear every vector before another container application
//     pairs.clear();
//     sorted_pairs.clear();
//     main_chaine.clear();
//     pending_chaine.clear();
//     original_pending.clear();
//     original_main.clear();
//     sorted_main_chaine.clear();

//     // Step 1: Build the original pairs
//     get_original_pairs(container);

//     // Step 2: Split into main/pending
//     separate_pairs(pairs);

//     // Step 3: Retain originals
//     original_pending = pending_chaine;
//     original_main = main_chaine;

//     // Step 4: Apply recursive Ford-Johnson merge-sort on the main chain
//     sorted_main_chaine = ford_johnson(original_main);

//     // Step 5: Reorder pending elements to follow partner’s new position
//     std::vector<int> reordered_pending;
//     for (size_t i = 0; i < sorted_main_chaine.size(); ++i) {
//         int main_val = sorted_main_chaine[i];

//         // locate pair partner
//         for (size_t j = 0; j < pairs.size(); ++j) {
//             if (pairs[j].first == main_val && pairs[j].second != -1) {
//                 reordered_pending.push_back(pairs[j].second);
//                 break;
//             }
//         }
//     }

//     // Step 6: Add leftover unmatched (-1) if any
//     for (size_t j = 0; j < pairs.size(); ++j) {
//         if (pairs[j].second == -1) {
//             reordered_pending.push_back(pairs[j].first);
//         }
//     }

//     original_pending = reordered_pending;
//     std::cout << "Reorderd pending >>" << std::endl;
//     std::cout << std::endl;
    // Step 7: Apply Jacobsthal insertion
    // jacobsthal(sorted_main_chaine);
// }

/////////////mine////////////////
    template <typename T>
    void sort_container(T& container){
        //clear every vector before another container application
        pairs.clear();
        sorted_pairs.clear();
        main_chaine.clear();
        pending_chaine.clear();
        original_pending.clear();
        original_main.clear();
        sorted_main_chaine.clear();

        get_original_pairs(container);

        //separate the pairs into two chaine (maine will be applied recursive for ford-johnson, pending will be left untouched)
        separate_pairs(pairs);

        //retain the orignal pending since pending will be changed later in the ford recursion
        original_pending = pending_chaine;
        original_main = main_chaine;

        ///////////////ford johnson implementation/////////////////////

        

        //apply recursive ford-johnson on the main chaine
        sorted_main_chaine = ford_johnson(original_main);

        ///////////////jacobsthal implementation//////////////////////

        // jacobsthal(sorted_main_chaine); 
    }

};

    

class NotANumberException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: not a number.";
        }
};

class NotAnIntException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: not an integer.";
        }
};

class PositiveNumberException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: no negative number is allowed.";
        }
};

class DuplicateNumberException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: Duplicate number included.";
        }
};

#endif


/////////////////////normal insertion sort ///////////////////////////
 // _pair_count = 1;
            // // Step 2: insertion sort by first element of the pair
            // for(it_paired = paired.begin() + 1; it_paired != paired.end(); ++it_paired){
            //     std::pair<int,int> key = *it_paired;
            //     std::vector<std::pair<int,int> >::iterator iter = it_paired;

            //     while(iter != paired.begin() && (iter-1)->first > key.first){
            //         *iter = *(iter-1);
            //         --iter;
            //     }
            //     *iter = key;
            //     _pair_count++;
            // }
            // std::cout << "Number of pairs: " << _pair_count << std::endl;

            // //putting into main and pending chaine
            // int odd = 0;
            // for(it_paired = paired.begin(); it_paired != paired.end(); ++it_paired){
            //     if(it_paired->second == -1)
            //         odd = it_paired->first;
            //     else{
            //         main_chaine.push_back(it_paired->first);
            //         pending_chaine.push_back(it_paired->second);
            //     }
            // }
            // if(_pair_count % 2 != 0) pending_chaine.push_back(odd);

            // //print the pairs
            // print_container(main_chaine);
            // print_container(pending_chaine);
            // print_pair(paired);  



//ford_johnson_template
        // template <typename T>
        // T ford_johnson(T& container){    
        //     typename T::iterator it;
        //     T main_chaine;

        //     std::vector<std::pair<int, int> > paired;
        //     std::vector<std::pair<int, int> >::iterator it_paired;

        //     // Step 1: make into pairs, larger element first
        //     for(it = container.begin(); it != container.end(); ++it){
        //         if((it + 1) != container.end()){
        //             if(*it < *(it + 1))
        //                 std::swap(*it, *(it + 1));

        //             paired.push_back(std::make_pair(*it, *(it + 1)));
        //             ++it;
        //         }
        //         else{
        //             paired.push_back(std::make_pair(*it, -1));
        //             break;
        //         }
        //     }
        //     print_pair(paired);

            
        //     //pair count
        //     _pair_count = 0;
        //     for(it_paired = paired.begin(); it_paired != paired.end(); ++it_paired)
        //         _pair_count++;
        //     std::cout << "_pair_count << " << _pair_count << std::endl;
        //     //iterate the pair to the larger elements to put update into the main chain
        //     int odd_into_pending = 0;
               
        //     for(it_paired = paired.begin(); it_paired != paired.end(); ++it_paired){
        //         if(it_paired->second == -1)
        //             odd_into_pending = it_paired->first;
        //         else{
        //             main_chaine.push_back(it_paired->first);
        //             pending_chaine.push_back(it_paired->second);
        //         }
        //     }
        //     if(_pair_count % 2 != 0 && _pair_count != 1) pending_chaine.push_back(odd_into_pending);

        //     print_container(main_chaine);
        //     print_container(pending_chaine);
        //     if(main_chaine.size() > 1)
        //        main_chaine = ford_johnson(main_chaine);
        //     return main_chaine;
        // }

        // template <typename T>
        // int get_pos_pair(T& container){
        //     if(container.empty()) return -1;
        //     int target = container[0];  // Get first element
            
        //     // Find position of pair containing this element
        //     for(size_t i = 0; i < pairs.size(); ++i) {
        //         if(pairs[i].first == target) {
        //             return static_cast<int>(i);  // Return index position
        //         }
        //     }
        //     return -1;  // Not found
        // }


        // template <typename T>
        // void get_sorted_pairs(){
        //     typename T::iterator it = container.begin(); 
            
        //     //only one number in the container
        //     //iterate the original pairs and put the matched pairs into sorted_pairs
        //     for(it; it != container.end(); ++it){
                
        //     }
        // }