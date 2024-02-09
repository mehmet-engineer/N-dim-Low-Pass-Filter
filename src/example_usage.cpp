#include "low_pass_filter.hpp"
#include <Eigen/Dense>
#include <thread>
#include <chrono>

int main(int argc, char** argv) 
{

    int filter_size = 3;
    double smoothness = 0.02;
    low_pass_filter lp_filter(filter_size, smoothness);

    lp_filter.set_smoothness(smoothness);
    lp_filter.set_initial_value(0.0);

    while(true) 
    {   
        std::cout << "---------------------- \n" << std::endl;

        Eigen::VectorXd data = Eigen::VectorXd::Random(filter_size);
        std::cout << "data: \n" << data << "\n" << std::endl;

        Eigen::VectorXd filtered_data = lp_filter.apply_filter(data);
        std::cout << "filtered_data: \n" << filtered_data << "\n" << std::endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}