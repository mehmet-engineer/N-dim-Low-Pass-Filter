#include <dynamics_tool_pkg/low_pass_filter.hpp>

/**
 * @author: Mehmet Kahraman
 * @date: 09.02.2024
*/


/**
 * @brief set smoothness value for all filter elements, if smoothness is 1.0, filter does not effect.
 * @param smoothness smoothness value from 0.0 to 1.0
 * @return None
*/ 
void low_pass_filter::set_smoothness(double smoothness)
{
    smoothness_vector = Eigen::VectorXd::Constant(filter_size, smoothness);
}

/**
 * @brief set initial value for all filter elements.
 * @param init_value initialization value for first filter result
 * @return None
*/ 
void low_pass_filter::set_initial_value(double init_value) 
{
    prev_data_vector = Eigen::VectorXd::Constant(filter_size, init_value);
}

/**
 * @brief apply filter and update filter with current data, it returns filtered vector.
 * @param current_vector current data vector to be filtered
 * @return filtered vector
*/ 
Eigen::VectorXd low_pass_filter::apply_filter(Eigen::VectorXd &current_vector) 
{

    // assume that smoothness is 0.2
    // get %80 of previous data and get %20 of current data
    for(int i = 0; i < filter_size; i++)
    {
        filtered_vector(i) = prev_data_vector(i)*(ones_vector(i) - smoothness_vector(i)) + current_vector(i)*smoothness_vector(i);
    }
    
    prev_data_vector = filtered_vector;

    return filtered_vector;
}