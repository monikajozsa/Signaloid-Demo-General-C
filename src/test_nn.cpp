#include <iostream>
#include <vector>
#include <uxhw.h>

// Function to perform forward pass in a single layer model
float forwardPass(const std::vector<float>& inputs, const std::vector<float>& weights) {
    float output = 0.0f;
    int input_size = inputs.size();
    for (int j = 0; j < input_size; j++) {
        output += inputs[j] * weights[j];
    }
    return output;
}

int main() {
    // Define weights using UxHwFloatUniformDist
    float w1 = UxHwFloatUniformDist(0.4f, 0.6f);
    float w2 = -UxHwFloatUniformDist(0.4f, 0.6f);
    float w3 = UxHwFloatUniformDist(0.2f, 0.4f);
    
    std::vector<float> weights = {w1, w2, w3};
    std::vector<float> inputs = {1.0f, 2.0f, 3.0f};

    // Calculate output
    float output = forwardPass(inputs, weights);

    // Print the output
    std::cout << "Output: " << output << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
