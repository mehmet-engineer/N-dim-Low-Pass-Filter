#include <iostream>
#include <cmath>
#include <Eigen/Dense>

/**
 * @author: Mehmet Kahraman
 * @date: 09.02.2024
*/

class low_pass_filter {

    // multi dimensional low pass filter

    private:
        Eigen::VectorXd ones_vector;

    public:

        int filter_size;
        Eigen::VectorXd smoothness_vector;
        Eigen::VectorXd prev_data_vector;
        Eigen::VectorXd filtered_vector;

    // constructor
    low_pass_filter(int filter_size, double smoothness) {
        
        this->filter_size = filter_size;

        smoothness_vector = Eigen::VectorXd::Constant(filter_size, smoothness);
        prev_data_vector = Eigen::VectorXd::Zero(filter_size);
        filtered_vector = Eigen::VectorXd::Zero(filter_size);
        ones_vector = Eigen::VectorXd::Ones(filter_size);

    }

    // member functions
    void set_smoothness(double smooth_value);
    void set_initial_value(double init_value);
    Eigen::VectorXd apply_filter(Eigen::VectorXd &current_vector);

}; // class
