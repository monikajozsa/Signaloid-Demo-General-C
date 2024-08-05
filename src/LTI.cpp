#include <iostream>
#include <vector>
#include <uxhw.h>

class LTI_System {
public:
    // Constructor to initialize matrices
    LTI_System(const std::vector<std::vector<double>>& A,
               const std::vector<std::vector<double>>& B,
               const std::vector<std::vector<double>>& C,
               const std::vector<std::vector<double>>& D)
        : A(A), B(B), C(C), D(D) {
        // Initialize the state vector x to zero
        x = {0.0, 0.0};
    }

    // Function to update the state based on input
    void update(double u) {
        // Calculate the new state
        std::vector<double> x_new(2, 0.0);
        x_new[0] = A[0][0] * x[0] + A[0][1] * x[1] + B[0][0] * u;
        x_new[1] = A[1][0] * x[0] + A[1][1] * x[1] + B[1][0] * u;
        
        x = x_new;
    }

    // Function to compute the output based on the current state
    double get_output(double u) const {
        // Compute the output
        return C[0][0] * x[0] + C[0][1] * x[1] + D[0][0] * u;
    }

private:
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> B;
    std::vector<std::vector<double>> C;
    std::vector<std::vector<double>> D;
    std::vector<double> x;
};

int main() {
    // Define system matrices
    std::vector<std::vector<double>> A = {{0.9, 0.1}, {0.2, 0.8}};
    std::vector<std::vector<double>> B = {{0.5}, {0.3}};
    std::vector<std::vector<double>> C = {{1.0, 0.0}};
    std::vector<std::vector<double>> D = {{0.0}};

    // Create an instance of LTI_System
    LTI_System system(A, B, C, D);

    // Define input
    float u = UxHwDoubleGaussDist(1.0, 0.1); // Mean 1.0, std dev 0.1

    // Update system and get output
    system.update(u);
    double y = system.get_output(u);

    std::cout << "Output: " << y << std::endl;

    return 0;
}
