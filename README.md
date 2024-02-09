# N-dim-Low-Pass-Filter
Multi Dimensional Low Pass Filter in C++

**Authors: Mehmet KAHRAMAN / Date: 09.02.2024**

Installation:
---
```
sudo apt update
sudo apt install libeigen3-dev
```

Example Usage:
---
```
int filter_size = 3;
double smoothness = 0.02;
low_pass_filter lp_filter(filter_size, smoothness);

lp_filter.set_smoothness(smoothness);
lp_filter.set_initial_value(0.0);

Eigen::VectorXd data = Eigen::VectorXd::Random(filter_size);

Eigen::VectorXd filtered_data = lp_filter.apply_filter(data);
std::cout << "filtered_data: \n" << filtered_data << "\n";
```