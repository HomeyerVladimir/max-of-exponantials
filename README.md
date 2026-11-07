# max-of-exponantials
Estimating Hₙ = 1 + ½ + … + 1/n in C++ using only random numbers


## The idea
If X₁, …, Xₙ are i.i.d. Exp(1), then E(max((X1,..,Xn))) = Hₙ 


## Results (n = 100)
| N    | estimate | error   |
|------|----------|---------|
| 10⁶  | 5.18783  | 0.0005  |

Coverage of 95% intervals over 2,000 runs: 95.7%.

One run of the estimator for n = 100: the running mean wobbles widely at small N, then settles on the dashed line at H₁₀₀ = 5.18738 inside a 95% band that narrows as N grows from 10 to one million
<img width="656" height="367" alt="image" src="https://github.com/user-attachments/assets/335b963a-fff5-497c-a6d4-dcb17ebc3e3f" />



## Mathematical proof 
[proof.pdf](https://github.com/user-attachments/files/34523256/proof.pdf)


## Full code
[src/main.cpp](src/main.cpp)
