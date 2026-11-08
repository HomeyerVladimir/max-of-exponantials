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
<img width="1267" height="627" alt="image" src="https://github.com/user-attachments/assets/d07f6673-9e9f-485f-8ee6-25fddca10f43" />




## Mathematical proof 
[proof.pdf](https://github.com/user-attachments/files/34523256/proof.pdf)


## Full code
[src/main.cpp](src/main.cpp)
