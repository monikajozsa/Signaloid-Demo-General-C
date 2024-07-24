#include <iostream>
#include <vector>

// Function to perform forward pass in a single layer model
double forwardPass(const std::vector<double>& inputs, const std::vector<double>& weights) {
    double output = 0.0;
    int input_size = inputs.size();
    for (int j = 0; j < input_size; j++) {
        output += inputs[j] * weights[j];
    }
    return output;
}

int main() {
    // Define weights and inputs
    std::vector<double> weights = {0.5, -0.5, 0.3};
    std::vector<double> inputs = {1.0, 2.0, 3.0};

    // Calculate output
    double output = forwardPass(inputs, weights);

    // Print the output
    std::cout << "Output: " << output << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
