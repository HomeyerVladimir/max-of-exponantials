#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

//the program aims at estimating the n-th harmonic number without using the ln(n) + Euler-Mascheroni constant process
//we will be using a probabilistic approach with an n-uplet of random variables following parameter 1 exponential
//distributions.

std::random_device rd;
std::mt19937 gen(rd());
//our seed

// define our vector function
std::vector<double>
randomVector(int n) {
    std::exponential_distribution<double> dist(1.0);
    std::vector<double> v(n);
    for (double& x : v) {
        x = dist(gen);
    }
    return v;
}


//main program
int main(){
    int n;
    int N;
    double Sn = 0;
    double Vn = 0;
    double Zn = 0;
    double Mn = 0;
    double SMx = 0;
    double Mx;
    double mX;
    std::cout << "choose n : " << '\n';
// n being the length of the vector and N the amount of repetitions 
    std::cin >> n;
    std::cout << "choose N : " << '\n';
    std::cin >> N;
    
    if(n < 1 || N < 2){
        std::cerr << "n must be >= 1 and N >= 2" << '\n';
        return 1;
    }
    else{
        std::vector<double> v = randomVector(n);
        for (double x : v){
            Sn += x;
        }
        Mn = Sn / n;
    //Mn is our empirical mean for our n-uplet of exponentials (just there for the sake of being there)


        Mx = *std::max_element(v.begin(), v.end());
        mX = *std::min_element(v.begin(), v.end());
    //Since we want to calculate the minimum and the maximum we need to intialize these values beforehand



        for (int i = 0; i < N; i++){
            std::vector<double> v = randomVector(n);
            SMx += *std::max_element(v.begin(), v.end());

    //for each repetition we generate a new outcome for our random vector and add its 
    //highest element to SMx (the sum of the maximums of each iteration)

            if(Mx <= *std::max_element(v.begin(), v.end())){
                Mx = *std::max_element(v.begin(), v.end());

    //basically I want to retain the information of the highest value obtained
    
            }
            if(mX >= *std::min_element(v.begin(), v.end())){
                mX = *std::min_element(v.begin(), v.end());
            }
        }
        double meanMx = SMx / N;

        for(int i = 1; i <= n; i++){
            Vn += 1.0/i;
            Zn += 1.0/std::pow(i, 2);
        }

        double absError = std::abs(meanMx - Vn);
        double StdDev = std::sqrt(Zn);
        double UpperBound = Vn + 1.96*(StdDev/std::sqrt(N));
        double LowerBound = Vn - 1.96*(StdDev/std::sqrt(N));

        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << '\n';
        std::cout << "the empirical mean is : " << BOLD << GREEN << Mn << RESET << '\n';
        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << '\n';
        std::cout << "the maximum is : " << BOLD << GREEN << Mx << RESET << '\n';
        std::cout << "the minimum is : " << BOLD << GREEN << mX << RESET << '\n';
        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << '\n';
        std::cout << BOLD << BLUE << "meanMx = " << meanMx << " is an estimate of the " << n << "-th Harmonic H-" << n << RESET << '\n';
        std::cout << BOLD << BLUE << "The value of H-" << n << " is : " << Vn << RESET << '\n';
        std::cout << "Absolute error = " << absError << '\n';
        std::cout << "the standard deviation is : " << BOLD << GREEN << StdDev << RESET << '\n';
        std::cout << "The confidence interval is "<< BOLD << GREEN << "[" << LowerBound << " ; " << UpperBound << "]" << RESET << '\n';
        if(LowerBound <= meanMx && meanMx <= UpperBound){
            std::cout << "The estimator lands in the confidence interval" << '\n';
        }
        else{
            std::cout << "The estimator doesn't land in the confidence interval" << '\n';
        }
        return 0;

    }
    
}
